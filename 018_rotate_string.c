#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool
rotate_str(const char* s1, const char* s2) {

    if (strlen(s1) != strlen(s2)) return false;

    char* con = (char*) malloc(strlen(s1)*2 +1);
    strcat(con, s1);
    strcat(con, s1);
    
    printf("con: %s\n", con);
    printf("s2: %s\n", s2);
    if (strstr(con, s2)) return true;
    else return false;
}


int main(int argc, char* argv[]) {

    char* s1 = argv[1];
    char* s2 = argv[2];
    
    if (rotate_str(s1, s2))
    printf("rotate substring!\n");

}
