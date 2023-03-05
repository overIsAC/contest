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
const int M = 32000;

vector<int> prime;
int f[M];
int n, a[N];

void solve() {
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        int v = a[i];
        for (auto &p : prime) {
            if (p * p > v) {
                break;
            }
            if (v % p == 0) {
                if (st.count(p)) {
                    cout << "YES\n";
                    return;
                }
                st.insert(p);
                while (v % p == 0) {
                    v /= p;
                }
            }
        }
        if (v > 1) {
            if (st.count(v)) {
                cout << "YES\n";
                return;
            }
            st.insert(v);
        }
    }
    cout << "NO\n";
}

int main() {
    for (int i = 2; i < M; ++i) {
        if (!f[i]) {
            prime.push_back(i);
            for (int j = i * 2; j < M; j += i) {
                f[j] = 1;
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}