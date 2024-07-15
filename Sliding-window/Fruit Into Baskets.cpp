//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
    int l=0,r=0;
    int len=0;
    int n= fruits.size();
    map<int,int> mpp;
    while(r<n){
        mpp[fruits[r]]++;
            // means its size is more than 2 
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                mpp.erase(fruits[l]);
                }
                l++;
            }
        len=max(len, r-l+1);
        r++;
        }
    return len;
    }
    // so this is like we are trying to find the max length subarray 
    // with two type of elements 
 // so what we are tying is that it should not be more than 2 type
 // and increase the type no if other than gn type and move the l 
 // until one of the type ends 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends