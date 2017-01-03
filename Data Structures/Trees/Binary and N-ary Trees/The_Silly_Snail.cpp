#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll data;
    node *left;
    node *right;
}*root=NULL;
node *arr[100005];
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    ll t,x,y,z,n,i,j;
    node *tmp,*tmpl,*tmpr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        j=n;
        root=NULL;
        for(i=0;i<=100000;i++)
            arr[i]=NULL;
        while(n>0)
        {
            cin>>x>>y>>z;
            if(arr[x]==NULL)
            {
                tmp=new node;
                tmp->data=x;
                tmp->left=NULL;
                tmp->right=NULL;
            }
            else
                tmp=arr[x];
            if(arr[y]==NULL && y!=0)
            {
                tmpl=new node;
                tmpl->data=y;
                tmpl->left=NULL;
                tmpl->right=NULL;
            }
            else
                tmpl=arr[y];
            if(arr[z]==NULL && z!=0)
            {
                tmpr=new node;
                tmpr->data=z;
                tmpr->left=NULL;
                tmpr->right=NULL;
            }
            else
                tmpr=arr[z];
            if(y!=0)
                tmp->left=tmpl;
            if(z!=0)
                tmp->right=tmpr;
            arr[x]=tmp;
            arr[y]=tmpl;
            arr[z]=tmpr;
            if(root==NULL)
               root=tmp;
            n--;
        }
        preorder(root);
        if(j==0)
            cout<<1;
        cout<<'\n';
    }
    return 0;
}
