class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        /*
         - bad - 
                j - i != arr[j] - arr[i]
            can rewrite as 
                nums[i] - i != nums[j] - j
            
            so, then good ?
                nums[i] - i = nums[j] - j
                
            Then, at each idx find out ( nums[i] - i )
               then check whether this diff happend past, so those are good pairs
                 - how many good pairs --- 1 * [ previous occurance ]

                 total += 1*freq[diff] // cause 1 person can mingle with that many previous 
                 in same good pairs
        */
        map<int, int> mp;
        long long good_pairs = 0;
        
        for(int i=0;i<nums.size();i++){
            int diff = nums[i]-i;

            good_pairs += mp[diff];
            mp[diff]++;
        }

        // we got the good pairs and then we need the bad pairs which is
        // bad_pairs = total_pairs - good_pairs
        
        long long n = nums.size();
        long long total_pairs = n*(n-1)/2;

        return total_pairs - good_pairs;



        /// We can also do it in the other way !!! ///

        /* count the bad pairs it self

        for(int i=0;i<nums.size();i++){
            int diff = i - nums[i];

            bad_pairs += i - freq[diff]; // How ?
            /*
                - till i - 1, we have pairs, 
                we got the freq[diff] from 0 - i-1 pairs, 
                so these are all matching means - good_pairs from 0 - i-1 of same diff of i!
                if we need bad pairs then i - good_pairs ( i.e. - i - freq[diff])

                bad pair means it should not equal and how many we can form ?

                     - so for each good pair if we have 2 - 2
                     then you got one more diff - 2
                      so, now how many pairs you can form with existing 2= 

                       ***** 1*freq[diff] ***** , i.e - (1,3), (2,3) , if 3 is new one

                       total += 1*freq[diff]
                    
            
 
            freq[diff]++;
        }*/


    }
};