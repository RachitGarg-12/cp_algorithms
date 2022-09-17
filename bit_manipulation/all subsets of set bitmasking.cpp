#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void  printbinary(ll n){
    ll p= (ll)log2(n);
    for(ll i=p;i>=0;i--){
        cout<< ((n>>i)&1);
    }
    cout<<endl;
}

vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> all_subsets;
        int l= (1<<n);
        for(int i=0;i<l;i++){              // 0<=i<= l-1
            vector<int> subset;
            for(int j=0;j<n;j++){
                 if((i & (1<<j)) !=0 ){subset.push_back(arr[j]);}
            }
           all_subsets.push_back(subset);
        }
        
        return all_subsets;
    }


int main(){

    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
       
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];  
        }
       
       auto all_subsets = subsets(arr);
       for(auto x:all_subsets){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
       }       


    return 0; 
}