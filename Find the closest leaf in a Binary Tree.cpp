#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
}**root,*temp;

node *newNode(char data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}

int closestDown(node *root)
{
	if(!root)
	return INT_MAX;
	
	if(!root->left && !root->right)
	return 0;
	
	return(1+ min(closestDown(root->left),closestDown(root->right)));
	
}
int _findClosest(node *root, char k ,node *ancestors[],int index)
{
	if(!root)
	return INT_MAX;
	
	if(root->data == k)
	{
		int res=closestDown(root);
		
		for(int i=index-1;i>=0;i--)
		res=min(res,index-i+closestDown(ancestors[i]));
		return res;
	}
	ancestors[index]=root;
	
	return min(_findClosest(root->left,k,ancestors,index+1),_findClosest(root->right,k,ancestors,index+1));
	
}
int findClosest(node *root, char k)
{
	node *ancestors[100];
	
	return _findClosest(root,k,ancestors,0);
	
}
int main()
{
    node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
 
    return 0;
}
