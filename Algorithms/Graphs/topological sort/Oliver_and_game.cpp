#include<bits/stdc++.h>
#define gc getchar
using namespace std;
int read_int() {
char c = gc();
while(c<'0' || c>'9') c = gc();
int ret = 0;
while(c>='0' && c<='9') {
ret = 10 * ret + c - 48;
c = gc();
}
return ret;
}
vector<int> graph[100005];
int visited[100005];
int disc_time[100005],finish_time[100005];
int tim=0;
void dfs(int v)
{
    tim++;
    disc_time[v]=tim;
    visited[v]=1;
    for(int i=0;i<graph[v].size();i++)
    {
        if(!visited[graph[v][i]])
            dfs(graph[v][i]);
    }
    finish_time[v]=++tim;
}
int main()
{
    int n,a,b,x,y,q,i,t;
    memset(visited,0,sizeof(visited));
    n=read_int();
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
    }
    dfs(1);
    q=read_int();
    while(q--)
    {
        t=read_int();
        x=read_int();
        y=read_int();
        if(t==0)
        {
            if(disc_time[x]<disc_time[y] && finish_time[x]>finish_time[y])
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(disc_time[y]<disc_time[x] && finish_time[y]>finish_time[x])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
