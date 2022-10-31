#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        if (a.substr(n - m + 1) == b.substr(1)) {
            if (count(a.begin(), a.end() - (m - 1), b[0])) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}