    //Rachit Garg
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
 

int knapsack(int wt[],int val[],int w, int n){
    if(n==0 || w==0){return 0;}

    if(wt[n-1]<=w){
        return max((val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }
}

        
    int main() {
    #ifndef ONLINE_JUDGE    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w=7;
    cout<<knapsack(wt,val,w-5,3)<<endl;
    cout<<knapsack(wt,val,w,3)<<endl;
    cout<<knapsack(wt,val,w,2)<<endl;
    cout<<knapsack(wt,val,w,1)<<endl;



}
  