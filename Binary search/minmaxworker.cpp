bool minmaxwork(ll a[],ll m,ll k,ll n){
        ll sum=0;ll workerused=1;
        fo(i,n){
            if(sum + a[i] <= m){sum += a[i];}
            else{sum=a[i];workerused++;}
        }
        return workerused<=k;   
    }

//BS on ANSWER in posssible range , just check if fort any x it is possible or not
     ll n,k;cin>>n>>k;
        ll a[n];ll sumarr=0;
        fo(i,n){cin>>a[i];sumarr += a[i];}
        ll l=1, r= 1e9*n;ll ans=1;
        while(l<r){
            ll m= l + (r-l)/2;
            debug(minmaxwork(a,m,k,n));
            if(minmaxwork(a,m,k,n)){r=m;}
            else{l=m+1;}
        }
        
        cout<<r<<endl;