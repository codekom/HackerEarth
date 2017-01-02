#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll color[100005],visited[100005],na[100005];
vector<ll> graph[100005];
stack<ll> l[100005];
void dfs(ll x,ll visited[])
{
    visited[x]=1;
    if(l[color[x]].empty())
        na[x]=-1;
    else
        na[x]=l[color[x]].top();
    //cout<<na[x]<<" "<<x<<" ";
    l[color[x]].push(x);
    if(!graph[x].empty())
    {
        vector<ll>::iterator it;
       for(it=graph[x].begin();it!=graph[x].end();++it)
       {
         if(!visited[*it])
            dfs(*it,visited);
       }
    }
    if(!l[color[x]].empty())
       l[color[x]].pop();

}
int main()
{
    ll n,c,i,par;
    memset(visited,0,sizeof(visited));
    scanf("%lld %lld",&n,&c);
    for(i=0;i<=100000;i++)
    {
        graph[i].clear();
    }
    for(i=1;i<n;i++)
    {
        scanf("%lld",&par);
        graph[par].push_back(i+1);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&color[i]);
    }
    dfs(1,visited);
    for(i=1;i<=n;i++)
        cout<<na[i]<<" ";
    return 0;
}
