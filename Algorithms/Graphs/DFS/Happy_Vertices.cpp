#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[100005];
vector<ll> graph[100005];
ll ch[100005],parent[100005];

void dfs(ll v,bool visited[])
{
    ll c=0;
    visited[v]=true;
    vector<ll>::iterator it;
    for(it=graph[v].begin();it!=graph[v].end();++it)
    {
        if(visited[*it]==false)
        {
            c++;
            parent[*it]=v;
            dfs(*it,visited);
        }
    }
    ch[v]=c;
}

int main()
{
    ll n,m,i,j,x,y;
    cin>>n>>m;
    for(i=0;i<=n+1;i++)
    {
    	visited[i]=false;
    	parent[i]=0;
    	ch[i]=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            parent[i]=0;
            dfs(i,visited);
        }
    }
    /*for(i=1;i<=n;i++)
        cout<<ch[i]<<" ";
    cout<<"\n";
    for(i=1;i<=n;i++)
        cout<<parent[i]<<" ";*/
    ll h=0;
    for(i=1;i<=n;i++)
    {
        if(parent[i]!=0)
        {
            if(ch[i]>ch[parent[i]])
                h++;
        }
    }
    cout<<h;
    return 0;
}
