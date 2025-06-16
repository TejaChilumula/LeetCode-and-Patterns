class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // combination + bitwise AND of all the nums in combination
        /*
         ********** Too slow ***************

         2044: Max 16 elements → 2^16 = 65,536 subsets → brute-force okay
         2275: Up to 100,000 elements → 2^100000 subsets → completely infeasible

        int ans=INT_MIN, n = candidates.size();
        for(int mask=0;mask< (1<<n);mask++){
            int curAND = INT_MAX, combination_nums = 0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) // checking that bit on or not
                {
                    curAND &= candidates[i];
                    combination_nums++;
                }
            }
            if(curAND > 0) ans = max(ans, combination_nums);

        }
        return ans;
        */


        // what we can do is that, we can calculate the col-wise bits
        /* which ever col has max bits that's the max no of elements we can consider
                0 0 1 0
                1 0 1 0
                0 1 0 0
                1 1 1 1
                0 0 0 1
                1 0 0 1. -> we can take 3 numbers into consideration because max(1's) col is 3
        */
        int ans = 0;
        for(int i=0;i<32;i++){
            int bit_count = 0;
            for(auto it : candidates){
                if((it>>i) & 1) bit_count++;
            }
            ans = max(bit_count, ans);
        }
        return ans;
    }

};