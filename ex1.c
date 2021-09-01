#include <stdio.h>
#include <stdlib.h>
#define MAX 255

typedef struct {
  int age;
  char name[MAX];
} Data;

typedef struct list_node {
  Data data;
  struct list_node *next;
} node;

node* create_list();
node* destroy_list(node*);
void append(node*, Data);
void show_list(node*);
void read_string(char []);

int main(void) {
  node *head;
  int n;
  Data date;

  printf("\nN: ");
    scanf("%i", &n);

  head = create_list();

  for(int i=0; i<n; i++){
      printf("\nName: ");
      read_string(date.name);
      printf("\nAge: ");
      scanf("%i", &date.age);
      append(head,date);
  }
  show_list(head);
  head = destroy_list(head);

  return 0;
}

node* destroy_list(node *head) {
  node *aux = head;
  while( aux->next != NULL ) {
    aux = aux->next;
    free(head);
    head = aux;
  }
  free(head);
  return NULL;
}

void append(node *head, Data data) {
  node *n;
  n = (node*) malloc(sizeof(node));
  if( n == NULL ) {
    printf("Out of memory...");
    exit(EXIT_FAILURE);
  }
  node *aux = head;
  while( aux->next != NULL )
    aux = aux->next;
  aux->next = n;
  n->next = NULL;
  n->data = data;
}

node* create_list() {
  node *n;
  n = (node*) malloc(sizeof(node));
  if( n == NULL ) {
    printf("Out of memory...");
    exit(EXIT_FAILURE);
  }
  n->next = NULL; // (*n).next
  return n;
}

void show_list(node *head) {
  node *aux = head;
  aux = aux->next;
  while( aux->next != NULL ) {
    printf("%s\t%i\n", aux->data.name, aux->data.age);
    aux = aux->next;
  }
  printf("%s\t%i\n", aux->data.name, aux->data.age);
}

void read_string(char txt[]){
    fflush(stdin);
    fgets(txt, MAX, stdin);
    if (txt[strlen(txt)-1]=='\n')
        txt[strlen(txt)-1]='\0';
}
