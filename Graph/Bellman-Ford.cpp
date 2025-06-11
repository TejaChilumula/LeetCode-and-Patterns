// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Rules
        /*
            - 1) any node can find its shortest path from src at most V-1 times
                    - 1 -> 2 -> 3 -> 4
                    we have edges list like 3->4, 2->3, 1->2
                    to get 4 we need 3 but we dont have
                       for 3 we need 2 ( dont have )
                       for 2 we need 1 (we have) - 1st iteration
                    iterations 2 - we get 3 val, 3, we get 4 val at most 
                        ---- N-1 = 3 iterations
            - 2) If there is a -ve cycle even after V-1 times still some V's will update its 
                    dist. then its a cycle its still on updating then we directly return -1
        */
        int max_val = 1e8;
        vector<int> dist(V,max_val);
        dist[src] = 0;
        for(int i=0;i<V;i++){
            
            for(auto edge : edges){
                int u = edge[0], v = edge[1], wt = edge[2];
                
                if(dist[u] != max_val && dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }    
        }
        
        for(auto edge : edges){
            int u = edge[0], v = edge[1], wt = edge[2];
                
            if(dist[u] != max_val && dist[v] > dist[u] + wt){
                return {-1};
            }
        }
        return dist;
    }
};
