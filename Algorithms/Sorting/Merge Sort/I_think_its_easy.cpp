#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
void mergeArrays(vector<pair<string,int>> &a,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int i,j,k;
    vector<pair<string,int>> l1,l2;
    for(i=0;i<n1;i++){
        l1.push_back(make_pair(a[p+i].first,a[p+i].second));
    }
    for(j=0;j<n2;j++){
        l2.push_back(make_pair(a[q+1+j].first,a[q+j+1].second));
    }
    i=0;j=0;k=p;
    while(i<n1 && j<n2)
    {
        if(l1[i].second<=l2[j].second){
            a[k].first=l1[i].first;
            a[k].second=l1[i].second;
            i++;
        }
        else{
            a[k].first=l2[j].first;
            a[k].second=l2[j].second;
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k].first=l1[i].first;
        a[k].second=l1[i].second;
        i++;
        k++;
    }
    while(j<n2){
        a[k].first=l2[j].first;
        a[k].second=l2[j].second;
        j++;
        k++;
    }
}
void mergeSort(vector<pair<string,int>> &a,int p,int r)
{
    if(p<r){
        int q=p+(r-p)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        mergeArrays(a,p,q,r);
    }
}
int main()
{
    int t,i,n;
    vector<pair<string,int>> arr;
    string str,token;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin,str);
        arr.clear();
        istringstream tokenStream(str);
        while(getline(tokenStream,token,' '))
        {
            arr.push_back(make_pair(token,token.length()));
        }
        mergeSort(arr,0,arr.size()-1);
        for(i=0;i<arr.size();i++)
        {
            cout<<arr[i].first<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
