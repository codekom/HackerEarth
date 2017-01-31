#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll count_one(ll n)
{
    ll c=0;
    while(n)
    {
        n=n&(n-1);
        c++;
    }
    return c;
}
struct c_ones
{
    ll a,b,c;
};
c_ones brr[300010];
int compasc(const void *x,const void *y)
{
    c_ones *p = (c_ones *)x;
    c_ones *q = (c_ones *)y;
    if(p->a > q->a)
        return 1;
    else if(p->a == q->a && p->c > q->c)
        return 1;
    else
        return -1;
    return 0;
}
int main()
{
    ll t,n,i;
    ll arr[100005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            brr[i].a=count_one(arr[i]);
            brr[i].b=arr[i];
            brr[i].c=i+1;
        }
        qsort(brr,n,sizeof(c_ones),compasc);
        for(i=0;i<n;i++)
        {
            cout<<brr[i].b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
