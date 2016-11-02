#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
typedef long long ll;
int main()
{
    ll t,L,i,j,time=0,s,x;
    ll upper[MAX],lower[MAX];
    ll rem[MAX];
    cin>>t;
    while(t--)
    {
        cin>>L;
        time=L;
        memset(rem,0,sizeof(rem));
        for(i=1;i<L;i++)
            cin>>upper[i];
        for(i=1;i<L;i++)
        {
            cin>>lower[i];
            rem[i]=max(upper[i],lower[i]);
        }
        s=0;
        for(i=1;i<L;i++)
        {
            if(rem[i]<=(L-i))
                rem[i]=0;
            else
                rem[i]=rem[i]-(L-i);
        }
        for(i=1;i<L;i++)
        {
            if(rem[i]>0)
            {
                x=L-i;
                if(upper[i]-x>=0)
                    upper[i]-=x;
                if(lower[i]-x>=0)
                    lower[i]-=x;
                rem[i]=max(upper[i],lower[i]);
            }
        }
        s=*max_element(rem,rem+L);
        cout<<time+s<<endl;
    }
    return 0;
}
