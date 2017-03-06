#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll limit=1000005;
vector<ll> prime(limit,1),count_prime(limit,0),pp(limit,0),arr(limit,0);
void sieve()
{
    ll i,j;
    prime[0]=0;
    prime[1]=0;
    for(i=2;i*i<=limit;i++)
    {
        if(prime[i]==1)
        {
            for(j=i*2;j<=limit;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    for(i=1;i<=limit;i++)
    {
        count_prime[i]+=count_prime[i-1]+prime[i];
        if(prime[count_prime[i]])
            pp[i]=1;
    }
    for(i=1;i<=1000000;i++)
    {
        arr[i]+=(arr[i-1]+pp[i]);
    }
}
int main()
{
    ll t,l,r,i,x,c;
    sieve();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&l,&r);
        c=0;
        /*for(i=l;i<=r;i++)
        {
            if(pp[i])
                c++;
        }*/
        if((pp[l]&&pp[r]) || (pp[l]&&!pp[r]))
            c=arr[r]-arr[l]+1;
        else if((!pp[l] && pp[r]) || (!pp[l] && !pp[r]))
            c=arr[r]-arr[l];
        printf("%lld\n",c);
    }
    return 0;
}
