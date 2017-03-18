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

bool isleaf(node *root)
{
	if(!root)
	return false;
	
	if(!root->left && !root->right)
	return true;
	
	return false;
}
int leftLeavesSum(node *root)
{
	int res=0;
	
	if(!root)
	return 0;
	
	if(isleaf(root->left))
	res+=root->left->data;
	
	else
	res+=leftLeavesSum(root->left);
	
	res+=leftLeavesSum(root->right);
	
	return res;
	
}
int main()
{
    node *root         		  = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);
    cout << "Sum of left leaves is "<< leftLeavesSum(root);
    return 0;
}
