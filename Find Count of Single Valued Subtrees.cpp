#include<bits/stdc++.h>
using namespace std;;

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
bool countSingle(node *root,int &count)
{
	if(!root)
	return true;
	
	bool left=countSingle(root->left,count);
	bool right=countSingle(root->right,count);
	
	if(!left || !right)
	return false;
	
	if(root->left && root->data!=root->left->data)
	return false;
	
	if(root->right && root->data !=root->right->data)
	return false;
	
	count++;
	return true;
}

int _countSingle(node *root)
{
	int count=0;
	countSingle(root,count);
	
	return count;
}
int main()
{
	node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);
 
    cout << "Count of Single Valued Subtrees is "<< _countSingle(root);
    return 0;
}
