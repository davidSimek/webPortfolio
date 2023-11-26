#include "../lib/httpLibrary/src/httpLibrary.h"

#include "requestHandling.h"
#include "constants.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void displayRequest(HttpRequest* request);

int main(int argc, char *argv[])
{
    char* requestBuffer = (char*)malloc(REQUEST_MAX_LENGTH + 1);
    char* responseBuffer = (char*)malloc(RESPONSE_MAX_LENGTH + 1);

    HttpRequest request;
    createRequest(&request, 100, 1000);
    HttpResponse response;
    createResponse(&response, 100, 1000);
    HttpConfig config;
    createServer(&config, 8080);


    Header* headerMap = (Header*)malloc(sizeof(Header));
    char* body = malloc(BODY_MAX_LENGTH + 1);

    while (true) {
        handleRequest(requestBuffer,
                      &request,
                      responseBuffer,
                      &response,
                      &config,
                      1000,
                      1000,
                      headerMap,
                      body);
    }


    deleteServer(&config);
    deleteRequest(&request);
    deleteResponse(&response);

    free(requestBuffer);
    free(responseBuffer);
    free(body);
    return 0;
}
