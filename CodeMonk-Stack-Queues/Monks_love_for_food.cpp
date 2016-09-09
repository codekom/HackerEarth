#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long ll;
ll stack[100005];
int main()
{
    ll q,t,c,top=-1;
    cin>>q;
    while(q--)
    {
        cin>>t;
        if(t==2)
        {
            cin>>c;
            top++;
            stack[top]=c;
        }
        else if(t==1 && top==-1)
        {
            cout<<"No Food\n";
        }
        else if(t==1 && top!=-1)
        {
            cout<<stack[top]<<'\n';
            top--;
        }
    }
    return 0;
}

