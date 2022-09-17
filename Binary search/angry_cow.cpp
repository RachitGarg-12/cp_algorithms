 //predicate function
 bool possible(ll mid, ll cow,ll h[],ll n){
          ll present= h[0]+2*mid;
          f1(i,n-1){
              if(h[i]>present){ present = h[i]+2*mid;cow--;}
                if(cow<=0){return false;}
            }
        return true;
}


int main() {
           ll n,k;cin>>n>>k;
           ll hay[n];
           fo(i,n){cin>>hay[i];}
           sort(hay,hay+n);
           ll range = hay[n-1]-hay[0];
           if(range<=k){cout<<0<<endl;}
           else{
              ll div = (range%k==0) ? range/k : (range/k) +1 ;
              ll maxr = ((div-1)%2==0) ? (div-1)/2 : ((div-1)/2)+1 ;
              ll low=0;ll high= maxr;ll ans=0;
              // we want first true
              while(low <= high){
                ll mid = low + (high-low)/2;
                if(possible(mid,k,hay,n)){ans = mid ;high = mid-1;}
                else{ low = mid+1;}
                }
               cout<<ans<<endl;
           }


            
            return 0;
        }