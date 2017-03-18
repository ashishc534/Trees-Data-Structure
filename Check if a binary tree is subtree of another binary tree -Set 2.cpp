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

void storeInOrder(node *root,char arr[],int &index)
{
	if(!root)
	{
		arr[index++]='$';
		return;
	}
	arr[index++]=root->data;
	storeInOrder(root->left,arr,index);
	storeInOrder(root->right,arr,index);
}

void storePreOrder(node *root,char arr[],int &index)
{
	if(!root)
	{
		arr[index++]='$';
		return;
	}
	arr[index++]=root->data;
	storePreOrder(root->left,arr,index);
	storePreOrder(root->right,arr,index);
}
int isSubtree(node *t , node *s)
{
	if(!t)
	return 0;
	
	if(!s)
	return 1;
	
	int m=0,n=0;
	
	char inT[100],inS[100];
	storeInOrder(t,inT,m);
	storeInOrder(s,inS,n);
	inT[m]='\0';
	inS[n]='\0';
	
	if(strstr(inT,inS)==NULL)
	return 0;
	
	m=0,n=0;
	char preT[100],preS[100];
	storePreOrder(t,preT,m);
	storePreOrder(s,preS,n);
	preS[n]='\0';
	preT[m]='\0';
	
	return(strstr(preT,preS)!=NULL);
}
int main()
{
    node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
 
    return 0;
}
