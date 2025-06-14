class Solution {
public:
    int MOD = 1e9 + 7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        int ans = 0;

        for (auto& edge : edges) {
            adj[edge[0]-1].push_back({edge[1]-1, edge[2]}); // edge[0] is richer than edge[1]
            adj[edge[1]-1].push_back({edge[0]-1, edge[2]});
        }

        vector<int> dist(n,INT_MAX);
        dist[n-1]=0;
        dijkstra(adj,n,dist);
        vector<int> dp(n,-1);

        return dfs(0,n-1, dist, dp, adj);

    }

    int dfs(int u, int tar, vector<int> &dist, vector<int> &dp, vector<vector<pair<int,int>>> &adj){
        if(u == tar) return 1;
        if(dp[u] != -1) return dp[u];
        long long ways = 0;
        for(auto [v,wt] : adj[u]){
            if(dist[u] > dist[v]){
                ways = (ways + dfs(v, tar, dist, dp, adj))%MOD;
            }
        }
        return dp[u] = ways;
        /*  
            - tabulation is tricky,
            we can go from the last node 5, keeping dp[5] = 1 and dist = [INT_MAX]
            we need to sort based on the distances either asc or desc
            ******** we need to sort ************
             Because we can have the adj_v at same level where it satisfies condn but
             its DP haven't computed so, if we sort it always get dist[u] > dist[v]

             manually set dist[1] = INT_MAX
                sort by dist descending
                dp[1] = 1
                for u in order:
                    for v in adj[u]:
                        if dist[v] < dist[u]:
                            dp[v] += dp[u]
        */
    }

    void dijkstra( vector<vector<pair<int, int>>> &adj, int n,vector<int> &ans){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,n-1});

        while(!pq.empty()){
            auto [cur_wt, u] = pq.top(); pq.pop();

            if(cur_wt > ans[u]) continue;

            for(auto [v, wt] : adj[u]){
                if(ans[u] != INT_MAX && ans[u] + wt < ans[v]){
                    ans[v] = ans[u] + wt;
                    pq.push({ans[v], v});
                }
            }
        }
    }
};