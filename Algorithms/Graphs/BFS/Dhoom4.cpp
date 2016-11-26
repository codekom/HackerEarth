#include<bits/stdc++.h>
#define mod 100000
using namespace std;
typedef long long ll;
int main()
{
    ll a[1005];
    ll visited[100001];
    memset(visited,0,sizeof(visited));
    ll sk,lk,i,j,k,n,p;
    list<pair<ll,ll> > q;
    cin>>sk>>lk;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(sk==lk)
        cout<<0;
    else
    {
        q.push_back(make_pair(sk,0));
        ll f=0;
        while(!q.empty())
        {
            i=q.front().first;
            k=q.front().second;
            q.pop_front();
            visited[i]=1;
            for(j=0;j<n;j++)
            {
                p=(i*a[j])%mod;
                if(p==lk)
                {
                    f=k+1;
                    break;
                }
                if(!visited[p])
                {
                    q.push_back(make_pair(p,k+1));
                    visited[p]=1;
                }
            }
            if(f!=0)
                break;
        }
        if(f==0)
            cout<<-1;
        else
            cout<<f;
    }
    return 0;
}
