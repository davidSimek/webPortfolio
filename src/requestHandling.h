#ifndef REQUEST_HANDLING
#define REQUEST_HANDLING

#include "../lib/httpLibrary/src/httpLibrary.h"

#include <stdbool.h>

void handleRequest(char* requestBuffer,
                   HttpRequest* request,
                   char* responseBuffer,
                   HttpResponse* response,
                   HttpConfig* config,
                   size_t requestMaxLength,
                   size_t responseMaxLength,
                   Header* headerMap);

void route(HttpRequest* request, HttpResponse* response, Header* headerMap);

bool is(char* first, char* second);

#endif
