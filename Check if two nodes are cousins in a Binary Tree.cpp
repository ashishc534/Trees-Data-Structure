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

int isSibling(node *root,node *a,node *b)
{
	if(!root)
	return 0;
	
	return((root->left==a && root->right==b)||(root->left==b && root->right==a)||isSibling(root->left,a,b)||isSibling(root->right,a,b));
}

int level(node *root,node *p,int lev)
{
	if(!root)
	return 0;
	
	if(root==p)
	return lev;
	
	int l=level(root->left,p,lev+1);
	if(l!=0)
	return l;
	
	else
	return (level(root->right,p,lev+1));
}

bool isCousin(node *root,node *a,node *b)
{
	return((level(root,a,1)==level(root,b,1)) &&!(isSibling(root,a,b)));
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    struct node *node1,*node2;
    node1 = root->left->left;
    node2 = root->right->right;
 
    isCousin(root,node1,node2)? cout<<("Yes"): cout<<("No");
 
    return 0;
}
