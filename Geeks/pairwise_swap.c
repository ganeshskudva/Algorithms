#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct _node_
{
    int data;
    struct _node_ *next;
}node;

node* alloc_node(int data)
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
           printf(" %d--> ",temp->data);
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

void pairwise_swap(node **head)
{
    node *temp = *head;
    node *curr = NULL;  
    node *prev = NULL;  
 
    if (!*head ) {
        return;
    }
    
    *head = (*head)->next;
    while (temp && temp->next) {
           curr = temp->next;
           temp->next = temp->next->next;
           curr->next = temp;
           if (prev) {
               prev->next = curr;
           }
           prev = temp;
           temp = temp->next;
    } 
 
}

int main ()
{
    int i = 0;
    node *head = NULL;
    srand(10);

    for (i=0; i<5; i++) {
         if (!head) {
             head = alloc_node(rand()%100);
         }else {
             push(&head, alloc_node(rand()%100));
         }
    }

    disp(head);
    pairwise_swap(&head);  
    disp(head);
}
