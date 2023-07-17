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

int main() {
    LL x, y;
    cin >> x >> y;
    if (x == y) {
        cout << "YES" << endl;
        return 0;
    }
    vector<int> a, b;
    while (x) {
        a.push_back(x % 2);
        x /= 2;
    }
    while (y) {
        b.push_back(y % 2);
        y /= 2;
    }
    if (!b[0]) {
        cout << "NO" << endl;
        return 0;
    }
    // for (auto &i : a) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (auto &i : b) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    auto check = [&](vector<int> a, vector<int> b) -> int {
        if (a.size() > b.size()) {
            return 0;
        }
        for (int i = 0, j = i + a.size() - 1; j < b.size(); ++i, ++j) {
            int ok = 1;
            for (int k = 0; k < i; ++k) {
                if (b[k] != 1) {
                    ok = 0;
                    break;
                }
            }
            for (int k = j + 1; k < b.size(); ++k) {
                if (b[k] != 1) {
                    ok = 0;
                    break;
                }
            }
            for (int q = 0, w = i; w <= j; ++q, ++w) {
                if (a[q] != b[w]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return 1;
            }
        }
        reverse(a.begin(), a.end());
        for (int i = 0, j = i + a.size() - 1; j < b.size(); ++i, ++j) {
            int ok = 1;
            for (int k = 0; k < i; ++k) {
                if (b[k] != 1) {
                    ok = 0;
                    break;
                }
            }
            for (int k = j + 1; k < b.size(); ++k) {
                if (b[k] != 1) {
                    ok = 0;
                    break;
                }
            }
            for (int q = 0, w = i; w <= j; ++q, ++w) {
                if (a[q] != b[w]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return 1;
            }
        }
        return 0;
    };

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.push_back(1);
    if (check(a, b)) {
        cout << "YES" << endl;
        return 0;
    }
    a.pop_back();
    while (a.size() && a.back() == 0) {
        a.pop_back();
    }
    if (check(a, b)) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}