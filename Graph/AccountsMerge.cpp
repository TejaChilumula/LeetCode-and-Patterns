class DisjointSet{
    private:
        vector<int> parent;
        vector<int> size;
    
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);

            for(int i=0;i<n;i++)
                parent[i] = i;
        }

        int findParent(int x){
            if(parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        }

        void UnionFind(int x, int y){
            int parX = findParent(x);
            int parY = findParent(y);

            if(parX == parY) return;

            if(size[parY] > size[parX])
            {
                parent[parX] = parY;
                size[parY] += size[parX];
            }
            else{
                parent[parY] = parX;
                size[parX] += size[parY];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);

        // we need to store each email -> account no. then perform the union
        unordered_map<string, int> emailToInt;
        for(int i = 0; i<n ; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];

                if(emailToInt.find(email) == emailToInt.end())
                    emailToInt[email] = i;
                else
                    ds.UnionFind(i, emailToInt[email]);
            }
        }

        // then we have the emails -> int and DS ready then merged emails put at one place,
        // ***** Group by root parent - supreme parent

        unordered_map<int, set<string>> rootToEmails;

        for(auto it : emailToInt){
            int accntIdx = it.second;

            int SupremeParent = ds.findParent(accntIdx);

            rootToEmails[SupremeParent].insert(it.first);
        }

        // then we have all the emails rooted correctly to the supreme parent
        // Need to build up the result, adding the name at start

        vector<vector<string>> res;

        for(auto it : rootToEmails){
            vector<string> merged;
            int accntIdx = it.first;
            merged.push_back(accounts[accntIdx][0]);
            
            for(auto& email : it.second)
                merged.push_back(email);
            
            res.push_back(merged);
        }

        return res;
    }
};