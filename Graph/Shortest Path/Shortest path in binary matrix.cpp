class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // so we need to push things in min heap and with the distance and the node 

        // then check the neighbours of that and check if the distance of them = dist already+ weight
        // make two arrays which store the values like +1,-1 of rows and column to find the adj cells
        // make a condition that if its 1 then don't do +1 otherwise or else do 
        // finally ig we just need to reach the last value 
        queue<pair<int, pair<int,int>>>q;
        int n= grid.size();
        int m= grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // No path if start or end is blocked
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        q.push({0, {0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int dis= it.first;
            int r=it.second.first;
            int c=it.second.second;
            int delr[]= {-1,-1,0,+1,+1,+1,0,-1};
            int delc[]= {0,+1,+1,+1,0,-1,-1,-1};
            if(r==n-1 && c==m-1) return dis+1;

            for(int i=0; i<8;i++) { // to get the index for finding all the adjacent cells  
                int nrow= r+ delr[i];
                int ncol= c+ delc[i];
                if(nrow>=0&& nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol]==0&& dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};