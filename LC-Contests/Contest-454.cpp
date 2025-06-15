***** Problem No. 1 *******

    - You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:

Combine all words in the string into a single camelCase string prefixed with '#'. 
A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.
Remove all characters that are not an English letter, except the first '#'.

Truncate the result to a maximum of 100 characters.
Return the tag after performing the actions on caption.

Example 1:

Input: caption = "Leetcode daily streak achieved"
Output: "#leetcodeDailyStreakAchieved"


 Solution Tricks:
    - Some times at the start may have " " spaces and also first firstword letter should be 
    lower, 
       - we can keep a flag as upper wntil we get next space, 
       - Once the first character done, change !Upper flag 

        class Solution {
    public:
    string generateTag(string caption) {
        string ans = "";
        ans += "#";
        bool Upper = false;
        int j=0;
        while(j < caption.size()){
            if(caption[j] == ' ') j++;
            else{
                ans += tolower(caption[j]);
                break;
            }
        }
        for(int i=j+1;i<caption.size();i++){
            if(ans.size() == 100) return ans;
            if(caption[i] == ' ') {
                Upper = true;
                continue;}
            if(Upper){
                Upper = false;
                ans += toupper(caption[i]);
            }
            else{
                ans+=tolower(caption[i]);
            }
            
        }
        return ans;
    }
};



********* Problem - 2 ***********

Q2. Count Special Triplets

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [6,3,6]

Output: 1

Explanation:

The only special triplet is (i, j, k) = (0, 1, 2), where:

nums[0] = 6, nums[1] = 3, nums[2] = 6
nums[0] = nums[1] * 2 = 3 * 2 = 6
nums[2] = nums[1] * 2 = 3 * 2 = 6


        - Brute Force 
         
         for every element from 2 to n-2

          iterate to its left to find the left match
          iterate through right to find the right match i.e. ( middle * middle )

          if we find then the no of possible subsets will be --- left * right

        - Optimal - Hash Maps 

         - We will be having the 2 prefix - 
                - prefix and suffix hashmaps -- which will give you the i and k for j ( middle element )

    
    SOLUTION:

        class Solution {
    public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;
        int n = nums.size();
        
        if (n < 3) return 0;
        
        unordered_map<int, int> suffixCount;
        for (int i = 2; i < n; i++) {
            suffixCount[nums[i]]++; /// initially the suffix of all elements leaving i, j ( 0, 1 ) are not there in suffix cause these are not suffix for any other elements
            // these ( 0, 1 ) wont be suffix for any other
        }
        
        long long ans = 0;
        unordered_map<int, int> prefixCount;
        
        for (int j = 1; j < n - 1; j++) {
            int target = nums[j] * 2;
            
            int leftCount = prefixCount.count(target) ? prefixCount[target] : 0; // we get no of elements === tar
            int rightCount = suffixCount.count(target) ? suffixCount[target] : 0; // // 
            
            ans = (ans + (long long)leftCount * rightCount) % MOD;
            
            // once we computer we need to move forward, so we add this to prefix so that it will be prefix to j+1 ... elements
            prefixCount[nums[j-1]]++;
            
            if (j + 1 < n) { // this wont be suffix going forward so remove from suffix
                suffixCount[nums[j+1]]--;
                if (suffixCount[nums[j+1]] == 0) {
                    suffixCount.erase(nums[j+1]);
                }
            }
        }
        
        return (int)ans;
    }
};


********** Problem-3 ************

You are given an integer array nums and an integer m.

Return the maximum product of the first and last elements of any subsequence of nums of size m.


Example 1:
Input: nums = [-1,-9,2,3,-2,-3,1], m = 1

Output: 81

Explanation:
The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.

Example 2:
Input: nums = [1,3,-5,5,6,-4], m = 3

Output: 20

Explanation:
The subsequence [-5, 6, -4] has the largest product of the first and last elements.

SOLUTION:

// Can you the Max Prodcut Subarray problem approach , cause it has -ve elements

 // we will keep , MIN_PREV, MAX_PREV so that we will be having the max and min ( -ves ) so far in dist m
 // we update it 
    and any of these 2 will give you the max 
      - If arr[j] is -ve and min_prev is -ve - then o/p give high positive
      - If arr[j] is +ve and max_prev is +ve then o/p will be high +ve 
        In this process we always maintain M min dist btwn i and j, Min_prev, or Max_prev might struck behind also

 - class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
    long long ans = LLONG_MIN;
        int n = nums.size();
        vector<long long> inpt(nums.begin(), nums.end());

        long long max_prev = LLONG_MIN;
        long long min_prev = LLONG_MAX;

        for(int i=m-1;i<n;i++){
            int j = i - (m - 1);
            max_prev = max(max_prev, inpt[j]);
            min_prev = min(min_prev, inpt[j]);

            long long  prod1 = max(ans, max_prev*inpt[i]);
            long long  prod2 = max(ans, min_prev*inpt[i]);

            ans = max(ans, max(prod1, prod2));

            
        }
        return ans;

        /*
           for (int start = 0; start <= nums.size() - m; ++start) {
                int end = start + m - 1;
                ans = max(ans, 1LL * nums[start] * nums[end]);
            }
        
        return ans;
       */ 
        
    }



    /*    
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int> arr;
        long long ans = LONG_MIN;
        helper(nums, m, 0, arr, ans);
        return ans;
    }

    void helper(vector<int> &nums, int m, int i, vector<int> &arr, long long &ans){
        if(arr.size() == m) {
            long long cur = 1LL*arr[0]*arr[arr.size()-1];
            ans = max(ans, cur);
            return;
        }

        if(i >= nums.size() || arr.size() > m) return;


        arr.push_back(nums[i]);
        helper(nums, m, i+1, arr, ans);
        arr.pop_back();
        helper(nums,m,i+1,arr,ans);
        
}
    */
    
};
