//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        int ans = 0;
        int m =n; 
        while(n){
            int x = n%10;
            ans+= std:: pow(x,3);
            n/=10;
        }
        if(ans==m){
            return "true";
        }
        else{
            return "false";
        }
    }
};

// 362 
// 362%10 = 2
// 8
// 36 
// 36%10 = 6, 36/10==3 

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends