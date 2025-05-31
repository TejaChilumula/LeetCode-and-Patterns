class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        /*int ans = left;

        for(int i=left+1;i<=right;i++){
            ans &= i;
        }
        return ans;
        */
        ***************** SHARE PREFIX ******************* Not Bit at a place
        /* Use the power of AND */
        /* as we are increasing from left to right - the numbers will share atleast one bit common prefix, we keep that bit and rest all we will make 0,
        if a bit is 0 at left ni, then it will defenitely 0 in right
        */
        int shifts = 0;
        while(l < r){
            l = l>>1;
            r = r>>1;
            shifts++;
        }

        return l<<shifts;

        /* what happens when l = 1 and r = 15
            - 0001
            - 1111
            ans   
        */

    }
};