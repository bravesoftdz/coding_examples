#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct my_link {
    struct my_link *next;
    char data;
} my_link_t;


static my_link_t *
n_to_last (my_link_t *head, int n) {

    if ( !head || n <1 ) return NULL;
    my_link_t *curr = head, *future = head;


    int i;
    for (i = 0; i<n; i++) {
        if (future->next)
            future = future->next;
        else
            return NULL;
    }
         
    while (future->next) {
        future = future->next;
        curr = curr->next;
    }

    return curr;
}


int main(int argc, char* argv[]) {
    
    if (!argv[1]) return 1;

    char *s = argv[1];
    int n = atoi(argv[2]);

    my_link_t *head = NULL, *curr = NULL;
    
    //build the link list
    while (*s) {
        if (*s == '-') {
            s++;
            continue;
        }
        
        if (!curr && !head) {
        curr = (my_link_t*) malloc(sizeof(my_link_t));
        curr->data = *s;
        curr->next = NULL;
        head = curr;
        }
        
        else { 
            curr->next = (my_link_t*)malloc(sizeof(my_link_t));
            curr = curr->next;
            curr->data = *s;
            curr->next = NULL;
        }
        s++; 
    }
    
    my_link_t *cut;  
    cut = n_to_last(head, n);
    while (cut) {
        printf("%c -> ", cut->data);
        cut = cut->next;
    }

    printf("\n");
    
    //no free 
    return 0;
}
