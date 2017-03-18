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
int _maxDiff(node *root, int &res)
{
	if(!root)
	return INT_MAX;
	
	if(!root->left && root->right)
	return root->data;
	
	int val = min (_maxDiff(root->left,res),_maxDiff(root->right,res));
	
	res=max(res,root->data-val);
	
	return min(val,root->data);
}

int maxDiff(node *root)
{
	int res=INT_MIN;
	
	_maxDiff(root,res);
	return res;
}
int main()
{
    node* root=NULL;
    
    root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
 
    cout<<"Maximum difference between a node and"
           " its ancestor is :\n"<<maxDiff(root);
           
    return 0;
}
