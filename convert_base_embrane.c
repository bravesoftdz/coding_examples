#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int convert(char c) {
    c = tolower(c);
    if (c >= '0' && c<= '9')
        return c - '0';
    if (c >= 'a' && c<= 'z')
        return c - 'a' + 10;

    return -1;
}

char convert_c(int num) {
    if (num <= 9 && num >= 0)
        return num + '0';
    if (num <= 36 && num >= 10)
        return num + 'a' - 10;

    return -1;
}

int ipow(int base, int exp) {
    int result = 1;
    while(exp) {
        result *= base;
        exp--;
    }
    return result;
}

char* to_base_any(const char* orig, const int orig_base, const int tgt_base){
    size_t len = strlen(orig);
    int temp = 0;
    char holder[64];
    holder[63] = '\0';
    int i = 0;
    while (*orig) {
        int p = ipow(orig_base, (len-1 - i));
        temp += convert(*orig)*p;
        orig++;
        i++;
    }

    int div = 0;
    i = 62;
    while (temp != 0) {
        div = temp%tgt_base;
        temp = temp/tgt_base;
        holder[i--] = convert_c(div);
    }; 
    
    return strdup(holder + i + 1);
}

int main(int argc, char* argv[]){

    if (argc <= 3){
        printf("usage: %s\n", argv[0]);
        exit(1);
    }

    char* s=to_base_any(argv[1], atoi(argv[2]), atoi(argv[3]));
    printf("original value: %s \n"
           "original base: %s \n"
           "converted value is: %s \n"
           "converted base: %s \n", argv[1], argv[2], s , argv[3]);

    free(s);
    return 0;
}
