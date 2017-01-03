#include<iostream>
#include<set>
#include<cstdio>
#define gc getchar
typedef long long int ll;
using namespace std;
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
    ll t,n,m,x,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        set<ll> v;
        set<ll>::iterator it;
        for(i=0;i<n;i++)
        {
            x=read_int();
            v.insert(x);
        }
        for(i=0;i<m;i++)
        {
            x=read_int();
            if(v.find(x)!=v.end())
                cout<<"YES\n";
            else
                cout<<"NO\n";
            v.insert(x);
        }
    }
    return 0;
}
