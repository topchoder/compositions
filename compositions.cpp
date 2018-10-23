#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    node *next;
};

node *nuget(int x)
{
	node *nu=new node;
   	nu->a=x;
   	nu->next=NULL;
    	return nu;
}

void coutin(node *root)
{
	while(root)
	{
	    cout<<root->a<<" ";
	    root=root->next;
	}
	cout<<"\n";
	return;
}
//function for generating the compositions
void permlist(int sum,int x,node **root,int n)
{
	if(!sum)//print the current composition
	{
	     coutin(*root);
	     return;
	}
	for(int i=1;i<=n;i++)
	{
	    if(*root==NULL&&sum>=i)//if the current list is empty add the first
	    {
		*root=nuget(i);
                 permlist(sum-i,i,root,n);
                 *root=NULL;//backtracking for other options
	    }
	    else if(*root&&sum>=i)//if the current list not empty
	    {
		node *tem=*root;
		while(tem->next)//going to the last of current list
		{
		     tem=tem->next;
		}
		tem->next=nuget(i);
        	permlist(sum-i,i,root,n);
      		while(tem->next->next)//removing the last element to try other possibility
      		{
         		tem=tem->next;
      		}
      		node *tem1=tem->next;
      		tem->next=tem1->next;
	    }
	}  
	return;
}

signed main()
{
   	int sum=6;
    	node *root=NULL;//list to store the compositions
    	permlist(sum,1,&root,sum);
	return 0;
}
