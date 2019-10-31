#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(){
  struct song_node *songs = NULL;
  struct song_node *find_test = NULL;
  printf("printing empty list\n");
  print_list(songs);

  songs = insert_front(songs, "snow halation", "muse");
  songs = insert_front(songs, "padoru padoru", "umu");
  songs = insert_front(songs, "d/dx(x^2)", "kill me");
  songs = insert_front(songs, "d/dx(2x)", "kill me");
  printf("Added songs\n");
  print_list(songs);

  songs = remove_node(songs, "d/dx(2x)", "kill me");
  printf("removed d/dx 2x\n");
  print_list(songs);

  find_test = find(songs, "padoru padoru", "umu");
  printf("Finding snow halation by muse\n");
  print_list(find_test);
  print_list(songs);

  songs = free_list(songs);
  printf("print freed list\n");
  print_list(songs);


  return 0;
}
