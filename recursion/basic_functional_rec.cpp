#include<bits/stdc++.h>
using namespace std;

void rev(int arr[],int l,int n){
       if(l>=n-l-1){return;}
       swap(arr[l],arr[n-1-l]);
       rev(arr,l+1,n);
}
bool palindrome(string &s,int l,int n){
        if(l>=n/2){return true;}
       if(s[l]!=s[n-l-1]){return false;}
       //if at any instance it return false rec is terminated , 
       //and for all function calls the value false is returned
       return palindrome(s,l+1,n);
}
int fibonacci(int n){
       if(n<=1){return n;}
       return fibonacci(n-1)+fibonacci(n-2);
}
int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
             
             int arr[]={1,4,2,9,3};
             int n=sizeof(arr)/sizeof(arr[0]);
             rev(arr,0,n);
             for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
             cout<<"\n";
             string s;cin>>s;int len=s.size();
             cout<<palindrome(s,0,len)<<"\n";
             cout<<fibonacci(11);
            return 0;
 }