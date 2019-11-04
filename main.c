#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <time.h>
#include "library.h"
#include "linked_list.h"

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

int main(){
	 srand(time(NULL));
	 struct song_node *songs = NULL;
	 printf("LINKED LIST TESTS\n");
	 printf("====================================\n\n");
	 printf("Testing print_list\n");
	 songs = insert_front(songs, "street spirit (fade out)", "radiohead");
	 songs = insert_front(songs, "paranoid android", "radiohead");
	 songs = insert_front(songs, "time", "pink floyd");
	 songs = insert_front(songs, "yellow ledbetter", "pearl jam");
	 songs = insert_front(songs, "even flow", "pearl jam");
	 songs = insert_front(songs, "alive", "pearl jam");
	 songs = insert_front(songs, "thunderstruck", "ac/dc");
	 print_list(songs);
	 
	 printf("====================================\n\n");
	 printf("Testing print_node\n");
	 print_node(songs);
	 
	 printf("====================================\n\n");
	 printf("Testing find_node\n");
	 printf("looking for [pearl jam: even flow]\n");
	 printf(" node found! ");
	 print_node(find(songs, "even flow", "pearl jam"));
	 printf("looking for [pearl jam: daughter]\n");
	 printf(" node not found\n");
	 print_node(find(songs, "daughter", "pearl jam"));
	 
	 printf("====================================\n\n");
	 printf("Testing find_artist\n");
	 printf("looking for [pink floyd]\n");
	 printf(" artist found! ");
	 print_list(find_artist(songs, "pink floyd"));
	 printf("looking for [pearl jam]\n");
	 printf(" artist found! ");
	 print_list(find_artist(songs, "pearl jam"));
	 
	 printf("====================================\n\n");
	 printf("Testing random\n");
	 print_node(random_element(songs));
	 print_node(random_element(songs));
	 print_node(random_element(songs));
	 print_node(random_element(songs));
	 
	 printf("====================================\n\n");
	 printf("Testing remove\n");
	 printf("Removing [pearl jam: alive]\n");
	 songs = remove_node(songs, "alive", "pearl jam");
	 print_list(songs);
	 printf("Removing [pearl jam: yellow ledbetter]\n");
	 songs = remove_node(songs, "yellow ledbetter", "pearl jam");
	 print_list(songs);
	 printf("Removing [pink floyd: alive]\n");
	 printf(" pink floyd - alive not found\n");
	 songs = remove_node(songs, "alive", "pink floyd");
	 print_list(songs);
	 
	 printf("====================================\n\n");
	 printf("Testing free_list\n");
	 songs = free_list(songs);
	 printf("list after free_list:\n");
	 print_list(songs);
	 printf("====================================\n\n");
	 
	 printf("MUSIC LIBRARY TESTS\n\n");
	 printf("====================================\n\n");
	 
	 printf("Testing print_library\n");
	 struct song_node *library[27];
	 for(int i = 0; i<27; i++){
		 library[i] = NULL;
	 }
	 add_song(library,"thunderstruck","ac/dc");
	 add_song(library,"even flow","pearl jam");
	 add_song(library,"alive","pearl jam");
	 add_song(library,"yellow ledbetter","pearl jam");
	 add_song(library,"time","pink floyd");
	 add_song(library,"peaches","presidents of the united states of america");
	 add_song(library,"street spirit (fade out)","radiohead");
	 add_song(library,"paranoid android","radiohead");
	 print_lib(library);
	 
	 printf("====================================\n\n");
	 printf("Testing print_letter\n");
	 printf("p list\n");
	 print_letter(library, 'p');
	 
	 printf("====================================\n\n");
	 printf("Testing find\n");
	 printf("looking for [pearl jam: alive]\n");
	 printf(" song found!");
	 print_node(search_song(library,"alive","pearl jam"));
	 printf("looking for [pearl jam: time]\n");
	 printf(" song not found");
	 print_node(search_song(library,"time","pearl jam"));
	 
	 printf("\n====================================\n\n");
	 printf("Testing find_artist\n");
	 printf("looking for [pearl jam]\n");
	 printf(" artist found! ");
	 print_list(search_artist(library,"pearl jam"));
	 printf("looking for [pink floyd]\n");
	 printf(" artist found! ");
	 print_list(search_artist(library,"pink floyd"));
	 printf("looking for [bob dylan]\n");
	 printf(" artist not found ");
	 print_list(search_artist(library,"bob dylan"));
	 
	 printf("\n====================================\n\n");
	 printf("Testing print_artist\n");
	 printf("Print [pearl jam]\n");
	 print_artist(library, "pearl jam");
	 printf("Print [ac/dc]\n");
	 print_artist(library, "ac/dc");
	 
	 printf("====================================\n\n");
	 printf("Testing shuffle\n");
	 shuffle(library);
	 shuffle(library);
	 shuffle(library);
	 
	 printf("====================================\n\n");
	 printf("Testing delete_song\n");
	 printf("removing: [pearl jam: alive]\n");
	 delete_song(library,"alive","pearl jam");
	 print_lib(library);
	 printf("removing: [pearl jam: ledbetter]\n");
	 delete_song(library,"yellow ledbetter","pearl jam");
	 print_lib(library);
	 
	 printf("====================================\n\n");
	 printf("Testing clear_library\n");
	 clear_lib(library);
	 printf("Library after clear:");
	 print_lib(library);
	 return 0;
}