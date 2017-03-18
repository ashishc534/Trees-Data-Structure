#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}**root,*temp;

void findLeafDown(node *root,int lev,int &distance)
{
	if(!root)
	return;
	
	if(!root->left && !root->right)
	{
	if(lev < distance)
	distance = lev;
	return;
	}
	
	findLeafDown(root->left,lev+1,distance);
	findLeafDown(root->right,lev+1,distance);
}

int findLeafRoot(node *root, node *x,int &distance)
{
	if(!root)
	return -1;
	
	if(root==x)
	return 0;
	
	int l=findLeafRoot(root->left , x , distance);
	
	if(l!=-1)
	{
		findLeafDown(root->right,l+2,distance);
		
		return l+1;
	}
	int r=findLeafRoot(root->right , x ,distance);
	
	if(r!=-1)
	{
		findLeafDown(root->left ,r+2,distance);
		return r+1;
	}
	return -1;
}
int minimumDistance(node *root, node *x)
{
	int dist=INT_MAX;
	
	findLeafDown(x,0,dist);
	
	findLeafRoot(root,x,dist);
	
	return dist;
}
node *newNode(int data)
{
	temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	
	return temp;
}
int main ()
{
    node *root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);
 
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
 
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
 
    root->right->left->left->left  = newNode(1);
    root->right->left->left->right = newNode(2);
    root->right->left->right->left  = newNode(3);
    root->right->left->right->right = newNode(4);
    root->right->right->left->left  = newNode(5);
    root->right->right->left->right = newNode(6);
    root->right->right->right->left = newNode(7);
    root->right->right->right->right = newNode(8);
 
    node *x = root->right;
 
    cout << "The closest leaf to the node with value "
         << x->data << " is at a distance of "
         << minimumDistance(root, x) << endl;
 
    return 0;
}
