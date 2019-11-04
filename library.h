#include "linked_list.h"

void add_song(struct song_node *lib[27], char name[100], char artist[100]);
struct song_node * search_song(struct song_node *lib[27], char name[100], char artist[100]);
struct song_node * search_artist(struct song_node *lib[27], char artist[100]);
void print_letter(struct song_node *lib[27], char letter);
void print_artist(struct song_node *lib[27], char artist[100]);
void print_lib(struct song_node *lib[27]);
void shuffle(struct song_node *lib[27]);
void delete_song(struct song_node *lib[27], char name[100], char artist[100]);
void clear_lib(struct song_node *lib[27]);