//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int f(int day, int last, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(day==0){ // this all just comes under base case
            int maxi=0;
            for(int task=0;task<3; task++){
                if(task!=last){
                    maxi= max(maxi, arr[0][task]); 
    // this means that last task happened on last day which is day 1 and 
    // now on day 0, task only other than last should happen and which one 
    // of those left task is max. Also this is the base case  
                }
            }
            return maxi;
        }
        
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){ // means haven't did task before then can do this task
            int point = arr[day][task]+ f(day-1, task, arr,dp);
             maxi = max(maxi, point);
// this above means ki you have performed task on this day and now also need
// to calculate the last days values we will say that today we performed task 
// and now what will be on last day.. And then add them all and keep taking maxi
        }
    }
    return dp[day][last]=maxi;
}
    
int maximumPoints(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(n-1, 3, arr,dp);
    }


    int maximumPoints(vector<vector<int>>& arr, int n)
        vector<vector<int>> dp(n, vector<int>(4,-1)); 
        // base case
        dp[0][0]=max(arr[0][1], arr[0][2]); // means its the last day and in a day before that we had performed task 0. (going bottom up, therefore checking as no day before this, but last day is day after it in bottom up)
        // So in this we are left with task 1 ,2 and for this question since we are req to maximise therefore will take the max task value out of left items 
        dp[0][1]= max(arr[0][0], arr[0][2]);
        dp[0][2]= max(arr[0][0], arr[0][1]);
        dp[0][3]= max(arr[0][0], max(arr[0][1], arr[0][2])); // if the case where there is just a single day, so no day before it, therefore none of them is used. So we take max of all 1,2,3     
    
        
        // made loop for both changing variables
        for(int day=1; day<n;day++){
            for(int last=0; last<4; last++){
                // this is what we wanted to calc therefore gn 0 initial value
                dp[day][last]=0;
                int maxi=0;
                
                // writing the same thing by observing from above (i.e. memoisation)
                for (int task=0; task<3; task++){
                    if(task!=last){
                        // bottom up approach therefore coming from down 0 to 3
                        int point = arr[day][task] + dp[day-1][task];
                        // rather than storing it in maxi, directly stored in dp
                        dp[day][last]=max(dp[day][last], point);
                    }
                }
                
            }
        }
        return dp[n-1][3];
        
    

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends