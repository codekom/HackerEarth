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
vector<ll> graph[100005];
ll visited[100005];
ll n,k,x;
void dfs(ll v,ll visited[])
{
    visited[v]=1;
    vector<ll>::iterator it;
    for(it=graph[v].begin();it!=graph[v].end();++it)
    {
        if(visited[*it]==0 && *it!=x)
        {
            dfs(*it,visited);
        }
    }
}
int main()
{
    ll i,a,b,c=0;
    memset(visited,0,sizeof(visited));
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin>>x;
    if(x==0)
        dfs(x+1,visited);
    else
        dfs(x-1,visited);
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            c++;
    }
    if(c>1)
        cout<<"Not Connected";
    else
        cout<<"Connected";
    return 0;
}
