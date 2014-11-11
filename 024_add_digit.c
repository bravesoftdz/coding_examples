#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct my_link {
    struct my_link *next;
    int data;
} my_link_t;


static my_link_t *
add_list (my_link_t *p, my_link_t *t, int carry) {
    if (!p && !t && !carry) return NULL;
    

    my_link_t *result = (my_link_t*)malloc(sizeof(my_link_t));
    result -> next = NULL;

    int value = 0;
    
    if (p) {
        value += p->data;
        p = p->next;
    }

    if (t) {
        value += t->data;
        t = t->next;
    }

    value += carry;
    result -> data = value % 10;
    
    my_link_t *temp = add_list(p? p : NULL, t? t : NULL, value >= 10? 1:0);
    my_link_t *temp_m;

    if (temp) {
        temp_m = temp;
        while (temp_m -> next) temp_m = temp_m -> next;
        temp_m -> next = result;
        result = temp;
    }

    return result;
}


int main(int argc, char* argv[]) {
    
    if (!argv[1]) return 1;

    char *s = argv[1];
    char *p = argv[2];

    my_link_t *head = NULL, *curr = NULL;
    my_link_t *p_head = NULL, *p_curr = NULL;
    
    //build the link list
    while (*s) {
        if (*s == '-') {
            s++;
            continue;
        }
        
        if (!curr && !head) {
        curr = (my_link_t*) malloc(sizeof(my_link_t));
        curr->data = atoi(s);
        curr->next = NULL;
        head = curr;
        }
        
        else { 
            curr->next = (my_link_t*)malloc(sizeof(my_link_t));
            curr = curr->next;
            curr->data = atoi(s);
            curr->next = NULL;
        }
        s++; 
    }
    
    while (*p) {
        if (*p == '-') {
            p++;
            continue;
        }
        
        if (!p_curr && !p_head) {
        p_curr = (my_link_t*) malloc(sizeof(my_link_t));
        p_curr->data = atoi(p);
        p_curr->next = NULL;
        p_head = p_curr;
        }
        
        else { 
            p_curr->next = (my_link_t*)malloc(sizeof(my_link_t));
            p_curr = p_curr->next;
            p_curr->data = atoi(p);
            p_curr->next = NULL;
        }
        p++; 
    }
    
    

    my_link_t *add = add_list(head, p_head, 0);
    while (add) {
        printf("%d -> ", add->data);
        add = add->next;
    }

    printf("\n");
    
    //no free 
    return 0;
}
