#include <stdio.h>
#include <stdlib.h>

#include <curl/curl.h>

/* practising using curl in C; 
 * following "https://www.youtube.com/watch?v=daA-KBKfJ_o"
 */
int main()
{
    CURL *curl = curl_easy_init();
    if (!curl){
        fprintf(stderr, "curl init FAILED\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/AmirrezaFiroozi/");
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK){
        fprintf(stderr, "download problem: %s\n", curl_easy_strerror(res));
    }
    
    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}

