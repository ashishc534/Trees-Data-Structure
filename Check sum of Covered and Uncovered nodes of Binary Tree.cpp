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

int sumUncoveredright(node *root)
{
	if(!root->left && ! root->right)
	return root->data;
	
	if(root->right)
	return root->data +sumUncoveredright(root->right);
	else
	return root->data + sumUncoveredright(root->left);
}
int sumUncoveredLeft(node *root)
{
	if(!root->left && ! root->right)
	return root->data;
	
	if(root->left)
	return root->data +sumUncoveredLeft(root->left);
	else
	return root->data + sumUncoveredLeft(root->right);
}
int sumUncovered(node *root)
{
	int left=0,right=0;
	
	if(root->left)
	left=sumUncoveredLeft(root->left);
	
	if(root->right)
	right=sumUncoveredright(root->right);
	
	return root->data + left + right;
}
int TotalSum(node *root)
{
	if(!root)
	return 0;
	
	return(TotalSum(root->left)+TotalSum(root->right)+1);
}
int isSumSame(node *root)
{
	if(!root)
	return 1;
	
	int sumUC= sumUncovered(root);
	int sumT=TotalSum(root);
	
	return(sumUC == (sumT-sumUC));
	
}
int main()
{
    node* root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
 
    if (isSumSame(root))
        printf("Sum of covered and uncovered is same\n");
    else
        printf("Sum of covered and uncovered is not same\n");
}
