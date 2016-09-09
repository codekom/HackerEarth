#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node
{
    ll info;
    struct node* link;
}*head,*q,*p;
int main()
{
    ll n,c=0,i,d,x;
    cin>>n;
    ll ideal[n];
    for(i=0;i<n;i++)
    {
        cin>>d;
        q=new node;
        q->info=d;
        q->link=NULL;
        if(i==0){
          head=q;
          p=head;
        }
        else
        {
            p->link=q;
            p=q;
        }
    }
    for(i=0;i<n;i++)
    {
        cin>>ideal[i];
    }
        for(i=0;i<n;i++)
        {
            x=ideal[i];
            while(1)
            {
                p=head;
                if(p->info!=x)
                {
                    q->link=p;
                    q=p;
                    if(p==head)
                    {
                        head=p->link;
                    }
                    p->link=NULL;
                    c++;
                }
                else
                {
                    c++;
                    head=head->link;
                    break;
                }
            }
        }
    cout<<c;
    return 0;
}

