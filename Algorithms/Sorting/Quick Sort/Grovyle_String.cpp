#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,i,n,j;
    int ch[26];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(ch,0,sizeof(ch));
        n=s.length();
        char str[n+1];
        int p=1,q=n-1,k=0,curr=q;
        for(i=0;i<n;i++){
            ch[s[i]-97]++;
        }
        for(i=0;i<26;i++){
            for(j=1;j<=ch[i];j++){
                str[k]=(char)(i+97);
                if(curr==q){
                    k=q;
                    q--;
                    curr=p;
                }
                else{
                    k=p;
                    p++;
                    curr=q;
                }
            }
        }
        str[n]='\0';
        cout<<str<<endl;
    }
    return 0;
}
