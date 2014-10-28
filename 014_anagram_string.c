#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

/*
 alg1--
 if (strcpm(sort(s1), sort(s2)) return true;
 return false;
*/

bool 
anagram_string(char* s1, char* s2) {

    if (strlen(s1) != strlen(s2)) return false;
    
    int len = strlen(s1);
    int found_num[256] = {0};
    int i;
    for (i=0; i<len; i++) {
        found_num[s1[i]]++;
    }

    for (i=0; i<len; i++) {
        if (found_num[s2[i]] == 0) return false;
        found_num[s2[i]]--;
    }
    
    return true;
}


int main(int argc, char* argv[]) {
    char* s1 = argv[1];
    char* s2 = argv[2];

    if (anagram_string(s1, s2))
       printf("yes!!!\n");
    else
       printf("no!!!\n");
}
