double n;cin>>n;
        const double eps=1e-8;
        double l=0,r=n;
        while(r-l>eps){
            double mid =(r+l+eps)/2;
            if(mid*mid<=(double)n){l=mid;}
            else{r=mid-eps;}
        }
        
        cout<<l<<nl;