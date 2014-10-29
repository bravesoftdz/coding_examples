#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct my_link {
    struct my_link *next;
    char data;
} my_link_t;


static my_link_t *
remove_dup(my_link_t *head) {

    if (!head) return NULL;
    
    my_link_t *prev = head, *curr = head->next, *temp=head;
    
    while (curr) {
        while (temp != curr) {
            if (temp->data == curr->data) {
                prev->next = curr->next;
                my_link_t *temp = curr;
                curr = curr->next;
                free(temp);
                break;
            }
            else {
                temp = temp->next;
            }
        }

        if (temp == curr) {
            prev = curr;
            curr = curr->next;
        }    

        temp = head;
    }

    return head;
}


int main(int argc, char* argv[]) {
    
    if (!argv[1]) return 1;

    char *s = argv[1];
    my_link_t *head = NULL, *temp, *curr;
    
    while (*s) {
        if (*s == '-') {
            s++;
            continue;
        }
        temp = (my_link_t*) malloc(sizeof(my_link_t));
        temp->next = NULL;
        temp->data = *s;
        
        if (!head) {
            head = temp;
            curr = head;
        }
        else { 
            curr->next = temp;
            curr = temp;
        }
        s++; 
    }
    
    
    remove_dup(head);
    curr = head;
    while (curr) {
        printf("%c -> ", curr->data);
        curr = curr->next;
        free(head);
        head = curr;
    }

    printf("\n");
    
    return 0;
}
