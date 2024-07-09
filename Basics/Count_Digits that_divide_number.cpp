//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int y = N;
        int ans=0;
        while(y>0){
            int x = y%10;
            if(x!=0&&N%x==0){
                ans++;
            }
            y/=10;
        }

        return ans;
        // 2122 /10 = 212 /10 = 21/10 = 2 /10 
        // 2122 % 10 = 2 
        // 212%10 = 2
        
        // 12 % 10 = 2; 
        // 1 
        // 26435  
        // 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends


// Even this little question is too much to handle for me because of edge cases