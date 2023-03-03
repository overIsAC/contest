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

int n, a[N];
int dp[555][555];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    auto add = [&](int x, int y) {
        if (x <= 0) {
            return;
        }
        for (int i = x; i <= 500; i += i & -i) {
            dp[i][y] = 1;
        }
    };
    for (int i = 1; i <= n; ++i) {
        add(a[i], a[i]);
        for (int j = a[i]; j > 0; j -= j & -j) {
            for (int k = 0; k <= 512; ++k) {
                if (dp[j][k]) {
                    add(a[i], k ^ a[i]);
                }
            }
        }
    }
    set<int> st = {0};
    for (int i = 1; i <= 500; ++i) {
        for (int j = 1; j <= 512; ++j) {
            if (dp[i][j]) {
                st.insert(j);
            }
        }
    }
    cout << st.size() << endl;
    for (auto &i : st) {
        cout << i << ' ';
    }

    return 0;
}