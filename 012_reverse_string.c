#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE !TRUE

int reverse_string(char* s) {
    //no error detection is implemented in this test
    char c;
    int len = strlen(s);
    int i;
    for (i = 0; i <= (len/2 - 1); i++) {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
    return 0;
}

void reverse_string_pointer(char* s) {
    char* end = s;
    char temp;

    if (s)
        while(*end)
            end++;
    end = end - 1;
    while (s < end) {
        temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}

int main(int argc, char* argv[]) {
    char* s = argv[1];
    printf("before reverse: %s \n" , s);
    reverse_string_pointer(s);
    printf("after reverse: %s \n" , s);
}


