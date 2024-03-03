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

int n, m;
int a[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[a[i]] += 1;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            f[i] += f[j];
        }
    }
    f[1] = 0;
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        int flag = 1;
        for (int j = 1; j * j <= i; ++j) {
            if (i % j) {
                continue;
            }
            if (f[j] || f[i / j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << endl;
    }
    return 0;
}