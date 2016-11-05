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
ll knowledge[100005];
ll visited[100005];
vector<ll> graph[100005];
ll n,m,c,maxi;
void dfs(ll v,ll visited[])
{
    visited[v]=1;
    vector<ll>::iterator it;
    for(it=graph[v].begin();it!=graph[v].end();++it)
    {
        if(visited[*it]==0)
        {
            if(knowledge[*it]>maxi)
            {
                maxi=knowledge[*it];
                c=1;
            }
            else if(knowledge[*it]==maxi)
            {
            	c++;
            	c=c%mod;
            }
            dfs(*it,visited);
        }
    }
}
int main()
{
    n=read_int();
    m=read_int();
    ll i,u,v,ans=1;
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
        cin>>knowledge[i];
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        if(u!=v)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            maxi=knowledge[i];
            c=1;
            dfs(i,visited);
            ans*=c;
            ans=ans%mod;
        }
    }
    cout<<ans;
    return 0;
}
