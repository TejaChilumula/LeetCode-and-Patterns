class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // The Basic Math we can follow
        /* maxVal = 2powMaxBit - 1 always have the max no of set bits
            so TotalXOR ^ maxVal --- will always be maximum we can achieve
            - because its the maxval we can go, so it will have most of bits 1 XOR
            with the totalXOR ,if any bits are 0 will be fliped to 1
            XOR rule A^B = C, A = B^C
            XOR ^ k = maxVal , cause it wont exceed this
            XOR^maxVal = k, inverse rule
        */

        int maxVal = (1<<maximumBit) - 1;
        int XOR = 0;
        for(auto num : nums) XOR ^= num;

        int n = nums.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            
            int k = XOR ^ maxVal;
            res[i] = k;

            XOR ^= nums[n-1-i];
        }
        return res;
    }
};