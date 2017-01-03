#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
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
        k++;
    }
    else if(val < ptr->data)
    {
        ptr->left=insert(ptr->left,val);
    }
    else if(val > ptr->data)
    {
        ptr->right=insert(ptr->right,val);
    }
    return ptr;
}

int main()
{
    ll t,n,i,x,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        k=0;
        root=NULL;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            root=insert(root,j);
        }
        //cout<<k;
        if(k==x)
            cout<<"Good\n";
        else if(k<x)
            cout<<"Bad\n";
        else
            cout<<"Average\n";
    }

    return 0;
}
