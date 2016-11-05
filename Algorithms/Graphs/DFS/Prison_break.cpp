#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int a[25][25]={{0}};
int visited[25][25]={{0}};
int n,c=0;
bool isSafe(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]==0&&visited[x][y]==0)
        return true;
    return false;
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    if(x==n-1&&y==n-1)
        c++;
    if(isSafe(x,y+1))
        dfs(x,y+1);
    if(isSafe(x+1,y))
        dfs(x+1,y);
    if(isSafe(x-1,y))
        dfs(x-1,y);
    if(isSafe(x,y-1))
        dfs(x,y-1);
    visited[x][y]=0;
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }
        if(a[0][0]==1 && a[n-1][n-1]==1)
            cout<<0<<'\n';
        else
        {
            c=0;
            dfs(0,0);
            cout<<c<<"\n";
        }
    }
    return 0;
}
