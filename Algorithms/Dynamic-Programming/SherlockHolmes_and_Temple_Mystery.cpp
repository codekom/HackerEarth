    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    int main()
    {
        ll t,n,i,j;
        ll cost[105];
        cin>>t;
        while(t--)
        {
            cin>>n;
            ll sum=0;
            for(i=0;i<n;i++)
            {
                cin>>cost[i];
                sum+=cost[i];
            }
            if(sum%2!=0)
                cout<<"NO\n";
            else
            {
               bool dp[sum/2+1][n+1];
               for(i=0;i<n;i++)
                  dp[0][i]=true;
               for(i=1;i<=sum/2;i++)
                  dp[i][0]=false;
               for(i=1;i<=sum/2;i++)
               {
                   for(j=1;j<=n;j++)
                   {
                       dp[i][j]=dp[i][j-1];
                       if(i>=cost[j-1])
                          dp[i][j]=dp[i][j-1]||dp[i-cost[j-1]][j-1];
                   }
               }
               if(dp[sum/2][n])
                  cout<<"YES\n";
               else
                  cout<<"NO\n";
            }
        }
        return 0;
    }
