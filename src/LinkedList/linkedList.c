#include "nyse.h"

void *node()
{
    struct NODE *node = NULL;

    if((node = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return node;
}

void insert(struct NODE **linkedList, void *item)
{
    struct NODE *newNode = (struct NODE *)node();

//     strncpy(newNode->symbol, (pthread_t)item, sizeof(newNode->symbol));

    newNode->thread = item;
    newNode->next = *linkedList;
    *linkedList = newNode;

    puts("Thread Inserted");
}

void display_list(struct NODE *linkedList)
{
    struct NODE *l = linkedList;
    //
}

void *find_node(struct NODE *item)
{
    struct NODE *newNode = node(); 



}
