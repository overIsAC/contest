#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 7 + 1e9;
const int N = 3 + 2e5;

int n, k;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s + 1;
        int l = 1, r = n;

        auto ok = [&](int o) {
            int kk = k;
            for (int i = 1; i <= n; ++i) {
                if (s[i] == '1') {
                    if (!kk) {
                        return 0;
                    }
                    --kk;
                    i += o - 1;
                }
            }
            return 1;
        };  

        while (l < r) {
            int mid = l + r >> 1;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}