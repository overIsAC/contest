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
        int a, b;
        cin >> a >> b;
        string ans;
        if (a <= b) {
            while (a && b) {
                ans += '1';
                ans += '0';
                --a;
                --b;
            }
            while (a) {
                ans += '0';
                --a;
            }
            while (b) {
                ans += '1';
                --b;
            }
        } else {
            while (a && b) {
                ans += '0';
                ans += '1';
                --a;
                --b;
            }
            while (a) {
                ans += '0';
                --a;
            }
            while (b) {
                ans += '1';
                --b;
            }
        }
        cout << ans << endl;
    }
    return 0;
}