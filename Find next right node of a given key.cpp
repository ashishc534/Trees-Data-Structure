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

node *nextRight(node *root,int k)
{
	if(!root)
	return NULL;
	
	queue<node *>qn;
	queue<int>ql;
	
	int level=0;
	
	qn.push(root);
	ql.push(level);
	
	while(!qn.empty())
	{
		int count=qn.size();
		while(count--)
		{
			temp = qn.front();
			level=ql.front();
			qn.pop();
			ql.pop();
			
			if(temp->data==k)
			{
				if(ql.empty() || ql.front()!=level)
				return NULL;
				
				return qn.front();
			}
			
			if(temp->left)
			{
				qn.push(temp->left);
				ql.push(level+1);
			}
			if(temp->right)
			{
				qn.push(temp->right);
				ql.push(level+1);
			}
		}
	}
	return NULL;
}
void test(node *root, int k)
{
    node *nr = nextRight(root, k);
    
	if (nr != NULL)
      cout << "Next Right of " << k << " is " << nr->data << endl;
    else
      cout << "No next right node found for " << k << endl;
}
 
int main()
{
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
 
    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
