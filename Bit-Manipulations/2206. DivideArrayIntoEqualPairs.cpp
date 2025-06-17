class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // If we can make n pairs then there are n - element pairs and each pair's (ele ^ ele) = 0, 
        /* so total XOR should be 0 in that sense we have for every ele we have canceled each

        int XOR = 0;
        for(auto num : nums) XOR ^= num;

        return XOR == 0 ? true : false; */

        // The above code wont work for [1,2,5,6] , no of bits will equal and cancel out,

        // we can use the bitset to trigger if we seen a bit or not, at the end if any of the bit set then no matching
        // element found for the bit position and no pair can form

        bitset<1001> bits;


        for(auto num : nums){
            bits[num] = !bits[num];
        }

        for(int i=0;i<1001;i++) {
            cout<<bits[i]<<" "; if(bits[i]) return false;
        }
        return true;

    }
};