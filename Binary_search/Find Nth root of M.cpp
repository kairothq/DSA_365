//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // so just like square root one
	    int low=0, high=m;
	    int ans=-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
            long long midPower = 1;
            for (int i = 0; i < n; ++i) {
                midPower *= mid;
                if (midPower > m) break; // Optimization to stop early if midPower exceeds m
            }
	        if(midPower<=m){
	            low=mid+1;
	            if(midPower==m){
	                ans=mid;
	            }
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return ans;
	}  
};

// so pow(x,n) gives float and can could cause problem in precission
// when using it, midPower is the soln since it calculates in int

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends