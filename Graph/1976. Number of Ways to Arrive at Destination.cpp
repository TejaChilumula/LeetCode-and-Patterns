class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // tricky and we need to know this wont be work with just finding the different ways to reach dis
        /*
            - we have to find each nodes, no of ways to reach so that we can accumulate those to reach the dis
                **** we need all the nodes ways[]
        */

        int mod = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<int> ways(n,0);
        ways[0] = 1; // we start from here
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;

        // adj vec
        vector<vector<pair<int,int>>> adj(n);

        for(auto road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }


        pq.push({0, 0});

        while(!pq.empty()){
            auto [cur_dis, u] = pq.top(); pq.pop();

            if(cur_dis > dist[u]) continue;

            for(auto [v, wt] : adj[u]){
                long long v_dis = cur_dis + wt;
                if(v_dis < dist[v]){
                    // we came here first time with this short dis
                    dist[v] = v_dis;
                    pq.push({v_dis,v});
                    ways[v] = ways[u]; // we just reach in u ways
                }
                else if (v_dis == dist[v]) ways[v] = (ways[v] + ways[u])%mod;
            }
        }
        return ways[n-1];
    }
};