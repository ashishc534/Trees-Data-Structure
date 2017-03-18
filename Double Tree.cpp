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

void doubleTree(node *root)
{
	node *oldLeft;
	
	if(!root)
	return;
	
	doubleTree(root->left);
	doubleTree(root->right);
	
	oldLeft=root->left;
	root->left=newNode(root->data);
	root->left->left=oldLeft;
}

void inOrder(node *root)
{
	if(!root)
	return;
	
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  cout<<"Inorder traversal of the original tree is \n";
  inOrder(root);
 
  doubleTree(root);
   
  cout<<"\n Inorder traversal of the double tree is \n";  
  inOrder(root);
    
  getchar();
  return 0;
}
