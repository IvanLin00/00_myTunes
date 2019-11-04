#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"


//helper function 1
int listsize(struct song_node *n){
	if(n == NULL) return 0;
	return 1 + listsize(n->next);
}

//helper function 2
struct song_node * find_node(struct song_node *n, int index){
	struct song_node *find = n;
	if(index == 0) return find;
	return find_node(find->next,index - 1);
}

//actual functions
void print_list(struct song_node *n){
  while(n != NULL){
    printf("%s : %s | ", n->artist, n->name );
    n = n->next;
  }
  printf("\n");
}

void print_node(struct song_node *n){
	if (n != NULL) printf("[%s : %s]\n", n->artist, n->name);
}

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]){
  struct song_node *insert = malloc(sizeof(struct song_node));
  strncpy(insert->name, name, 100);
  strncpy(insert->artist, artist, 100);
  insert->next = n;
  return insert;
}

//helper function 3
struct song_node * insert_node(struct song_node *n, char name[100], char artist[100], int index){
	struct song_node *insert = malloc(sizeof(struct song_node));
	strncpy(insert -> name, name, 100);
	strncpy(insert -> artist, artist, 100);
	if(index == 0) return insert_front(n, name, artist);
	struct song_node *temp = find_node(n, index-1)->next;
	find_node(n, index - 1) -> next = insert;
	insert -> next = temp;
	return n;
}

//other functions
struct song_node * order(struct song_node *n, char name[100], char artist[100]){
	 struct song_node *compare;
	 int lsize = listsize(n);
	 int insertat = 0;
	 for(int index = 0; index < lsize; index++){
		 compare = find_node(n,index);
		 if(strcmp(artist,compare->artist)<0){
			 insertat = index;
			 break;
		 }
		 if(strcmp(artist, compare-> artist) ==0 && strcmp(name, compare-> name) < 0){
			 insertat = index;
			 break;
		 }
		 if(compare->next ==NULL){
			 return insert_node(n,name,artist,lsize);
		 }
	 }
	 return insert_node(n,name,artist,insertat);
}


struct song_node * find(struct song_node *n,char name[100], char artist[100]){
  struct song_node *tofind = n;
  while(tofind != NULL){
    if(strcmp(tofind->name,name) == 0 && strcmp(tofind->artist, artist) == 0){
       return tofind;
     }
     tofind = tofind-> next;
   }
}

struct song_node * find_artist(struct song_node *n, char artist[100]){
	struct song_node *tofind = n;
	while(tofind != NULL){
		if(strcmp(tofind->artist, artist) == 0){
		   return tofind;
		 }
		 tofind = tofind-> next;
	}
}

struct song_node * random_element(struct song_node *n, int num_nodes){
	int node_index = rand() % num_nodes;
	struct song_node *random_node = n;
	while (node_index > 0 && random_node != NULL){
		random_node = random_node -> next;
		node_index -= 1;
	}
	return random_node;
}

struct song_node * remove_node(struct song_node *n, char name[100], char artist[100]){
  struct song_node *holder = n;
  struct song_node *prev = NULL;
  struct song_node *findn = find(n,name,artist);
  if(findn == NULL) return n;
  if(findn == n){
    n = n->next;
  }
  else{
    while(holder != NULL){
      if(holder -> next == findn){
        prev = holder;
        break;
      }
      holder = holder -> next;
    }
    prev -> next = findn -> next;
  }
  free(findn);
  return n;
}

struct song_node * free_list(struct song_node *n){
  while(n != NULL){
    struct song_node *freed = n;
    n = n->next;
    free(freed);
	freed = NULL;
  }
  return n;
}
