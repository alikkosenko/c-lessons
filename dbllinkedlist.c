#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEfAULTSIZE 20

typedef struct node
{
   int data;
   struct node *next;
   struct node *prev; 
} Node;

typedef struct dbllinkedlist
{
    Node *head;
    Node *tail;
}Dbllinkedlist;


Node *nalloc();
void append(Dbllinkedlist *list, int data);
void delete(Dbllinkedlist *list);
void printlist(Dbllinkedlist *list);

int
main(int argc, char **argv){

    long size;
    char *endptr;
    if(argc > 1){
        size = strtol(argv[1], &endptr, 10);
    }
    else size = DEfAULTSIZE;
     
    Dbllinkedlist *list;
    list->head = NULL;
    list->tail = NULL;

    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);

    printlist(list);
    delete(list);

    printlist(list);


    return 0;
}


Node * nalloc(){
    return (Node *)malloc(sizeof(Node));
}

void append(Dbllinkedlist *list, int data){
    Node *new_node = nalloc();
    if(!new_node){
        printf("Error in allocating new node!!!\n");
        return;
    } 
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail)
    {
        list->tail->next = new_node;
    }
    else
    {
        list->head = new_node;
    }
    
    
    list->tail = new_node;
}

void delete(Dbllinkedlist *list){
    Node *temp;
    temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
}

void printlist(Dbllinkedlist *list){
    Node *cur;
    for (cur = list->head; cur != NULL; cur = cur->next)
    {
        printf("%d\n", cur->data);
    }
    
}