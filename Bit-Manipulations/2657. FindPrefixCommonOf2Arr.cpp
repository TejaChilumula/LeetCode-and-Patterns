class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        /* 2 solutions using bitset
        // Solution 1: using the 2 bits for 1 number rule
        // 2*n for the A's element, 2*n+1 for B's for same element

        bitset<101> bits; // n <= 50, we need 2x
        int n = A.size(), c = 0;
        vector<int> res(n);

        for(int i=0;i<n;i++){
            
            // insert in A's pos i.e 2*A[i]
            int a = A[i], b = B[i];
            bits[2*a] = 1;
            if(bits[2*a+1] == 1) c++; //B already inserted

            // B's insert
            bits[2*b+1] = 1;
            if(bits[2*b] == 1) c++; // A already inserted

            res[i] = c;
        }
        return res;
        */

        // Solution - 2

        // using the bits as the element count
        // 0 0 0 0 0, if 3 present in A
        // then bits becomes 0 0 1 0 0, we mark the bit on the number we get so far and we need the common so we do Abits & Bbits

        int n = A.size();
        vector<int> res(n);
        unsigned long long Abits = 0, Bbits = 0;

        for(int i=0;i<n;i++){
            Abits |= (1ULL << A[i]);
            Bbits |= (1ULL << B[i]);

            res[i] = __builtin_popcount(Abits & Bbits);
        }

        return res;
    }
};