#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
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

int eval(node *root)
{
	if(!root)
	return 0;
	
	int lVal=eval(root->left);
	int rVal=eval(root->right);
	
	if(root->data=='+')
	return lVal+rVal;
	
	if(root->data=='-')
	return lVal-rVal;
	
	if(root->data=='*')
	return lVal*rVal;
	
	if(root->data=='/')
	return lVal/rVal;
}
int main()
{
	node *root=NULL;
	root=newNode('+');
	root->left=newNode('*');
	root->right=newNode('-');
	root->left->left=newNode(5);
	root->left->right=newNode(4);
	root->right->left=newNode(100);
	root->right->right=newNode('/');
	root->right->right->left=newNode(20);
	root->right->right->right=newNode(2);
	
	
	cout<<eval(root);
}
