#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(){
  struct song_node *songs = NULL;
  print_list(songs);

  songs = insert_front(songs, "snow halation", "muse");
  songs = insert_front(songs, "padoru padoru", "umu");
  songs = insert_front(songs, "d/dx(x^2)", "kill me");
  print_list(songs);

  find(songs, "d/dx(x^2)", "kill me");
  return 0;
}
