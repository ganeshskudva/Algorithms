#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct _node_
{
    int           data;
    struct _node_ *left;
    struct _node_ *right;

}node;

node* alloc_node (int val)
{
    node *temp = NULL;
    
    temp = (node *)malloc(sizeof(node));
    if (!temp) {
        printf("\nMalloc error\n");
        exit(0);
    }
//    printf(" %d ",val);
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
    if (rand()%2) {
        if (root->left == NULL) {
            root->left = add;
            printf(" Left:%d ",add->data);
            return;
        }
        add_node(root->left, add);
    } else { 
        if (root->right == NULL) {
            root->right = add;
            printf(" Right:%d ",add->data);
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

int main()
{
    node *root = NULL;
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
      default: printf("\nInvalid choice\n");
               break;
    } 
    return 0;
 
}
