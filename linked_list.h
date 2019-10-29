struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *n, char name[100], char artist[100]);
struct song_node * order(struct song_node *n, char name[100], char artist[100]);
void print_list(struct song_node *n);
struct song_node * find(struct song_node *n,char name[100], char artist[100]);
char * find_artist(struct song_node *n, char artist[100]);
struct song_node * random_element(struct song_node *n);
struct song_node * remove_node(struct song_node *n, char name[100], char artist[100]);
struct song_node * free_list(struct song_node *n);
