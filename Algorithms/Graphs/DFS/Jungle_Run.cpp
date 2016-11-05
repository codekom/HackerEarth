#include<bits/stdc++.h>
#define mod 1000000007
#define gc getchar
using namespace std;
typedef long long ll;
ll read_int() {
char c = gc();
while(c<'0' || c>'9') c = gc();
ll ret = 0;
while(c>='0' && c<='9') {
ret = 10 * ret + c - 48;
c = gc();
}
return ret;
}
char a[35][35];
int visited[35][35]={{0}};
int n,c=0,mini=INT_MAX;
bool isSafe(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&(a[x][y]=='P'||a[x][y]=='E')&&visited[x][y]==0)
        return true;
    return false;
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    //cout<<x<<" "<<y<<"\n";
    if(a[x][y]=='E')
    {
    	//cout<<c;
        if(c<mini)
            mini=c;
    }
    if(isSafe(x,y+1))
    {
        c++;
        dfs(x,y+1);
    }
    if(isSafe(x+1,y))
    {
        c++;
        dfs(x+1,y);
    }
    if(isSafe(x-1,y))
    {
        c++;
        dfs(x-1,y);
    }
    if(isSafe(x,y-1))
    {
        c++;
        dfs(x,y-1);
    }
    visited[x][y]=0;
    c--;
}
int main()
{
    int i,j,x,y;
    cin>>n;

    for(i=0;i<n;i++)
    {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                visited[i][j]=0;
                if(a[i][j]=='S')
                {
                    x=i;
                    y=j;
                }
            }
    }
    c=0;
    mini=INT_MAX;
    dfs(x,y);
    cout<<mini;
    return 0;
}
