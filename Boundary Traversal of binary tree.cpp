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

void printleftBoundary(node *root)
{
	if(!root)
	return;
	
	if(root->left)
	{
		cout<<root->data<<" ";
		printleftBoundary(root->left);
	}
	else if(root->right)
	{
		cout<<root->data<<" ";
		printleftBoundary(root->right);
	}
}
void printrightBoundary(node *root)
{
	if(!root)
	return;
	
	if(root->right)
	{
		printrightBoundary(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left)
	{
		printrightBoundary(root->left);
		cout<<root->data<<" ";
	}
}

void printLeaves(node *root)
{
	if(!root)
	return;
	
	printLeaves(root->left);
	
	if(!root->left && !root->right)
	cout<<root->data<<" ";
	
	printLeaves(root->right);
}
void printBoundary(node *root)
{
	if(!root)
	return;
	
	cout<<root->data<<" ";
	
	printleftBoundary(root->left);
	
	printLeaves(root->left);
	printLeaves(root->right);
	
	printrightBoundary(root->right);
}
int main()
{
	node *root         		  = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}
