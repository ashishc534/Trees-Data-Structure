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

bool _check(node *root , int level , int &leaflevel)
{
	if(!root)
	return true;
	
	if(!root->left && !root->right)
	{
		if(leaflevel==0)
		{
			leaflevel=level;
			return true;
		}
		return (level==leaflevel);
	}
	return _check(root->left,level+1,leaflevel)&&_check(root->right,level+1,leaflevel);
}
bool check(node *root)
{
	int level=0,leaflevel=0;
	
	return _check(root,level,leaflevel);
}
int main()
{
    node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout<<"Leaves are at same level\n";
    else
        cout<<"Leaves are not at same level\n";
    getchar();
    return 0;
}
