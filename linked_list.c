#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

void print_list(struct song_node *n){
  printf("[ ");
  while(n != NULL){
    printf("%s : %s, ", n->artist, n->name );
    n = n->next;
  }
  printf("]\n");
}

// void print_node(struct song_node *n){
//   struct song_node *toprint = n;
//   toprint->next = NULL;
//   print_list(toprint);
// }

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]){
  struct song_node *insert = malloc(sizeof(struct song_node));
  strncpy(insert->name, name, 100);
  strncpy(insert->artist, artist, 100);
  insert->next = n;
  return insert;
}

//wip
struct song_node * find(struct song_node *n,char name[100], char artist[100]){
  struct song_node *tofind = n;
  while(tofind != NULL){
    if(strcmp(tofind->name,name) == 0 && strcmp(tofind->artist, artist) == 0){
       return tofind;
     }
     tofind = tofind-> next;
   }
}

struct song_node * remove_node(struct song_node *n, char name[100], char artist[100]){\
  struct song_node *findn = find(n,name,artist);
  if(findn = n){
    n = n->next;
    free(findn);
  }
  return n;
}

struct song_node * free_list(struct song_node *n){
  while(n != NULL){
    struct song_node *freed = n;
    n = n->next;
    free(freed);
  }
  return n;
}
