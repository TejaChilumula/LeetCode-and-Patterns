class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // do we need pq here ? No !
        /* Because you dont know from the chepeast route you will reach the dest in k strps or not
        Normal queue works fine here, we need the best way within k stops so greedy works good*/

        queue<pair<int, pair<int,int>>> q;
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());
        vector<int> dist(n,INT_MAX);

        for(auto flight : flights) adj[flight[0]].push_back({flight[1], flight[2]});

        q.push({0,{src, 0}});

        while(!q.empty()){
            auto [min_dist, p] = q.front();
            auto [u, steps] = p;
            q.pop();

            if(steps > k ) continue;

            for(auto [v, wt] : adj[u]){
                if(min_dist + wt < dist[v] && steps <= k){
                    dist[v] = min_dist + wt;
                    q.push({dist[v], {v, steps+1}});
                }
            }
        }

        return dist[dst] == INT_MAX ?  -1 : dist[dst];

    }
};