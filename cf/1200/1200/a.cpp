#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int cnt[11];

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (auto &i : s) {
        if (i == 'L') {
            for (int j = 0; j <= 9; ++j) {
                if (!cnt[j]) {
                    cnt[j] = 1;
                    break;
                }
            }
        } else if (i == 'R') {
            for (int j = 9; j >= 0; --j) {
                if (!cnt[j]) {
                    cnt[j] = 1;
                    break;
                }
            }
        } else {
            cnt[i - '0'] = 0;
        }
    }
    for (int i = 0; i <= 9; ++i) {
        cout << cnt[i];
    }
    return 0;
}