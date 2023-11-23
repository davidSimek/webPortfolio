#ifndef REQUEST_HANDLING
#define REQUEST_HANDLING

#include "../lib/httpLibrary/src/httpLibrary.h"

void handleRequest(char* requestBuffer,
                   HttpRequest* request,
                   char* responseBuffer,
                   HttpResponse* response,
                   HttpConfig* config,
                   size_t requestMaxLength,
                   size_t responseMaxLength,
                   Header* headerMap);

void route(HttpRequest* request, HttpResponse* response, Header* headerMap);

#endif
