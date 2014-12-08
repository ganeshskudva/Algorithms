#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define STACK 0 
#define QUEUE 1

typedef struct _node_
{
    int data;
    struct _node_ *next;
}node;

node *alloc_node(int val)
{
    node *temp = NULL;

    temp = (node *)malloc(sizeof(node));
    if (!temp ) {
        printf("\nMalloc error\n");
        exit(0);
    }

    temp->data = val;
    temp->next = NULL;
    return temp;
}

void add_node(node **head, node *anode, int stack)
{
   int i = 0;
   node *temp = NULL;
 
   if (!*head) {
        *head = anode;
        return;
    }

    temp = *head;
    if (stack) {
        while (temp->next != NULL) {
               temp = temp->next;
        }

        temp->next = anode;
        return;
    }

    if (!temp->next)  {
        temp->next = anode;
        anode->next = NULL;
        return;
    } 
    anode->next = temp->next;
    temp->next = anode;    
 
}

void disp(node *head)
{
    if (!head) {
        return;
    }

    while (head) {
           printf("%d--> ",head->data);
           head = head->next;
    }
   
    printf(" -->NULL ");
}

void alternate_reverse(node *head)
{
    node *alt_head = NULL;
    node *temp = head;   
    node *prev = NULL;
    node *anode = NULL;
    int  odd   = 1;
 
    alt_head = alloc_node(0xffff);
    
    while (temp) {
           if (!odd) {
               anode = temp;
               temp = temp->next;
               add_node(&alt_head, anode, STACK);
               odd = 1;
               prev->next = temp;
               continue;
           }
           prev = temp;
           temp = temp->next;
           odd = 0;
    }
   prev ->next = alt_head->next;
}

int main()
{
    node *head = NULL;
    int  i     = 0;
    srand(time(NULL));
 
    for (i=0; i<10; i++) {
         if (!head) {
             head = alloc_node(i+1);
         } else {
             add_node(&head, alloc_node(i+1), QUEUE);
         }
    }
  
    printf("\nBefore\n");
    disp(head);
    alternate_reverse(head);
    printf("\nAfter\n");
    disp(head);
    return 0;
}
