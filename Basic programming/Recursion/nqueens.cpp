#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int n;
int is_attacked(int a[][12],int x,int y)
{
    for(int i=0;i<n;i++)
    {
        if(a[x][i]==1)
            return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i][y]==1)
            return 1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+j)==(x+y) && a[i][j]==1)
               return 1;
            if((i-j)==(x-y) && a[i][j]==1)
               return 1;
        }
    }
    return 0;
}
int nqueens(int a[][12],int q)
{
    if(q==n)
        return 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(is_attacked(a,i,j))
                continue;
            a[i][j]=1;
            if(nqueens(a,q+1))
             {
                return 1;
             }
            a[i][j]=0;
        }
    }
    return 0;
}
int main()
{
    int x;
    cin>>n;
    memset(a,0,sizeof(a));
    x=nqueens(a,0);
    if(x==1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else
        cout<<"Not possible\n";
    return 0;
}
