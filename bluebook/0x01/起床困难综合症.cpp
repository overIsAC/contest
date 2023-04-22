#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e5;

int n, m;
string op[N];
int num[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> op[i] >> num[i];
    }
    int limit = 1, ans = 0;
    for (int i = 29; i >= 0; --i) {
        int bit[2] = {0, 1};
        for (int j = 1; j <= n; ++j) {
            if (op[j] == "OR") {
                for (int k = 0; k <= 1; ++k) {
                    bit[k] |= num[j] >> i & 1;
                }
            } else if (op[j] == "AND") {
                for (int k = 0; k <= 1; ++k) {
                    bit[k] &= num[j] >> i & 1;
                }
            } else {
                for (int k = 0; k <= 1; ++k) {
                    bit[k] ^= num[j] >> i & 1;
                }
            }
        }
        int up = limit ? (m >> i & 1) : 1;
        int t = 0;
        for (int j = 0; j <= up; ++j) {
            if (bit[t] < bit[j]) {
                t = j;
            }
        }
        limit = limit && t == up;
        ans |= bit[t] << i;
    }
    cout << ans << endl;

    return 0;
}