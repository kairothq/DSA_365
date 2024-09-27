class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0, {0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0]=0;
        int dr[]={0,+1,0,-1};
        int dc[]={+1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int min_effort= it.first;
            int r=it.second.first;
            int c=it.second.second;
            if (r == n - 1 && c == m - 1)
                return min_effort;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int new_effort = max(min_effort, abs(heights[nr][nc]-heights[r][c]));
                    if(new_effort< effort[nr][nc]){
                        effort[nr][nc]=new_effort;
                        pq.push({new_effort,{nr,nc}});
                    }
                }
        }
        }
        return -1;
    }
};