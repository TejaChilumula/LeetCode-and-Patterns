***********  Q3. Minimum Increments to Equalize Leaf Paths ****************

You are given an integer and an undirected tree rooted at node 0 with I nodes numbered from 0
to n - 1. This is represented by a 2D array (edges of length i - 1, where edges [1) = (un, va)
indicates an edge from node u to vI.
Each node has an associated cost given by cost {11), representing the cost to traverse that node.
The score of a path is defined as the sum of the costs of all nodes along the path.
Your goal is to make the scoles of all root-to-leaf paths equal by increasing the cost of any
number of nodes by any non-negative amount.
Return the minimum number of nodes whose cost must be increased to make all root-to-leaf path scores equal.

Example 1:
Input: n = 3, edges = [[0,1], [0,2], cost = [2,1,3]

                    0 (2)
               (1) 1 .     2 (3)

               Path 0->1 = 3 . - this needs 1 increment of 2 units 
               Path 0->2 = 5
               Ans :- 1


        Intuition : We can findout all the paths and get max_path and try to adjust all the other leaf nodes units.
                so ans is count(leaf_nodes) < max_path ( these many nodes need increment )

                what if some leafs share the common parent ?, instead of incrementing the leafs all we can increment this common parent 

                  0
                /    \
            1 .         2
        
           /  \       /    \              ---------> Here Instead of updating the 4 and 5, we can update the 1 itself so its changes can be absorbed by the leaf's
        4       5     7     8
     (4)        (4)   (7)     \
    /   \                      9                      ---------> What if deep down leaf's share the same ancestor where an update can impact all the leaf's , more than 2 ?
  /\      /\                     \     
/\ /\    /\ /\                   10 (11)                                    In this deep case we can update the 1 parent of parent so that instead of 4 and 5
(4) (4) . (4) (4)                                                           ---- So, we the ancestor from whose the 
                                                                                            minPath == maxPath (from ancestor -> leaf) 
                                                                                             cost to reach (ancestor) + maxPath < total_max_path --- then it is the top ancestor need update

                                                                                             ---- IMPPP ---- cause both min and max paths are same here means all leaf path's are same
                                                                                             and its not being the total_max_path -- then this is the most top ancestor needs to update.

                                                                                             First, we need 
                                                                                                    1. minPath, maxPath of each - from its all leaf's
                                                                                                    2. We need cost to reach node - cost[node]


/*

    - we need 2 DFS's 
            - to find out the min and max leaf dist from each node
            - find out how many increments needed.
                                                                                                    */

class Solution {
public:
using ll = long long;

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &maxi, vector<ll> &minn, vector<ll> &cost ){

        maxi[u] = LLONG_MAX, minn[u] = LLONG_MIN;

        bool leaf = true;

        for(auto &v : adj[u]){
            if(v == p) continue;
            leaf = false;

            dfs(v,u,adj,maxi,minn,cost);

            maxi[u] = max(maxi[u], (ll) cost[x] + maxi[v]);
            minn[u] = min(minn[u], (ll) cost[x] + minn[v]);
        }
        if(leaf){
            maxi[x] = minn[x] = cost[x];
        }
}

void dfs(int u, int p, vector<vector<int>> &adj, vector<ll> &maxi, vector<ll> &minn, vector<ll> &cost , ll total_cost_from_root){
    if(maxi[u] == minn[u] && maxi[u] + cst) return 0; // The node's path leaf have max(leaf_path) so no incre
    if(maxi[u] == minn[u]) return 1;   /// we will return at the largest ancestor where we can update.

    total_cost_from_root += cost[u];
    int count = 0;

    for(auto &v : adj[u]){
        if(v == p) continue;
        count += dfs2(v,x,adj,maxi,minn,cost,total_cost_from_root);
    }

    return count;

}

int minInc(vector<int> &cost, vector<vector<int>> &edges, int n){
    vector<vector<int>> adj(n);
    vector<ll> maxi(n), minn(n);

    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }


    dfs(0, -1, adj, maxi, minn, cost);
    return dfs2(0, -1, adj, maxi, minn, cost, 0);
    
}

// 2nd Approach --- ChatGPT approach

/*
    so we wont count the min and maxi at each level, all we only care is how many childrens going to leaf are lesser than maxi in that path ( **** not Maxipath )
     - we do this at each node,
        - At a node, check all its childPath's and 
            count how many are only lesser** than local maxima and update ans++;
             ****** we dont take equals cause we can inc parent ( only 1)
             Bottom - Up
             

                                0(2)
                                /   \
                            1(1)   2(10)
                            /   \
                        3(1)  4(1)

                        go down

                        at 3 -> we return 1
                        at 4 -> 1

                        at 1, we got ChildPath[1,1];
                          max(ChildPath) = 1
                          no less paths - no ans++;
                          return 1 + 1 = 2

                        at 2 - ret 10

                        at 0 - ChildPath[2,10]
                        2 < 10 - ans++

                        ans = 1

                        thats it!

*/

// here we only care of maxPath, no minPath required !

ll ans = 0;
void dfs(u, p, adj, cost){

    vector<int> childPaths;

    for(auto &v : adj[u]){
        if(v == p) continue;

        int pathtoleaf = dfs(v,u,adj,cost);
        childPath.push_back(pathtoleaf);
    }

    int maxPath_in_this_subtree = *max_element(childPath.begin(), childPath.end());

    for(auto c: childPath){
        if(c < maxPath_in_this_subtree) ans++;
    }

    return cost[u] + maxPath_in_this_subtree;
}



int main(){
    vector<vector<int>> adj(n);

    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }


    dfs(0, -1, adj, cost);
    return ans;

}

******************* Problem - 2 : Inverse Coin Change **********************

class Solution {
public:
    vector<int> findCoins (vector<int>& numWays) {
    int n = numWays.size();
    vector<int> coins;
    vector<int> ways_prev(n+1, 0); ways_prev[0] = 1;

    for(int i = 0; i < n; i++) {
        int x = numWays[i] - ways_prev[i+1];

        if(x > 1 || x < 0) return {}; 
        // we have to get numWays[i] - 1 ways with prev coins, so if it is greater than 1, we cant make
        if (x == 0) continue;

        coins. push_back(i+1);
        // IMP - this way we add for every amount >= i+1, we now have extra ways to
        // form it by using this new coin, 
        //if we add 3 coin, if Ways[5] += ways[5-3]; 
        // This way we add how many ways to can add, so that many ways 3 can add to 2 
        for(int j = i+1; j <= n; j++) {
            ways_prev [j] += ways_prev[j-(i+1)];
        }
    }
        return coins;
    }

};


*********** Approach - 2 *************
//This Problem can also done by using the 
/*
    1. CoinChange at each idx, whether with the computed coins it can be possible or not
    2. and 
    the noofWays we compute using the existing coins
      - 1. if noWays == numWays[denomination]-1;  // means we got all combinations and one more
      with tha denomination coin
            lets say   we have NoWays[5] = 4, we got it by 2+3, 1+1+1+2, 1+1+3 --> 3ways
              - then we want one more, can be possible by its own coin - 5
                    --- so, we need that coin and we add it to coin_bag, this way we add coins
*/

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;
        vector<int> coins;
        for(int i=0;i<numWays.size();i++){
            int noWays = coinChange(coins, i+1, 0);
            cout<<"no of ways of"<<i+1<<"is "<<noWays<<endl;
            if(noWays == numWays[i]-1) {
                cout<<"coin added<"<<i+1<<endl;
                    coins.push_back(i+1);
            }
            if((numWays[i] == 0 && noWays > 0) || numWays[i] > noWays+1) return {};
        }
        return coins;
    }
    int coinChange(vector<int> &coins, int tar, int i){
        if(coins.size() == 0) return 0;

        vector<int> dp(tar+1,0);

        dp[0] = 1;

        for(int coin : coins){
            for(int i=coin;i<= tar;i++){
                
                dp[i] += dp[i - coin];
            }
        }

        return dp[tar];
        
    }
    int coinChange2(vector<int> &coins, int tar, int i){
        if(coins.size() == 0) return 0;
        if(i >= coins.size() || tar < 0) return 0;
        if(tar == 0 ) return 1;
        int take = 0;
            take = coinChange(coins, tar - coins[i], i);

        int not_take = coinChange(coins, tar, i+1);

        return take + not_take;
    }
};