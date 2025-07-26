#include "nyse.h"

// patrick
pthread_t create_thread(pthread_t thread)
{
    return thread;
}

void increment(int *array)
{
    (*array)++;
}

int main()
{
    /* * * */

    int i, upperBound = 3, lowerBound = 0;

    int *ptr = (int[]){33, 55, 66, 77};

    // this is the same as above.
    int list[] = {33, 55, 66, 77};
    int *p = &list[0];

    int item = *++p;              // move to the next value
    printf("item -> %d\n", item); // 55

    int itemm = ++*p; // move and increment the next value
    printf("itemm -> %d\n", itemm);

    increment(&itemm);                               // 56
    printf("The new value of item is: %d\n", itemm); // 57

    for (int j = 0; j < (upperBound - lowerBound) + 1; j++)
        printf("-> %d\n", list[j]);

    /* * * */

    pthread_t thread_one, thread_two, thread_three;
    pthread_t (*thread)() = &create_thread; // function pointer

    struct NODE h;
    struct NODE *head = NULL;

    head = &h;

    insert(&head, thread(thread_one));
    insert(&head, thread(thread_two));
    insert(&head, thread(thread_three));

    void *(*http)(char *) = &http_curl_request;

    char *portfolio[] = {
        "rzlv",
        "amzn",
        "arm"};

    for (i = 0; i < 3; i++)
        create_new_thread(&thread, http(portfolio[i]));

    return 0;
}
