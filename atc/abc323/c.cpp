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
const int N = 3 + 111;

int n, m, a[N];
string s[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<PII> b;
    for (int i = 0; i < n; ++i) {
        int sum = i + 1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'o') {
                sum += a[j];
            }
        }
        b.push_back({sum, i});
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; ++i) {
        vector<int> c;
        int cnt = i + 1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != 'o') {
                c.push_back(a[j]);
            } else {
                cnt += a[j];
            }
        }
        sort(c.rbegin(), c.rend());
        int ans = 0;
        int* p;
        if (b[0].second == i) {
            p = &b[1].first;
        } else {
            p = &b[0].first;
        }
        for (auto& i : c) {
            if (cnt > *p) {
                break;
            }
            cnt += i;
            ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}