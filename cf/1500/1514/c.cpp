#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<int> pre;
    LL temp = 1;
    for (int i = 1; i <= n; ++i) {
        if (__gcd(i, n) == 1) {
            ans.push_back(i);
            temp = temp * i % n;
            pre.push_back(temp);
        }
    }

    if (temp != 1) {
        for (int i = (int)ans.size() - 1; i >= 0; --i) {
            if (temp * pre[i - 1] % n == 1) {
                ans.erase(ans.begin() + i);
                break;
            }
            temp *= ans[i];
        }
    }

    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}