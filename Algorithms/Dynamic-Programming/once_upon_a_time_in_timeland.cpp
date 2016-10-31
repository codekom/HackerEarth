#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,j,t,k,x;
    ll a[10005],dp[10005];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
                a[i]=0;
        }
        dp[0]=a[0];
        for(i=1;i<n;i++)
        {
            x=i-k-1;
            if(x==0)
                dp[i]=a[i]+dp[x];
            else if(x>0)
            {
                ll mi=dp[x]+a[i];
                ll p=x-k-1;
                if(p<0)
                    p=0;
                for(j=x;j>=p;j--)
                {
                    if(a[i]+dp[j]>mi)
                        mi=a[i]+dp[j];
                }
                dp[i]=mi;
            }
            else
                dp[i]=a[i];
        }
        ll maxi=dp[n-1];
        for(i=n-1;i>=(n-k-1);i--)
        {
            if(dp[i]>maxi)
                maxi=dp[i];
        }
        cout<<maxi<<'\n';
    }
    return 0;
}
