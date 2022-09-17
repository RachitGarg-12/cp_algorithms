#include<bits/stdc++.h>
using namespace std;
void subsequences(int i,vector<int> &a,int sum,int arr[],int n,int target){
    if(i>=n){
        if(sum==target){
        for(auto i:a){cout<<i<<" ";}
        if(a.size()==0){cout<<"{}";}
        cout<<"\n";}return;
    }
    a.push_back(arr[i]);
    subsequences(i+1,a,sum+arr[i],arr,n,target);
    a.pop_back();
    subsequences(i+1,a,sum,arr,n,target);
}

int num_subsequences(int i,int sum,int arr[],int n,int target){
    if(sum>target){return 0;} //if arr only has positive nums

    if(i>=n){
        if(sum==target){return 1;}
        else{return 0;}
    }
    int l=num_subsequences(i+1,sum+arr[i],arr,n,target);
    int r=num_subsequences(i+1,sum,arr,n,target);
    return l+r;
}
bool any_subsequence(int i,vector<int> &a,int sum,int arr[],int n,int target){
    if(i>=n){
        if(sum==target){
        for(auto i:a){cout<<i<<" ";}
        if(a.size()==0){cout<<"{}";}
        cout<<"\n";return true;}
        else{return false;}
    }
    a.push_back(arr[i]);
    if(any_subsequence(i+1,a,sum+arr[i],arr,n,target)){return true;}
    a.pop_back();
    if(any_subsequence(i+1,a,sum,arr,n,target)){return true;}

    return false;
}

int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
             
             int arr[]={3,2,1};int n=sizeof(arr)/sizeof(arr[0]);
             vector<int> a;
             subsequences(0,a,0,arr,n,3);cout<<endl;
             vector<int> b;
             any_subsequence(0,b,0,arr,n,3);cout<<endl;
             cout<<num_subsequences(0,0,arr,n,3);
            return 0;
 }