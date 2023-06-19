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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        if (a == b) {
            int l = 0, r = 0;
            for (int i = 0; i < n; ++i) {
                int j = i;
                while (j + 1 < n && a[j] <= a[j]) {
                    ++j;
                }
                if (r - l < j - i) {
                    l = i;
                    r = j;
                }
                i = j;
            }
            ++l;
            ++r;
            cout << l << ' ' << r << endl;
        } else {
            int l = n, r = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    l = min(i, l);
                    r = max(i, r);
                }
            }
            int _max = 0, _min = n;
            for (int i = l; i <= r; ++i) {
                _min = min(_min, a[i]);
                _max = max(_max, a[i]);
            }
            while (true) {
                if (l >= 1 && a[l - 1] <= _min) {
                    --l;
                    _min = a[l];
                    continue;
                }
                if (r + 1 < n && a[r + 1] >= _max) {
                    ++r;
                    _max = a[r];
                    continue;
                }
                break;
            }
            ++l;
            ++r;
            cout << l << ' ' << r << endl;
        }
    }
    return 0;
}