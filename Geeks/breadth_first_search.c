#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct _node_
{
    int           data;
    struct _node_ *left;
    struct _node_ *right;

}node;

typedef struct _queue_
{
    node           *q_node;
    struct _queue_ *next;
}queue;

node* alloc_node (int val)
{
    node *temp = NULL;
    
    temp = (node *)malloc(sizeof(node));
    if (!temp) {
        printf("\nMalloc error\n");
        exit(0);
    }
    printf(" %d ",val);
    temp->data  = val;
    temp->left  = NULL;
    temp->right = NULL;
   
    return temp;
}

void add_node (node *root, node *add) 
{
    if (!root) {
        printf("\nRoot NULL\n");
        return;
    }
    if (add->data < root->data) {
        if (root->left == NULL) {
            root->left = add;
            return;
        }
        add_node(root->left, add);
    } else if (add->data > root->data) { 
        if (root->right == NULL) {
            root->right = add;
            return;
        }
        add_node(root->right, add);
    }
}


void inorder (node *root) 
{
    if (!root) {
        return;
    }
   
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);

}

void preorder (node *root) 
{
    if (!root) {
        return;
    }

    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);

}

void postorder (node *root) 
{
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);

}

queue *alloc_q_node(node *qu_node)
{
    queue *temp = NULL;
    
    temp = (queue *)malloc(sizeof(queue));
    if (!temp) {
        printf("\nMalloc failure\n");
        exit(0);
    }
    
    temp->q_node = qu_node;
    temp->next = NULL;
    return temp;
}

int queue_size(queue *q_head)
{
    int cnt = 0;
    int i   = 0;

    if (!q_head) {
        return cnt;
    }

    while (q_head) {
           q_head = q_head->next;
           cnt++;
    }
    return (cnt - 1);
}

void enqueue(queue *q_head, node *anode) 
{
    queue *temp = NULL;

    if (!q_head) {
        printf("empty q");
        return;
    }
    
    temp = alloc_q_node(anode);
    while (q_head->next != NULL) {
           q_head = q_head->next;
    }
    q_head->next = temp;
}

node *dequeue(queue *q_head)
{
    queue *temp = NULL;
    node *node_t = NULL;

    if (!q_head) {
        return NULL;
    }
    
    temp = q_head->next; 
    node_t = temp->q_node;
    q_head->next = temp->next;
    free(temp);
    return node_t;   
}

int levelorder(node *root) 
{
    int size = 0;
    int hgt = 0;
    int left = 1;
    queue *q_lhead = NULL;
    queue *q_rhead = NULL;
    queue *q_head = NULL;
    node *temp = NULL;

    if (!root) {
        return;
    }

    q_lhead = alloc_q_node(NULL);
    q_rhead = alloc_q_node(NULL);
    enqueue(q_lhead, root);
    while (queue_size(q_lhead) || queue_size(q_rhead)) {
           while (queue_size(q_lhead)) { 
                  temp = dequeue(q_lhead);
                  q_head = q_rhead;
                  if (temp) {
                      printf(" %d ",temp->data);
                      if (temp->left && temp->right) {
                          enqueue(q_head, temp->right);
                          enqueue(q_head, temp->left);
                  } else if (!temp->left && temp->right) {
                          enqueue(q_head, temp->right);
                  } else if (temp->left && !temp->right) {
                          enqueue(q_head, temp->left);
                  }
                  }
           }

           while (queue_size(q_rhead)) { 
                  temp = dequeue(q_rhead);
                  q_head = q_lhead;
                  if (temp) {
                      printf(" %d ",temp->data);
                      if (temp->left && temp->right) {
                          enqueue(q_head, temp->left);
                          enqueue(q_head, temp->right);
                  } else if (temp->left && !temp->right) {
                          enqueue(q_head, temp->left);
                  } else if (!temp->left && temp->right) {
                          enqueue(q_head, temp->right);
                  }
                  }
           }
           
    }
    return hgt;    
}

void lorder(queue *q_head)
{
    node *temp = NULL;

    if (!queue_size(q_head)) {
        return;
    }

    temp = dequeue(q_head);
    if (temp) {
         printf(" %d ",temp->data);
         if (temp->left && temp->right) {
              enqueue(q_head, temp->left);
              enqueue(q_head, temp->right);
          } else if (temp->left && !temp->right) {
               enqueue(q_head, temp->left);
          } else if (!temp->left && temp->right) {
               enqueue(q_head, temp->right);
          }
    }
    lorder(q_head);
}    
        

int main()
{
    node *root = NULL;
    queue *q_head = NULL;
    int i = 0;
    int choice = 0;
    srand(100);

    for (i=0; i<10; i++) {
         if (!root) {
             root = alloc_node(rand()%100);
             printf("\nRoot elem:%d\n",root->data); 
         } else {
             add_node(root, alloc_node((rand()%100)));
         }
    }

    scanf("%d",&choice);
    switch (choice) {
      case 0: printf("\nInorder\n");
	      inorder(root);
              break;
      case 1: printf("\nPre-order\n");
              preorder(root);
              break;
      case 2: printf("\nPost-order\n");
              postorder(root);
              break;
      case 3: printf("\nLevel-order\n");
              printf("\nHgt:%d\n",levelorder(root));
              break;
      case 4: printf("\nLevel-order\n");
              q_head = alloc_q_node(NULL);
              enqueue(q_head, root);
              lorder(q_head);
              break;
      default: printf("\nInvalid choice\n");
               break;
    } 
    return 0;
 
}
