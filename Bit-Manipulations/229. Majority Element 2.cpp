#include<iostream>
#include<stdlib.h>
#include<vector>
class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        using namespace std;
        // Need to find out the all the elements appear more than N/3 times
        // so only atleast 1 and atmost 2 elements can be present in the array
        // cause n/3 + n/3 + n/3 = 3n/3 = n; but we want more than n/3 which will take from one of n/3 part

        // Boyer Moore's Algo
        
        class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         
        int c1 = 0, c2 = 1, cnt1 = 0, cnt2 = 0, n = nums.size();

        for(int i=0;i<nums.size();i++){
            
        
            if(nums[i] == c1){
                cnt1++;
            }
            else if(nums[i] == c2){
                cnt2++;
            }
            else if(cnt1 == 0){
                c1 = nums[i];
                cnt1    = 1;
            }
            else if(cnt2 == 0){
                c2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
            vector<int> res;
            
            /* this wont work
            if(cnt1 > n/3) res.push_back(c1);
            if(cnt2 > n/3) res.push_back(c2);
             for case [2,2,1,3] both for cnt1 = 1 and cnt2 = 0 at the end becz it is dynamic to the values, so we need the cross check with the obtained elements count
            
            cnt1 = 0, cnt2 = 0;
            for(int i=0;i<n;i++){
                if(nums[i] == c1) cnt1++;
                else if(nums[i] == c2) cnt2++;
            }*/
            
            if(cnt1 > n/3) res.push_back(c1);
            if(cnt2 > n/3) res.push_back(c2);

            return res;
    }
};
        }
        };