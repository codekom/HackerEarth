#include<bits/stdc++.h>
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
int main()
{
     const ll mod=1e9+7;
     ll i,x,sum,j,v;
     vector<ll> g;
     for(i=0;i<=60;i++)
     {
         x=pow(2,i);
         g.push_back(x);
     }
     ll t,n,sz;
     t=read_int();
     sz=g.size();
     while(t--)
     {
         n=read_int();
         sum=0;
         for(i=0;i<sz;i++)
         {
             if(g[i]>n)
                break;
             for(j=i+1;j<sz;j++)
             {
                 if(g[i]+g[j]>n)
                    break;
                 sum=(sum%mod+(g[i]+g[j])%mod)%mod;
             }
         }
         printf("%lld\n",sum);
     }
     return 0;
}
