#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char*
replace_space(char* s) {

    if (!s) return NULL;

    int len = strlen(s);
    int num_space = 0;
    int i;
    int new_len = 0;
    char* new_s;

    for (i=0; i<len; i++) {
        if (s[i] == ' ') num_space++;
    }

    new_len = len + num_space*2;

    new_s = (char*) malloc(new_len + 1);

    new_s[new_len] = '\0';

    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            new_s[new_len - 1] = '0';
            new_s[new_len - 2] = '2';
            new_s[new_len - 3] = '%';
            new_len = new_len - 3;
        }
        else {
            new_s[new_len - 1] = s[i];
            new_len--;
        }
    }

    return new_s;
}


int main(int argc, char* argv[]) {

    char* s = argv[1];
    printf("before transform: %s\n", s);
    char* new_s = replace_space(s);
    printf("after transform: %s\n", new_s);

    free(new_s);
}
