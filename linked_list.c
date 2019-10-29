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
  if(n->name == name && n->artist == artist)
    return n;
  while(tofind->name != name && tofind->artist != artist)    
    tofind = tofind->next;
  return tofind;
}
