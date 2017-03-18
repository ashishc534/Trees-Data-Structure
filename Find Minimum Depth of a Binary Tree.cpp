#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    node* left, *right;
}**root,*temp;
 
 
node *newNode(int data)
{
    node *temp = new node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}

int minDepth(node *root)
{
	if(!root)
	return 0;
	
	if(!root->left && !root->right)
	return 1;
	
	if(!root->left)
	return minDepth(root->right)+1;
	
	if(!root->right)
	return minDepth(root->left)+1;
	
	return (min(minDepth(root->left),minDepth(root->right)))+1;	
} 
int main()
{
    node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
	cout << minDepth(root);
    
	return 0;
}
