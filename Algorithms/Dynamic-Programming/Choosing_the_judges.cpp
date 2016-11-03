#include<bits/stdc++.h>
#define MAX 200010
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,i,x=1;
    ll a[10005],dp[10005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        if(n>0)
        {
        	dp[0]=a[0];
        	if(n>1)
               dp[1]=a[1];
            if(n>=3)
              dp[2]=dp[0]+a[2];
           for(i=3;i<n;i++)
              dp[i]=a[i]+max(dp[i-2],dp[i-3]);
           if(n>=2)
             cout<<"Case "<<x<<": "<<max(dp[n-1],dp[n-2])<<"\n";
           else
             cout<<"Case "<<x<<": "<<dp[n-1]<<"\n";
        }
        else
           cout<<"Case "<<x<<": "<<0<<"\n";
        x++;
    }
    return 0;
}
