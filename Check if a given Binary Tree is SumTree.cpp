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

int sum(node *root)
{
	if(!root)
	return 0;
	
	return (root->data + sum(root->left) + sum(root->right));
}

bool isLeaf(node *root)
{
	if(!root->left && !root->right)
	return true;
	
	return false;
}
int isSumTree(node *root)
{
	if(!root || isLeaf(root))
	return 1;
	
	int ls,rs;
	
	ls=sum(root->left);
	rs=sum(root->right);
	
	if((ls+rs==root->data) && isSumTree(root->left) && isSumTree(root->right))
	return 1;
	
	return 0; 
}
int main()
{
    node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    
	if(isSumTree(root))
    cout<<"The given tree is a SumTree ";
    else
    cout<<"The given tree is not a SumTree ";
 
    getchar();
    return 0;
}
