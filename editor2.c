#include <stdio.h>
#include "editor2.h"

int main() {
    char editing_buffer[EDITING_BUFFER_LENGTH] = "Meme\nMagic\nIs\nReal";
    printf("\n%d",editor_count_lines(editing_buffer,EDITING_BUFFER_LENGTH));
    return 0;
}

int editor_count_lines(char *editing_buffer,int buffer_size){
    int lines = 0;
    for(char* i = (char *) &editing_buffer; i < (char *) (&editing_buffer + buffer_size); i++){
        if(*i =='\n'){
            lines++;
        }
    }
    return lines;
}
