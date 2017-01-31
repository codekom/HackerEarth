#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,i,x;
    ll a[100005];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll e=0,o=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if((x&1)==0)
                e++;
            else
                o++;
        }
        printf("%lld\n",(e*o));
    }
    return 0;
}
