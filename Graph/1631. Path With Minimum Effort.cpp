class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        int n = heights.size();
        int m = heights[0].size();

        pq.push({0,0,0});

        vector<vector<int>> dist(n,vector<int>(m, INT_MAX));

        dist[0][0] = 0;

        vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top[0], r = top[1], c = top[2]; 

            if(r == n-1 && c == m-1) return d;

            for(int i=0;i<4;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int maxi = max(d, abs(heights[r][c] - heights[nr][nc]));
                    if(maxi < dist[nr][nc])
                    {
                        dist[nr][nc] = maxi;
                        pq.push({maxi, nr, nc});
                    }
                        
                }
            }

        }

        return 0;
    }
};