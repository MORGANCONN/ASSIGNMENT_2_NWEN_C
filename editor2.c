#include <stdio.h>
#include <string.h>
#include "editor2.h"

int main(){
    char buffer[] = "The good, the bad and the lucky.";
    int positions[20];
    int *pp = positions;

    printf("Buffer contents: %s", buffer);
    int r = editor_search_multiple(buffer, sizeof(buffer), "the", positions, 20);
    printf("\nOutput of editor_search_multiple(): %d\n", r);
    printf("Positions: { ");
    for(int i=0; i<r; i++) { printf("%d ", *pp); pp++; }
    printf("}\nActual number of occurrences in buffer of 'the': 2\n");
    printf("Positions: { 10 22 }\n");
}


int editor_count_lines(char *editing_buffer,int buffer_size){
    int lines = 0;
    for(char* i = editing_buffer; i < editing_buffer + buffer_size; i = i + sizeof(char)){
        if(*i =='\n'){
            lines++;
        }
    }
    return lines;
}

int editor_search_multiple(char *editing_buffer, int buffer_size, const char *searchString, int results[], int resultsSize){
    int number_of_occurances = 0;
    char buffer[buffer_size / sizeof(char)];
    char *bptr;
    int *posptr = results;
    int buffer_lowercase_length_orignal = strlen(editing_buffer);
    bptr = buffer;
    strcpy(buffer,editing_buffer);
    while (strstr(buffer, searchString) != NULL) {
        number_of_occurances++;
        char *Location_address = strstr(buffer, searchString);
        int array_location = (int)(Location_address - bptr);
        int target_length = strlen(searchString);
        int end_of_target_index = array_location + target_length + 1;
        int buffer_lowercase_length = strlen(buffer);
        *posptr = (buffer_lowercase_length_orignal - buffer_lowercase_length) + array_location;
        posptr = posptr + 1;
        for (int i = end_of_target_index; i < (int)(buffer_size / sizeof(char)); i++) {
            buffer[i - end_of_target_index] = buffer[i];
        }
        buffer[buffer_lowercase_length - end_of_target_index]='\0';
    }
    return number_of_occurances;
}
