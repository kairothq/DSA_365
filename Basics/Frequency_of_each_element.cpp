//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        unordered_map<int, int> freqMap;
        
        // Count the frequency of elements in the array
        for(int i = 0; i < N; i++) {
            if(arr[i] <= N) {
                freqMap[arr[i]]++;
            }
        }
        
        // Update the array with the frequency of elements from 1 to N
        for(int i = 1; i <= N; i++) {
            if(freqMap.find(i) != freqMap.end()) {
                arr[i-1] = freqMap[i];
            } else {
                arr[i-1] = 0;
            }
        }
    }
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends