#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,m,i,j,troops,maxi,c,x,y;
    ll a[1005][1005];
    ll visited[1005][1005];
    list<pair<ll,ll> > q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        troops=0;
        maxi=0;
        q.clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==0)
                    visited[i][j]=1;
                else if(visited[i][j]==0 && a[i][j]==1)
                {
                    q.push_back(make_pair(i,j));
                    visited[i][j]=1;
                    c=0;
                    while(!q.empty())
                    {
                        x=(q.front()).first;
                        y=(q.front()).second;
                        q.pop_front();
                        c++;
                        if((x+1)<n && a[x+1][y]==1 && visited[x+1][y]==0)
                        {
                            q.push_back(make_pair(x+1,y));
                            visited[x+1][y]=1;
                        }
                        if((x-1)>=0 && a[x-1][y]==1 && visited[x-1][y]==0)
                        {
                            q.push_back(make_pair(x-1,y));
                            visited[x-1][y]=1;
                        }
                        if((y+1)<m && a[x][y+1]==1 && visited[x][y+1]==0)
                        {
                            q.push_back(make_pair(x,y+1));
                            visited[x][y+1]=1;
                        }
                        if((y-1)>=0 && a[x][y-1]==1 && visited[x][y-1]==0)
                        {
                            q.push_back(make_pair(x,y-1));
                            visited[x][y-1]=1;
                        }
                        if((x+1)<n && (y-1)>=0 && a[x+1][y-1]==1 && visited[x+1][y-1]==0)
                        {
                            q.push_back(make_pair(x+1,y-1));
                            visited[x+1][y-1]=1;
                        }
                        if((x+1)<n && (y+1)<m && a[x+1][y+1]==1 && visited[x+1][y+1]==0)
                        {
                            q.push_back(make_pair(x+1,y+1));
                            visited[x+1][y+1]=1;
                        }
                        if((x-1)>=0 && (y+1)<m && a[x-1][y+1]==1 && visited[x-1][y+1]==0)
                        {
                            q.push_back(make_pair(x-1,y+1));
                            visited[x-1][y+1]=1;
                        }
                        if((x-1)>=0 && (y-1)>=0 && a[x-1][y-1]==1 && visited[x-1][y-1]==0)
                        {
                            q.push_back(make_pair(x-1,y-1));
                            visited[x-1][y-1]=1;
                        }
                        
                    }
                    maxi=max(maxi,c);
                    troops++;
                }
            }
        }
        cout<<troops<<" "<<maxi<<"\n";
    }
    return 0;
}
