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
const int N = 3 + 2e5;

int n, q;
int a[N], k[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        map<char, LL> m1, m2;
        ++m1['a'];
        ++m2['a'];
        auto calc = [&]() {
            vector<pair<char, LL>> a(m1.begin(), m1.end());
            vector<pair<char, LL>> b(m2.begin(), m2.end());
            reverse(b.begin(), b.end());
            int i = 0, j = 0;
            while (i < a.size() && j < b.size()) {
                LL t = min(a[i].second, b[j].second);
                a[i].second -= t;
                b[j].second -= t;
                if (t) {
                    if (a[i].first != b[j].first) {
                        return a[i].first < b[j].first;
                    }
                }
                if (!a[i].second) {
                    ++i;
                }
                if (!b[j].second) {
                    ++j;
                }
            }
            if (i == a.size()) {
                return j < b.size();
            }
            return false;
        };
        cin >> n;
        while (n--) {
            int d, k;
            string c;
            cin >> d >> k >> c;
            for (auto& i : c) {
                if (d == 1) {
                    m1[i] += k;
                } else {
                    m2[i] += k;
                }
            }
            if (calc()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}