#include "../lib/httpLibrary/src/httpLibrary.h"
#include "requestHandling.h"
#include "constants.h"

#include <string.h>
#include <stdio.h>

void handleRequest(char* requestBuffer,
                   HttpRequest* request,
                   char* responseBuffer,
                   HttpResponse* response,
                   HttpConfig* config,
                   size_t requestMaxLength,
                   size_t responseMaxLength,
                   Header* headerMap,
                   char* body) {
    size_t requestLength = getRequest(config, requestBuffer, requestMaxLength);
        
    parseRequest(requestBuffer, requestLength, request);
    
    route(request, response, headerMap, body);

    size_t responseLength = serializeResponse(response, responseMaxLength, responseBuffer);
    printf("RAW RESPONSE: %s\n----------------------\n", responseBuffer);
    sendResponse(config, responseBuffer, responseLength);

}

void route(HttpRequest* request, HttpResponse* response, Header* headerMap, char* body) {

    if (is(request->path, "/lol")) {
        setHeader(headerMap, 0, "", "");
        if (fromFile("html/lol.html", body)) {
            fillResponse(response, "HTTP/1.1", "200", "OK", headerMap, 1, body);
        } else {
            fillResponse(response, "HTTP/1.1", "404", "Not Found", headerMap, 1, "<h1> not found</h1>");
        }
    } else if (is(request->path, "/lol.css")) {
        setHeader(headerMap, 0, "", "");
        if (fromFile("html/lol.css", body)) {
            fillResponse(response, "HTTP/1.1", "200", "OK", headerMap, 1, body);
        } else {
            fillResponse(response, "HTTP/1.1", "404", "Not Found", headerMap, 1, "<h1> not found</h1>");
        }
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

bool fromFile(char* filePath, char* body) {
    FILE* filePointer = fopen(filePath, "r");
    if (filePointer == 0) {
        return false;
    }

    size_t bytesRead = fread(body, 1, BODY_MAX_LENGTH, filePointer);

    if (bytesRead <= 0) {
        fclose(filePointer);
        return false;
    }
    
    body[bytesRead] = '\0';
    fclose(filePointer);
    return true;
}
