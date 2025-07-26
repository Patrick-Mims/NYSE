#include "nyse.h"

//----------------------------------------------------------------create_new_thread
void create_new_thread(const pthread_t *thread, const void *(*fn)(void *))
{
    void *result;

    // pthread return 0 on success or a positive value for failure.
    // if this is not successful then it equals a failure.
    if (pthread_create(&thread, NULL, fn, NULL) != 0)
        fprintf(stderr, "Error: pthread_create()");

    pthread_join(thread, &result);
}
