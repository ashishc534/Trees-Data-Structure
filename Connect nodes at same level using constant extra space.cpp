#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node *nextRight;
}**root,*temp;

node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->nextRight=temp->right=NULL;
	
	return temp;
}

node *getNext(node *root)
{
	temp = root->nextRight;
	
	
	while(temp!=NULL)
	{
		if(temp->left)
		return temp->left;
		
		if(temp->right)
		return temp->right;
		
		temp = temp->nextRight;
	}
	return NULL;
}
void connectRecur(node *root)
{
	if(!root)
	return;
	
	if(root->nextRight!=NULL)
	connectRecur(root->nextRight);
	
	if(root->left)
	{
		if(root->right)
		{
			root->left->nextRight=root->right;
			root->right->nextRight=getNext(root);
		}
		else
		root->left->nextRight=getNext(root);
		connectRecur(root->left);
	}
	else if(root->right)
	{
		root->right->nextRight=getNext(root);
		connectRecur(root->right);
	}
	else connectRecur(getNext(root));
}

void connect(node *root)
{
	root->nextRight=NULL;
	connectRecur(root);
}

int main()
{
    node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->right->right       = newNode(90);
 
    connect(root);
 
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight? root->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight? root->left->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight? root->right->right->nextRight->data: -1);
 
    getchar();
    return 0;
}
