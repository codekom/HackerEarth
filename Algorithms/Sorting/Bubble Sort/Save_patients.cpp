#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,i,j,x,tmp;
    int a[12],b[12];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        x=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                x++;
            }
            if(b[j]>b[j+1])
            {
                tmp=b[j];
                b[j]=b[j+1];
                b[j+1]=tmp;
                x++;
            }
        }
        if(x==0)
            break;
    }
    int c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>b[i])
            c++;
    }
    if(c==n)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
