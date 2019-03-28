//
// Created by Connor on 28/03/2019.
//

#ifndef ASSIGNMENT_2_NWEN_C_EDITOR2_H
#define ASSIGNMENT_2_NWEN_C_EDITOR2_H

#define EDITING_BUFFER_LENGTH 21

int editor_count_lines(char *editing_buffer,int buffer_size);

char *editor_search_multiple(char *editing_buffer, int buffer_size, const char *searchString, int results[], int resultsSize);

#endif //ASSIGNMENT_2_NWEN_C_EDITOR2_H
