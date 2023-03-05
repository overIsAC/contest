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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    LL n, k, s;
    cin >> n >> k >> s;
    if (k == 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> ans;
    bool flag = true;
    LL p = 1;
    for (int i = 1; i <= k; ++i) {
        if (flag) {
            LL v = min(s, n - p);
            s -= v;
            p += v;
        } else {
            LL v = min(s, p - 1);
            s -= v;
            p += v;
        }
        ans.push_back(p);
        flag = !flag;
        if (!s) {
            break;
        }
    }
    if (ans.size() == k && !s) {
        cout << "YES" << endl;
        for (auto& i : ans) {
            cout << i << ' ';
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}