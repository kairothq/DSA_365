pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    std:: sort(arr, arr+n);
    int ans=std::lower_bound(arr, arr+n,x)-arr;
    int Ceil = (ans < n) ? arr[ans] : -1; // checking if its not greater than all elements
    int low=0, high=n-1;
    int Floor =-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]==x){
            Floor=arr[mid];
            break;
        }
        else if(arr[mid]>x) high=mid-1;
        else{
            Floor=arr[mid];
            low=mid+1;
        }
    }
    return {Floor, Ceil};
};