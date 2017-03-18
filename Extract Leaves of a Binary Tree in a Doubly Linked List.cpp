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

node *extractLeafList(node *root,node *&head)
{
	if(!root)
	return NULL;
	
	if(!root->left && !root->right)
	{
		root->right=head;
		
		if(head!=NULL)
		head->left=root;
		
		head=root;
		return NULL;
	}
	root->right = extractLeafList(root->right,head);
	root->left = extractLeafList(root->left,head);
}

void printList(node *head)
{
	temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}
void print(node *root)
{
	if(!root)
	return;
	
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}
int main()
{
    node *head = NULL;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    printf("Inorder Trvaersal of given Tree is:\n");
    print(root);
 
    root = extractLeafList(root, head);
 
    printf("\nExtracted Double Linked list is:\n");
    printList(head);
 
    printf("\nInorder traversal of modified tree is:\n");
    print(root);
    return 0;
}
