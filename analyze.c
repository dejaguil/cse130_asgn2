#include "analyze.h"
#include <string.h>
#include <assert.h>

void analyzeURL(char* url,char* host,int* port,char* doc)
{
   char fullCopy[1024];
    strncpy(fullCopy, url, 1023);
    fullCopy[1023] = '\0';

    char* workingPtr = fullCopy;

    if (strncmp(workingPtr, "http://", 7) == 0) {
        workingPtr += 7;
    }

    char leftover[1024];
    strncpy(leftover, workingPtr, 1023);
    leftover[1023] = '\0';

    char* slashPosition = strchr(leftover, '/');
    if (slashPosition != NULL) {
        strcpy(doc, slashPosition);
        *slashPosition = '\0';
    } else {
        strcpy(doc, "/");
    }

    char* colonPointer = strchr(leftover, ':');
    if (colonPointer != NULL) {
        *colonPointer = '\0';
        strcpy(host, leftover);
        char* portString = colonPointer + 1;
        if (*portString != '\0') {
            *port = atoi(portString);
        }
    } else {
        strcpy(host, leftover);
    }
}
