#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll data;
    node *left;
    node *right;
}*root=NULL;

struct node* insert(node *ptr,ll val)
{
    if(ptr==NULL)
    {
        ptr=new node;
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->data=val;
    }
    else if(val < ptr->data)
        ptr->left=insert(ptr->left,val);
    else
        ptr->right=insert(ptr->right,val);
    return ptr;
}
int main()
{
    ll n,i,x,y,nx,ny,maxi;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    cin>>x>>y;
    nx=min(x,y);
    ny=max(x,y);
    x=nx;y=ny;
    maxi=y;
    while((root->data>y && root->data>x) || (root->data<y && root->data<x))
    {
        if(root->data>y && root->data>x)
            root=root->left;
        else if(root->data<y && root->data<x)
            root=root->right;
    }
    node *p=root;
    while(root->data!=y)
    {
        if(root->data>y)
        {
            maxi=max(root->data,maxi);
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    root=p;
    while(root->data!=x)
    {
        if(root->data>x)
        {
            maxi=max(root->data,maxi);
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    cout<<maxi;
    return 0;
}
