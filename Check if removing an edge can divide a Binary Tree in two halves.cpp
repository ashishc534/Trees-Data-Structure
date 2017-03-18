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
int count(node *root)
{
	if(!root)
	return 0;
	
	return(count(root->left)+count(root->right)+1);
}
bool _check(node *root,int n, bool &res)
{
	if(!root)
	return false;
	
	int c=_check(root->left,n,res)+_check(root->right,n,res)+1;
	
	if(c==(n-c))
	res=true;
	
	return c;
}
bool check(node *root)
{
	if(!root)
	return false;
	
	bool res=false;
	int n=count(root);
	_check(root,n,res);
	return res;
}
int main()
{
    node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->right->right = newNode(4);
 	root->right->left->left = newNode(3);
 	root->right->left->right = newNode(2);
    root->right->right->right = newNode(8);
 
    check(root)? 	cout<<"YES": cout<<"NO";
 
    return 0;
}
