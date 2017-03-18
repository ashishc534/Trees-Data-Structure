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

int totalNodes(node *root)
{
	if(!root)
	return 0;
	
	return(1 + totalNodes(root->left) + totalNodes(root->right));
}
bool check(node *root,int index,int n)
{
	if(!root)
	return true;
	
	if(index >= n)
	return false;
	
	return(check(root->left,2*index+1,n) && check(root->right,2*index+2,n));
	
}
bool isComplete(node *root)
{
	int index=0;
	int n=totalNodes(root);
	return (check(root,index,n));
}
int main()
{
	node *root=NULL;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	
	isComplete(root)? cout<<"YES":cout<<"NO";
	
	return 0;		
}
