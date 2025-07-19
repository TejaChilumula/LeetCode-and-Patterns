#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 || m == 1)
            cout << "NO"<<endl;
        else
            cout << "YES"<<endl;
    }

    return 0;
}
