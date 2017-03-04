#include<bits/stdc++.h>
#define gc getchar
using namespace std;
int read_int() {
char c = gc();
while(c<'0' || c>'9') c = gc();
int ret = 0;
while(c>='0' && c<='9') {
ret = 10 * ret + c - 48;
c = gc();
}
return ret;
}
int main()
{
    int t,n,x,y,v;
    t=read_int();
    while(t--)
    {
        n=read_int();
        queue<pair<int,int> > q;
        set<int> s;
        s.insert(n);
        q.push(make_pair(n,0));
        while(!q.empty())
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            if(x==1)
                break;
            else
            {
                if(x>1)
                {
                    v=s.size();
                    s.insert(x-1);
                    if(s.size()!=v)
                      q.push(make_pair(x-1,y+1));
                }
                if(x>=3 && x%3==0)
                {
                    v=s.size();
                    s.insert(x/3);
                    if(s.size()!=v)
                      q.push(make_pair(x/3,y+1));
                }
                if(x>=2 && x%2==0)
                {
                    v=s.size();
                    s.insert(x/2);
                    if(s.size()!=v)
                      q.push(make_pair(x/2,y+1));
                }
            }
        }
        printf("%d\n",y);
    }
    return 0;
}
