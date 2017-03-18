#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
	node* left, *right;
}**root,*temp;
 
node *newNode(int data)
{
    temp = new node;
    temp->data=data;
    temp->left=temp->right=NULL;
    
    return temp;
}
 
void printInoder(node*root)
{
    if (root != NULL)
    {
        printInoder(root->left);
        cout<<root->data<<" ";
        printInoder(root->right);
    }
}
 
node *RemoveHalfNodes(node *root)
{
	if(!root)
	return NULL;
	
	root->left=RemoveHalfNodes(root->left);
	root->right=RemoveHalfNodes(root->right);
	
	if(!root->left && !root->right)
	return root;
		
	if(!root->left)
	{
		return root->right;
	}
	if(!root->right)
	{
		return root->left;	
	}
	return root;
} 
int main(void)
{
    node*NewRoot=NULL;
    node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
 
    cout<<"Inorder traversal of given tree \n";
    printInoder(root);
 
    NewRoot = RemoveHalfNodes(root);
 
    cout<<"\nInorder traversal of the modified tree \n";
    printInoder(NewRoot);
    return 0;
}
