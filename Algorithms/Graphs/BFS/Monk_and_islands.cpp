#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,m,x,y,i,v,c;
    int visited[10005];
    list<pair<ll,ll> > q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(visited,0,sizeof(visited));
        vector<ll> graph[10005];
        q.clear();
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        v=1;
        vector<ll>::iterator it;
        q.push_back(make_pair(v,0));
        ll mini=LONG_LONG_MAX;
        visited[v]=true;
        while(!q.empty())
        {
            v=(q.front()).first;
            y=(q.front()).second;
            q.pop_front();
            for(it=graph[v].begin();it!=graph[v].end();++it)
            {
                x=*it;
                if(x!=n && visited[x]==0)
                {
                    q.push_back(make_pair(x,y+1));
                    visited[x]=1;
                }
                else if(x==n)
                    mini=min(y+1,mini);
            }
        }
        cout<<mini<<"\n";
    }
    return 0;
}
