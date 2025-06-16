class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        /*map<int, vector<int>> mp;
        int n = arr.size();

        for(auto num : arr){
            int c = __builtin_popcount(num);

            mp[c].push_back(num);
        }

        vector<int>res;

        for(auto entry : mp){
            sort(entry.second.begin(), entry.second.end());
            res.insert(res.end(), entry.second.begin(), entry.second.end());
        }
        return res;
        */

        /* We can also write using the custom SORT operator */

        sort(arr.begin(), arr.end(), [](int a, int b){
            int c1 = __builtin_popcount(a);
            int c2 = __builtin_popcount(b);

            return (c1 == c2) ? a < b : c1 < c2;
        });

        return arr;


    }
};