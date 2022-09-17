#include<bits/stdc++.h>
using namespace std;
void subsequences(int i,vector<int> &a,int arr[],int n){
    if(i>=n){
        for(auto i:a){cout<<i<<" ";}
        if(a.size()==0){cout<<"{}";}
        cout<<"\n";return;
    }
    a.push_back(arr[i]);
    subsequences(i+1,a,arr,n);
    a.pop_back();
    subsequences(i+1,a,arr,n);
}

int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
             
             int arr[]={3,1,2};int n=sizeof(arr)/sizeof(arr[0]);
             vector<int> a;
             subsequences(0,a,arr,n);
            return 0;
 }