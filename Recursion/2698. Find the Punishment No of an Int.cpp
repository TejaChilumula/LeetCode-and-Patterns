class Solution {
public:
    long global_ans = 0;
    int punishmentNumber(int n) {
        // how to get punishment number ?....


        /*

            structuring should be simple, what you need at the driver code and what you
            want the helper functions to return.

             -  You can calculate the gloabl_ans in helper but we are having the val, which needs to add, then why we need a val to return from it, 
             - It just need to tell, is it a punsihed num or not !
        */

        for(int i=1;i<=n;i++){
            string sqrt = to_string(i*i);

            if(helper(i, sqrt, 0, 0, sqrt.size())) global_ans += i*i;
            
        }
        return global_ans;
    }

    bool helper(long ans, string sqrt, int idx, int sum, int n){

        if(idx == sqrt.size()){
            
            return sum == ans;
        }

        if(sum > ans || idx > sqrt.size()) return false;

        for(int i=idx;i<=n;i++){
            string num_str = sqrt.substr(idx,i-idx+1);  /// for each element you are finding all the subarray patterns....
            /*
            ***** For each index, try all possible substrings starting here, then recurse forward.
                - 1 | 296 - s=1
                - 2 | 96. - s=3
                - 9 | 6. -  s=12
                  6.     - s = 18 not equal return false
                  ---- Backtrack ----
                s = 3 , 96 - 99 != ret false
                ------- Backtrack. -----
                s = 1, 29 | 6 
                s = 30 , 6
                s = 36 - return True
            */
            int num = stoi(num_str);
            if(helper(ans, sqrt, i+1, sum+num, n)) return true;
        }
        return false;
    }


};