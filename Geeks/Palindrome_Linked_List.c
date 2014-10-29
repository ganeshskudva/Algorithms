#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct _node_
{
    char data;
    struct _node_ *next;
}node;

node* alloc_node(char data)
{
    node *temp = NULL;
 
    temp = (node *)malloc(sizeof(node));
    if (!temp) {
        printf("\nMalloc error\n");
        exit(0);
    }

    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(node **head, node *anode)
{
    if (!*head) {
        *head = anode;
        return;
    }
    anode->next = *head;
    *head = anode;
    
}

void disp(node *head)
{
    node *temp = head;
  
    while (temp) {
           printf(" %c--> ",temp->data);
           temp = temp->next;
    }

    if (!temp) {
        printf(" NULL ");
    }
}

void reverse(node *head)
{
    if (!head) {
        return;
    }

    reverse(head->next);
    printf(" %d-->  ",head->data);
}
 
void reverse_llist(node **head)
{
    node *prev = NULL;
    node *temp = *head;

    while ((*head)!= NULL) {
           if ((*head)->data == 8) {
               int j =0;
           }
           *head = (*head)->next;
           temp->next = prev;
           prev = temp;
           temp = *head;
    }
    *head = prev;
}

int main ()
{
    int i = 0;
    node *head = NULL;
    srand(10);

    if (!head) {
        head = alloc_node('M');
    }
        push(&head, alloc_node('a'));
        push(&head, alloc_node('l'));
        push(&head, alloc_node('a'));
        push(&head, alloc_node('y'));
        push(&head, alloc_node('a'));
        push(&head, alloc_node('l'));
        push(&head, alloc_node('a'));
        push(&head, alloc_node('M'));
    
  
    printf("\nBefore\n");  
    disp(head);
//    printf("\nAfter\n");  
//    reverse(head);
    reverse_llist(&head);
    printf("\nAfter reversing\n");  
    disp(head);
    printf("\nAfter\n");  
    reverse(head);
}
