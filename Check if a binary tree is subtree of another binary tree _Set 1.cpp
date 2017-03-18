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

bool areIdentical(node *s,node *t)
{
	if(!t && !s)
	return true;
	
	if(!s || !t)
	return false;
	
	if(t->data==s->data)
	return true;
	
	return(areIdentical(s->left,t->left)&&areIdentical(s->right,t->right)); 
}
bool isSubtree(node *t,node *s)
{
	if(!s)
	return true;
	
	if(!t)
	return false;
	
	
	if(areIdentical(t,s))
	return true;
	
	return (isSubtree(t->left,s) || isSubtree(t->right,s));
}
int main()
{
    node *T        		  = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
    cout<<"Tree 2 is subtree of Tree 1";
    
	else
    cout<<"Tree 2 is not a subtree of Tree 1";
 
    getchar();
    return 0;
}
