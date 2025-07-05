class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //create a freq_map of key(product) -- Here, we get the same product with multiple combinations
        // *** TRICK ****And no doubt one element involves in 2 combinations giving same product - (unq elements)
        // Once we have freq map, for each product if the val is > 2 then we need all combinations of it
        // n*(n-1)/2 combinations -- o(n^2) --- but feasible, because of n <= 1000 constraint
        int ans = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product = nums[i]*nums[j];
                mp[product]++;
                
            }
        }

        for(auto entry : mp){
            int count = entry.second;
            if(count == 2) ans += 8;
            if(count > 2) ans += ((count*(count-1))/2)*8;
        }

        return ans;

    }
};