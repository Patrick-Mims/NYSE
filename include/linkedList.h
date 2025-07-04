#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct NODE
{
    char symbol[5];
    pthread_t thread;
    // struct NODE *next;
    void *next;
};

void *node();
void insert(struct NODE **, void *);
// void insert(void **, void *);

#endif