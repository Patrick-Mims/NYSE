#include "nyse.h"

// compare(int, int) gets passed to solve_puzzle(void *(*)(int, int))
int compare(int a, int b)
{
    return (a + b);
}

// pass in a function pointer
// the definition is the return type
// a pointer to the new name that will be associated with 
// params: a and b
// params: c and d are the two integers we're passing in.

// ------------------------------------- solve_puzzle(int (*)(int, int), int, int)
// int (*fn)(int, int) refers to compare(int, int) 
//
void *solve_puzzle(int (*fn)(int a, int b), int c, int d)
{
    printf("solved_puzzle => %d\n", (*fn)(c, d));
}

// patrick
// I guess this returns a new thread?
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
    int list[] = { 33, 55, 66, 77 };
    int *p = &list[0];

    int item = *++p; // move to the next value
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

    // pointer to an object 
    head = &h;

    // add a new thread to the list
    insert(&head, thread(thread_one));
    insert(&head, thread(thread_two));
    insert(&head, thread(thread_three));

    void *(*http)(char *) = &http_curl_request;

    char *portfolio[] = {
        "rzlv",
        "amzn",
        "arm"};

    printf("Just before solve_puzzle\n"); 
    solve_puzzle(compare, 20, 35);

    // start here
    for (i = 0; i < 3; i++)
        create_new_thread(&thread, http(portfolio[i]));

    return 0;
}
