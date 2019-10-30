#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(){
  struct song_node *songs = NULL;
  printf("printing empty list\n");
  print_list(songs);

  songs = insert_front(songs, "snow halation", "muse");
  songs = insert_front(songs, "padoru padoru", "umu");
  songs = insert_front(songs, "d/dx(x^2)", "kill me");
  printf("Added songs\n");
  print_list(songs);

  songs = find(songs, "snow halation", "muse");
  printf("Finding snow halation by muse\n");
  print_list(songs);

  songs = free_list(songs);
  printf("print freed list\n");
  print_list(songs);


  return 0;
}
