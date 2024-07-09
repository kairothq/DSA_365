void symmetry(int n) {
    for(int i=1;i<=n;i++){
        // stars
        for(int j=1;j<=i;j++){
        cout<<"* ";
        }
        //spaces
        for(int j=2*(n-i);j>0;j--){
            cout<<" ";
        }
        // stars
        for(int j=1;j<=i;j++){
        cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        // stars
        for(int j=1;j<=i;j++){
        cout<<"* ";
        }
        //spaces
        for(int j=2*(n-i);j>0;j--){
            cout<<" ";
        }
        // stars
        for(int j=1;j<=i;j++){
        cout<<"* ";
        }
        cout<<endl;
}
// this is the code for pattern like 

    // 1,0,0,0,0,1
    // 1,1,0,0,1,1 n=3
    // 1,1,1,1,1,1
    // 1,1,0,0,1,1 
    // 1,0,0,0,0,1


    
    // 1,0,0,0,0,0,0,1
    // 1,1,0,0,0,0,1,1
    // 1,1,1,0,0,1,1,1 n=4
    // 1,1,1,1,1,1,1,1
    // 1,1,1,0,0,1,1,1
    // 1,1,0,0,0,0,1,1
    // 1,0,0,0,0,0,0,1


// where 1 represent * and 0 represent space