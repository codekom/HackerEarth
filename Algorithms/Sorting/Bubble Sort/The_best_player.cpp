#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    vector<pair<string,int> > v;
    int t,n,i,j,fanquotient,x;
    string name;
    cin>>n>>t;
    for(i=0;i<n;i++)
    {
        cin>>name>>fanquotient;
        v.push_back(make_pair(name,fanquotient));
    }
    for(i=0;i<n;i++)
    {
        x=0;
        for(j=0;j<n-i-1;j++)
        {
            if(v[j].second<v[j+1].second)
            {
                pair<string,int> tmp;
                tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
                x++;
            }
            else if(v[j].second==v[j+1].second)
            {
                string s1,s2;
                s1=v[j].first;
                s2=v[j+1].first;
                if(s1.compare(s2)>0)
                {
                    pair<string,int> tmp;
                    tmp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=tmp;
                }
            }
        }
        if(x==0)
            break;
    }
    for(i=0;i<t;i++)
    {
        cout<<v[i].first<<'\n';
    }
    return 0;
}
