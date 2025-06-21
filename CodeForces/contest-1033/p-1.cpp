#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;


#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

string solve(vector<long long> coords) {
   /* We have the 4 cases, out of these if any of the case satisfies then we can form a square

   --- ---       |||
   -------       |||
                 |||   

   -------
   -------
   -------

   | | 
   | |
   |   
   | |
   | |
*/

    int l1, b1, l2, b2, l3, b3;
    l1 = coords[0]; //......

    int area = (l1*b2) + (l2*b2) + (l3*b3);
    int side = sqrt(area);

    bool ans = 0;

    ans |= (l1 == side && l1 == l2 && l2 == l3 && b1+b2+b3 == side );
    ans |= (b1 == side && b1 == b2 && b2 == b3 && l1+l2+l3 == side );
    ans |= (b2 == b3 && l2 + l3 == side && l1 == side && b1+b2 == side);
    ans |= (l2 == l3 && b2+b3 == side && b1 == side && l1 + l2 == side);

    return ans ? "Yes\n" : "No\n";


}

int32_t main() {
    fast_io
    int t = 1;
    vector<long long> coords(6);

    cin >> t; // Uncomment if multiple test cases

    while (t--) {
        for(int i=0;i<6;i++) cin>>coords[i];
        cout<<solve(coords);}
return 0;
}
