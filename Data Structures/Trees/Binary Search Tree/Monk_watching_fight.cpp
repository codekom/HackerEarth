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
    else if(val <= ptr->data)
        ptr->left=insert(ptr->left,val);
    else
        ptr->right=insert(ptr->right,val);
    return ptr;
}
ll height(node *root)
{
    if(root==NULL)
        return 0;
    ll leftH=height(root->left);
    ll rightH=height(root->right);
    if(leftH>rightH)
        return leftH+1;
    else
        return rightH+1;
}
int main()
{
    ll n,i,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    cout<<height(root);
    return 0;
}
