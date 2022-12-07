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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES" << endl;
        if (n == 1) {
            cout << 0 << endl;
        }
        if (n == 2) {
            cout << 1 << endl;
            cout << "1 2" << endl;
        }
        if (n > 2) {
            cout << n << endl;
            for (int i = 1; i < n; ++i) {
                cout << i << ' ' << i + 1 << endl;
            }
            cout << 1 << ' ' << n << endl;
        }
        return 0;
    }
    if (k == 2) {
        if (n <= 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << n - 1 << endl;
            for (int i = 1; i < n; ++i) {
                cout << i << ' ' << i + 1 << endl;
            }
        }
        return 0;
    }
    if (n == k) {
        cout << "NO" << endl;
        return 0;
    }

    vector<PII> ans;

    {
        int i = 1, j = k + 1;
        while (i < j) {
            for (int q = i + 1; q <= j; ++q) {
                ans.push_back({q, i});
            }
            ++i;
            --j;
        }
        for (int q = k + 2; q <= n; ++q) {
            ans.push_back({q - 1, q});
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}