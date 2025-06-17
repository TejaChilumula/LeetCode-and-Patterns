class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /* Smart Solution
            since we want Org[] in which , der[i] = Org[i]^Org[i+1]
            der[i+1] = Org[i+1]^Org[i+2];....
            so der[i]^der[i+1]... = ( Org[i]^Org[i+1] ) ^ ( Org[i+1]^Org[i+2] ) .....
             Everything will cancel out..
        */

        int XOR = 0;

        for(auto d : derived) XOR ^= d;

        return XOR == 0;
    }
};