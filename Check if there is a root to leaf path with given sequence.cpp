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

bool existPath(node *root,int arr[],int index,int n)
{
	if(!root)
	return false;
	
	
	if(!root->left && !root->right && root->data==arr[index] && (index==n-1))
	return true;
	
	return((index < n) && root->data == arr[index] && existPath(root->left,arr,index+1,n)||existPath(root->right,arr,index+1,n));

}
int main()
{
    int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
   	
	node *root = newNode(5);
    root->left    = newNode(3);
    root->right   = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right->left = newNode(6);
    root->right->left->right = newNode(7);
 
    existPath(root, arr, 0, n)? cout << "Path Exists" :
                                cout << "Path does not Exist";
    return 0;
}
