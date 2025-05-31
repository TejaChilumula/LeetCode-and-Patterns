class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        // Need to find the powerset and then XOR sum of all the sets individually and sum up
        int n = nums.size();
        int total_sum = 0;
        vector<vector<int>> sets;
        for(int i =0; i< pow(2,n);i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    sum = sum ^ nums[j];
                }
            }
            total_sum += sum;
        }
        
        return total_sum;

        // Very Very Interesting method..
        /*
         for n we will get pow(2,n) substes, i n = 3 we get 8 subsets
            , each bit will contribute to half of the subsets , take | not take

            so what we need is --- 
                1. Whether the bit present in atleast a no or not
                2. then multiply each bit ( OR of all ) * pow(2, n-1); 
        */

        int total_OR = 0;
        for(int i=0;i<nums.size();i++){
            // we will get all the set bits
            total_OR |= nums[i];
        }
        return total_OR * (1 << n-1);
    }
};