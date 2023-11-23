#include "../lib/httpLibrary/src/httpLibrary.h"
#include "requestHandling.h"

#include <string.h>
#include <stdio.h>

void handleRequest(char* requestBuffer,
                   HttpRequest* request,
                   char* responseBuffer,
                   HttpResponse* response,
                   HttpConfig* config,
                   size_t requestMaxLength,
                   size_t responseMaxLength,
                   Header* headerMap) {
    size_t requestLength = getRequest(config, requestBuffer, requestMaxLength);
        
    parseRequest(requestBuffer, requestLength, request);
    
    route(request, response, headerMap);

    size_t responseLength = serializeResponse(response, responseMaxLength, responseBuffer);
    printf("RAW RESPONSE: %s\n----------------------\n", responseBuffer);
    sendResponse(config, responseBuffer, responseLength);

}

void route(HttpRequest* request, HttpResponse* response, Header* headerMap) {

    if (is(request->path, "/lol")) {
        setHeader(headerMap, 0, "", "");
        fillResponse(response, "HTTP/1.1", "200", "OK", headerMap, 1, "<h1>you are in lol section now now</h1>");
    } else if (is(request->path, "/toJeDobry")) { 
        setHeader(headerMap, 0, "", "");
        fillResponse(response, "HTTP/1.1", "200", "OK", headerMap, 1, "<h1>Jo jo, je to dobrý</h1>");
    } else {
        setHeader(headerMap, 0, "", "");
        fillResponse(response, "HTTP/1.1", "200", "OK", headerMap, 1, "<h1>this is HOME</h1>");
    }
}


bool is(char* first, char* second) {
    return strcmp(first, second) == 0;
}
