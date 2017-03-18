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

bool isMirror(node *root1, node *root2)
{
	if(!root1 && !root2)
	return true;
	
	if(!root1 || !root2)
	return false;
	
	return (isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left));
	
}
bool IsFoldable(node *root)
{
	if(!root)
	return true;
	
	return (isMirror(root->left,root->right));
}
int main()
{
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);
 
  if(IsFoldable(root) == true)
  
  { 
  cout<<"\n tree is foldable"; 
  }
  
  else
  { 
  cout<<"\n tree is not foldable"; 
  }
 
  getchar();
  return 0;
}
