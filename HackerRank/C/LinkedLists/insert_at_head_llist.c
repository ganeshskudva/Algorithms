#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
	int data;
	Node *next;
};
/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node *alloc_node(int data)
{
    struct Node *temp = NULL;
    
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        return NULL;
    } else {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

Node* Insert(Node *head,int data)
{
  struct Node *temp = NULL;
   
  temp = alloc_node(data);  
  if (!temp) {
          return head;
  }
    
  if (!head) {
        
      return temp;
  }
    
  temp->next = head;
  return temp;
}


void Print(Node *head)
{
	Node *temp = head;
	while(temp!= NULL){ cout<<temp->data<<"\n";temp = temp->next;}
}
int main()
{
	int t;
	cin>>t;
	Node *head = NULL;
	while(t-- >0)
	{
		int x; cin>>x;
		head = Insert(head,x);
	}
	Print(head);
}
