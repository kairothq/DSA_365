//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOccurance(int arr[], int n, int x){
        int low=0, high=n-1;
        int first =-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x) {
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]>x){
                    high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }

    int lastOccurance(int arr[], int n, int x){
        int low=0, high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(x==arr[mid]) {
                last=mid;
                low=mid+1;
            }
            else if (arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return last;
    }	
	
int count(int arr[], int n, int x) {
    int m= firstOccurance(arr,n,x);
        if(m==-1) return 0; // even here it is very important to write(x==-1 rather than x=-1 if checking)
    int p= lastOccurance(arr,n,x);
    return p-m+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends