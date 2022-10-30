#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cnt[10] = {};
        for (int i = s.size() - 1; i >= 0; --i) {
            int j = s[i] - '0';
            bool have = false;
            for (int k = j - 1; k >= 0; --k) {
                if (cnt[k]) {
                    have = true;
                    break;
                }
            }
            if (have) {
                ++cnt[min(j + 1, 9)];
            } else {
                ++cnt[j];
            }
        }

        for (int i = 0; i < 10; ++i) {
            while (cnt[i]--) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}