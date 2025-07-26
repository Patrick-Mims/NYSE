#include "nyse.h"

static char *get_url(char *ticker)
{
    char *url = NULL;

    if ((url = malloc(50 * sizeof(char))) == NULL)
        exit(EXIT_FAILURE);

    strcpy(url, "https://data.alpaca.markets");
    strcat(url, "/v2");
    strcat(url, "/stocks/");
    strcat(url, ticker);
    strcat(url, "/trades");
    strcat(url, "/latest");

    printf("Much Love: %s\n", url);

    return url;
}

static char *(*URL)(char *) = &get_url;

//*****************************************************write_callback

static size_t write_callback(char *(*dt)(), size_t size, size_t nmemb, void *stream)
{
    struct IO *out = (struct IO *)stream;

    out->stream = fopen(out->json_file, "wc");

    if (!out->stream)
        exit(EXIT_FAILURE);

    puts("write_callback successful!");

    return fwrite(dt, size, nmemb, out->stream);
}

static size_t (*CALLBACK)(char *, size_t, size_t, void *) = write_callback;

void *http_curl_request(char *symbol)
{
    puts("Education");
    printf("symbol-> %s\n", symbol);

    struct IO io = {
        "data.json",
        NULL};

    struct LIBCURL *libcurl = NULL;
    struct curl_slist *headers = NULL;

    libcurl = (struct LIBCURL *)node(); // allocate memory directly.
    libcurl->curl = curl_easy_init();

    curl_easy_setopt(libcurl->curl, CURLOPT_URL, URL(symbol));
    /*
    curl_easy_setopt(libcurl->curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, CALLBACK);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, &io);

    headers = curl_slist_append(headers, "accept: application/json");

    // Add two more lines for the key - get from Alpaca project
    // headers = curl_slist_append(headers, "");
    // headers = curl_slist_append(headers, "");
    curl_easy_setopt(libcurl->curl, CURLOPT_HTTPHEADER, headers);

    if (libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    libcurl->code = curl_easy_perform(libcurl->curl);

    curl_easy_cleanup(libcurl->curl);

    if (CURLE_OK != libcurl->code)
        fprintf(stderr, "curl told us %d\n", libcurl->code);
    */

    curl_global_cleanup();

    pthread_exit(0); // return success and terminate thread
}
