#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}

node *_BttoTree(node *root)
{
	if(!root)
	return NULL;
	
	if(root->left)
	{
		node *left=_BttoTree(root->left);
		while(left->right)
		left=left->right;
		
		left->right=root;
		root->left=left;
	}
	if(root->right)
	{
		node *right=_BttoTree(root->right);
		while(right->left)
		right=right->left;
		
		right->left=root;
		root->right=right;
	}
	
	return root;
}
void printList(node *head)
{
	temp = head;
	cout<<"NULL";
	while(temp)
	{
		cout<<"<-"<<temp->data<<"->";
		temp=temp->right;
	}
	cout<<"NULL";
}
node *BttoTree(node *root)
{
	if(!root)
	return NULL;
	
	node *head=_BttoTree(root);
	while(head->left)
	head=head->left;
	
	return head;
}
int main()
{
	node *root=newNode(10);
	root->left=newNode(12);
	root->right=newNode(15);
	root->left->left=newNode(25);
	root->left->right=newNode(30);
	root->right->left=newNode(36);
	
	node *head = BttoTree(root);
	printList(head);
	
	return 0;
}
