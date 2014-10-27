#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE !TRUE

void compress_dup_string_bug(char* s) {
    if (!s) return;
    int len = strlen(s);
    int i, j;
    int tail = 0;
    for (i = 0; i < len; i++) {
        //FIXME: this is a good buggy code
        //the problem is for loop here will be excuted one more time, try aaaab
        for (j = 0; j <= tail; j++) {
            printf("j: %d\n", j);
            printf("tail: %d\n", tail);
            if (s[i] == s[j])
                break;
        }

        printf("j out: %d\n", j);
        if (j == tail) {
            s[tail++] = s[i];
            printf("here\n");
        }
    }

    s[tail] = '\0';
}


void compress_dup_string(char* s) {
    if (!s) return;
    int len = strlen(s);
    int i, j;
    int tail = 1;
    for (i = 0; i < len; i++) {
        for (j = 0; j < tail; j++) {
            if (s[i] == s[j])
                break;
        }

        if (j == tail) {
            s[tail++] = s[i];
        }
    }

    s[tail] = '\0';
}

void compress_dup_string_bool(char* s) {
    if (!s) return;
    int len = strlen(s);
    bool found[256];
    int i;
    for (i=0; i<256; i++)
        found[i] = FALSE;

    int tail = 0;
    for (i=0; i<len; i++) {
        if (!found[s[i]]) {
            s[tail++] = s[i];
            found[s[i]] = TRUE;
        }
    }

    s[tail] = '\0';
}

int main(int argc, char* argv[]) {
    char* s = argv[1];
    printf("before compress: %s \n" , s);
    compress_dup_string_bool(s);
    printf("after compress: %s \n" , s);
}


