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
const int M = 3 + 1e6;

int n, a[N];
int cnt[M];
vector<int> b[M];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]] = 1;
    }
    for (int i = 2; i < M; ++i) {
        if (b[i].size()) { 
            continue;
        }
        for (int j = i; j < M; j += i) {
            b[j].push_back(i);
        }
    }
    for (int i = M - 1; i >= 1; --i) {
        if (!cnt[i]) {
            continue;
        }
        int ok = 1;
        for (auto &j : b[i]) {
            if (!cnt[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}