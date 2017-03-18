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

bool _isBalanced(node *root,int &maxH,int &minH)
{
	if(!root)
	{
		maxH=minH=0;
		return true;
	}
	
	int lmxH,lmnH;
	int rmxH,rmnH;
	
	if(_isBalanced(root->left,lmxH,lmnH)==false)
	return false;
	
	if(_isBalanced(root->right,rmxH,rmnH)==false)
	return false;
	
	maxH=max(lmxH,rmxH)+1;
	minH=min(lmnH,rmnH)+1;
	
	if(maxH <= 2*minH)
	return true;
	
	return false;
}
bool isBalanced(node *root)
{
	int maxH,minH;
	return (_isBalanced(root,maxH,minH));
}
int main()
{
    node * root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(100);
    root->right->left = newNode(50);
    root->right->right = newNode(150);
    root->right->left->left = newNode(40);
    
	isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";
 
    return 0;
}
