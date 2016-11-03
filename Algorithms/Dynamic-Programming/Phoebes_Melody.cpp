#include<bits/stdc++.h>
#define MAX 200010
using namespace std;
typedef long long ll;
int main()
{
    ll t,n,k,i,sum,p,q;
    ll val[MAX];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(i=0;i<n;i++)
        {
            p=i-k;
            q=i+k;
            while(p>=0||q<n)
            {
                if((q<n&&val[q]<val[i])||(p>=0&&val[p]<val[i]))
                {
                    sum+=(i-q);
                    break;
                }
                p--;
                q++;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
