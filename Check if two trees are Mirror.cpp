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

bool areMirror(node *a,node *b)
{
	if(!a && !b)
	return true;
	
	else if(!a || !b)
	return false;
	
	return (a->data==b->data && areMirror(a->left,b->right) && areMirror(a->right,b->left));
	
}
int main()
{
    node *a = newNode(1);
    node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);
 
    areMirror(a, b)? cout << "Yes" : cout << "No";
 
    return 0;
}
