class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bitset<101> a;
        bitset<101> b;
        bitset<101> c;

        for(int i=0;i<nums1.size();i++){
            a[nums1[i]] = 1;
        }
        for(int i=0;i<nums2.size();i++){
            b[nums2[i]] = 1;
        }
        for(int i=0;i<nums3.size();i++){
            c[nums3[i]] = 1;
        }


        vector<int> ans;

        for(int i=0;i<=100;i++){
            int cnt = 0;
            if(a[i]) cnt++;
            if(b[i]) cnt++;
            if(c[i]) cnt++;
            if(cnt >= 2) ans.push_back(i);
        }
        return ans;

        // The smart and the tricy way

        // In the vector<int> seen -> 
        /* We make 
        - nums1[ele] |= 1
        - nums2[ele] |= 2 // Why we wont take 3 , it will take 2 bits so 
         we can differentiate whether it appeared in 1 and 2 or 3
        - nums3[ele] |= 4

        so OR will keep all the bits ON
         so if an element appear in nums1 & nums2 then
            seen[ele] = 0
            seen[ele] = 0001 -> when nums1 have it
            seen[ele] = 0011 -> when both nums1 & nums2 have it

            seen[ele] = 0100 -> when nums3 have it

            if an ele appears in nums1, nums3 
             then seen[ele] = 0 1 0 1

             so it will be checked by ((seen[ele] & 1) && (seen[ele] && 4))

             so this way we will check
        */

        vector<int> seen(101);

        for(int i=0;i<101;i++){
            seen[i] |= 1;
            seen[i] |= 2;
            seen[i] |= 4;
            
            int setBitNo = seen[i]; 
            if((setBitNo & 1 && setBitNo & 2) ||
                (setBitNo & 2 && setBitNo & 4)||
                (setBitNo & 4 && setBitNo & 1))
        }

    
    }
};