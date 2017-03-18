#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *l;
	node *r;
}**root,*temp;

node *newNode(int data)
{
	temp= new node;
	temp->data=data;
	temp->l=temp->r=NULL;
	
	return temp;
}

int MaxSum(node *root)
{
	if(!root)
	return 0;
	
	int result=root->data;
	
	queue<node *>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		int count=q.size();
		int sum=0;
		while(count--)
		{
			node *temp= q.front();
			q.pop();
			
			sum=sum+temp->data;
			
			if(temp->l)
			q.push(temp->l);
			
			if(temp->r)
			q.push(temp->r);
		}
		result=max(sum,result);
	}
	return result;
}
int main()
{
	node *n=NULL;
	n=newNode(4);
	n->l=newNode(2);
	n->r=newNode(-5);
	n->l->l=newNode(-1);
	n->l->r=newNode(3);
	n->r->l=newNode(-2);
	n->r->r=newNode(6);
	
	cout<<MaxSum(n)<<endl;
	return 0;
}
