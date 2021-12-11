
/*
 * Wrote this following libcurl video tutorial at
 * https://www.youtube.com/playlist?list=PLpXAyWkDQy40u-xT-Zr6Rab6EdEFOjO2W
 */ 

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define VERBOSITY_LEVEL 1L
long verbosity_level = 0L; 

#define USERAGENTSTR "Mozilla/5.0 (X11; Linux x86_64; rv:94.0) Gecko/20100101 Firefox/94.0"

static size_t writecallback(char *ptr, size_t size, size_t nmemb, void *userdata);
struct memory{
    char *memory;
    size_t size;
};
int main(int argc, char *argv[])
{
    if (argc < 3){
        fprintf(stderr, "ERROR! Usage: ./mycurlapp URL filename (-v)\n");
        return 1;
    }
    if (argc > 3 && !strcmp("-v", argv[3]))
        verbosity_level = 1L;

    CURL *curl;
    CURLcode res;
    struct memory chunk;
    FILE *file;
    curl_global_init(CURL_GLOBAL_ALL);

    chunk.memory = NULL;
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, verbosity_level);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USERAGENTSTR);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() returned %s\n", curl_easy_strerror(res));
        }else{
            printf("We got %d bytes to our callback\n", (int) chunk.size);
            file = fopen(argv[2], "w");
            fprintf(file, "%s", chunk.memory);
            fprintf(stdout, "%s", chunk.memory);
        }
        free(chunk.memory);

        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    return 0;
}
static size_t writecallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize * 2 + 1);
    if (ptr == NULL){
        fprintf(stderr, "Failed to realloc\n");
        return 0; /* error */
    }

    mem->memory = ptr;
    memcpy(&mem->memory[mem->size], contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';
    return realsize; 
}
