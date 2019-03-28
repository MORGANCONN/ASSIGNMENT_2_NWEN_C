#include <stdio.h>
#include <string.h>
#include "editor2.h"


int editor_count_lines(char *editing_buffer,int buffer_size){
    int lines = 0;
    for(char* i = (char *) &editing_buffer; i < (char *) (&editing_buffer + buffer_size* sizeof(char)); i = i + sizeof(char)){
        if(*i =='\n'){
            lines++;
        }
    }
    return lines;
}

char *editor_search_multiple(char *editing_buffer, int buffer_size, const char *searchString, int results[], int resultsSize){
    // search array of pointers for first instance of string
    char *firstIndex = strstr(editing_buffer,searchString);
    // add to array
    results[0] = (int)&firstIndex;
    int word_length = strlen(searchString) - (&firstIndex-&editing_buffer);

    // make new array of pointers after end of last instance of string
    // add to array and continue until no further instances of string
    // return pointer to start of results array

}
