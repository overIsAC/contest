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
const int N = 13 + 1e5;

int n, a[N];
LL pre[N];
int pp[N];
LL suf[460][N];

void add(LL *suf, int p, LL v) {
    suf[p] = v;
}

LL ask(int idx, int p) {
    while (pp[idx] > p) {
        suf[idx][pp[idx]] = max(suf[idx][pp[idx]], suf[idx][pp[idx] + 1]);
        --pp[idx];
    }
    suf[idx][pp[idx]] = max(suf[idx][pp[idx]], suf[idx][pp[idx] + 1]);
    return suf[idx][p];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int j = 0; j < 450; ++j) {
            pp[j] = n;
        }
        for (int i = 1; i <= n + 5; ++i) {
            for (int j = 0; j < 450; ++j) {
                suf[j][i] = 0;
            }
        }
        int ans = 1;
        for (int i = n; i >= 1; --i) {
            add(suf[1], i, a[i]);
            int v = 1;
            for (int j = 2; i + j + v - 1 <= n; ++j) {
                if (ask(j - 1, i + j) > pre[i + j - 1] - pre[i - 1]) {
                    add(suf[j], i, pre[i + j - 1] - pre[i - 1]);
                    ans = max(ans, j);
                }
                v += j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}