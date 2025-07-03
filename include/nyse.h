#ifndef NYSE_H 
#define NYSE_H

#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct IO
{
    const char *json_file; // Immutable: Defined as const
    FILE *stream;
};

/*
struct IO io = {
    "data.json",
    NULL};
    */

struct LIBCURL
{
    CURL *curl;
    CURLcode code;
};

struct NODE
{
    char symbol[5];
    pthread_t thread;
    // struct NODE *next;
    void *next;
};


void create_new_thread(const pthread_t *, const void *(*fn)(void *));
void *http_curl_request(char *);

#endif
