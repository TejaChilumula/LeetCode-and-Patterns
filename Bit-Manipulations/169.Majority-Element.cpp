class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());

        for(int i=1;i<nums.size();i++){
            int c = 0;
            while(i<nums.size() && nums[i-1] == nums[i]) {
                c++;
                i++;}
            
            if(c >= nums.size()/2) return nums[i-1];
            
        }
        return 0;
    }
    // Optimized approach using Boyer-Moore Voting Algorithm

    /* this approach helps to solve in O(n) times*/

    int majorityElementOptimized(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }

    // Bit Manipulation Approach
    // This approach counts the number of 1s in each bit position across all numbers
    // and determines if that bit should be set in the majority element.
    // Time Complexity: O(n * 32) = O(n)
    // Space Complexity: O(1)
    // where n is the number of elements in the input array.
    // This is efficient for 32-bit integers.
    // Note: This approach assumes that the input numbers are 32-bit integers.

    int majorityElementBitManipulation(vector<int>& nums) {
        int majority = 0;
        for(int i = 0; i < 32; i++) {
            int count = 0;
            for(int num : nums) {
                if((num >> i) & 1) count++;
            }
            if(count > nums.size() / 2) {
                majority |= (1 << i);
            }
        }
        return majority;
    }
    
};