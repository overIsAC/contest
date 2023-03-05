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
        string s;
        cin >> s;
        if (s.back() % 2 == 0) {
            cout << 0 << endl;
        } else {
            int v = 0;
            for (auto& i : s) {
                if (i & 1)
                    ;
                else
                    ++v;
            }
            if (s[0] % 2 == 0) {
                cout << 1 << endl;
            } else if (v) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}