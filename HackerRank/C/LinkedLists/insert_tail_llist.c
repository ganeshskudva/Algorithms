#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  struct Node *temp =  NULL;
  struct Node *curr =  NULL;
    
  if (!head) {
      temp = (struct Node *)malloc(sizeof(struct Node));
      if (!temp) {
          return NULL;
      } else {
          temp->data = data;
          temp->next = NULL;
      }
      return temp;
  }
    
  curr = head;
  while (curr->next) {
         curr = curr->next;
  }
  
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (!temp) {
      return NULL;
  } else {
      temp->data = data;
      temp->next = NULL;
  }
  
  curr->next = temp;
    
  return head;
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
