#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include <time.h>

int main(){
  srand(time(NULL));

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

  // songs = order(songs, "EEEEEEEEEEE", "markiplier");
  // printf("markiplier in order\n");
  // print_list(songs);

  find_test = find(songs, "padoru padoru", "umu");
  printf("umu\n");
  print_node(find_test);

  find_test = find_artist(songs, "kill me");
  printf("kill me\n");
  print_list(find_test);

  find_test = random_element(songs, 4);
  printf("random song\n");
  print_node(find_test);

  songs = remove_node(songs, "d/dx(x^2)", "kill me");
  printf("removed d/dx x^2\n");
  print_list(songs);

  songs = free_list(songs);
  printf("print freed list\n");
  print_list(songs);


  return 0;
}
