#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

node *newNode(int data)
{
	temp= new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}


bool isleaf(node *root)
{
	return root->left && root->left->right==root && root->right && root->right->left==root;
}
int maxheight(node *root)
{
	if(!root)
	return 0;
	
	if(isleaf(root))
	return 1;
	
	return 1 + max(maxheight(root->left),maxheight(root->right));
}
int main()
{
	node *root=NULL;
	root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->left->left=newNode(6);
	
	node *L1,*L2,*L3;
	L1=root->left->left->left;
	L2=root->left->right;
	L3=root->right;
	
	L1->right=L2;
	L2->right=L3;
	L3->right=L1;
	L2->left=L1;
	L3->left=L2;
	L1->left=L3;
	cout<<maxheight(root);
		
}
