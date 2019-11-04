#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "library.h"
#include "linked_list.h"

int letter_index(char letter){
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	for(int index = 0; index < 26; index ++){
		if (letter - alphabet[index] == 0){
			return index;
		}
	}
	return 26;
}

void add_song(struct song_node *lib[27], char name[100], char artist[100]){
	int index = letter_index(artist[0]);
	lib[index] = order(lib[index], name, artist);
}

struct song_node * search_song(struct song_node *lib[27], char name[100], char artist[100]){
	int index = letter_index(artist[0]);
	return find(lib[index],name,artist);
}

struct song_node * search_artist(struct song_node *lib[27], char artist[100]){
	int index = letter_index(artist[0]);
	return find_artist(lib[index],artist);
}

void print_letter(struct song_node *lib[27], char letter){
	int index = letter_index(letter);
	print_list(lib[index]);
}

void print_artist(struct song_node *lib[27], char artist[100]){
	int index = letter_index(artist[0]);
	print_list(find_artist(lib[index], artist));
}

void print_lib(struct song_node *lib[27]){
	for(int i = 0; i < 26; i++){
		print_list(lib[i]);
	}
}

void shuffle(struct song_node *lib[27]){
	int randint = rand()%26;
	while(lib[randint] == NULL) randint = (randint + 1) % 26;
	print_node(random_element(lib[randint]));
}

void delete_song(struct song_node *lib[27], char name[100], char artist[100]){
	int index = letter_index(artist[0]);
	lib[index] = remove_node(lib[index],name,artist);
}

void clear_lib(struct song_node *lib[27]){
	for (int i = 0; i<27; i++){
		lib[i] = free_list(lib[i]);
		lib[i] = NULL;
	}
}
