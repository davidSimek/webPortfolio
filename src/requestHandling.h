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
                   Header* headerMap,
                   char* body);

void route(HttpRequest* request, HttpResponse* response, Header* headerMap, char* body);

bool is(char* first, char* second);

bool fromFile(char* filePath, char* body);

#endif
