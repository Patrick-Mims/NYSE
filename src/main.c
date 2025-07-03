#include "nyse.h"

pthread_t create_thread(pthread_t thread)
{
    return thread; 
} 

int main()
{
    int i;

    pthread_t thread_one, thread_two, thread_three;

    pthread_t (*thread)() = &create_thread;

    struct NODE *head = NULL;

    insert(&head, thread(thread_one));
//    insert(&head, thread(thread_two));
//    insert(&head, thread(thread_three));

    void *(*http)(char *) = &http_curl_request;

    char *portfolio[] = {
        "aapl",
        "amzn",
        "arm"};

    for (i = 0; i < 3; i++)
    {
        create_new_thread(&thread, http(portfolio[i]));
    }

    return 0;
}