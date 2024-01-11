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
const int N = 3 + 1e3;

int n, m;
char s[N][N];
int z[N][N];
int h[N], w[N], top;

int calc(int* z) {
    int ans = 0;
    for (int i = 1; i <= m + 1; ++i) {
        int mh = 1e9, mw = 0;
        while (top && h[top] >= z[i]) {
            mh = min(mh, h[top]);
            mw += w[top];
            --top;

            ans = max(ans, mh * mw);
        }

        mh = min(mh, z[i]);
        mw += 1;
        h[++top] = mh;
        w[top] = mw;

        ans = max(ans, mh * mw);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
            if (s[i][j] == 'F') {
                z[i][j] = z[i - 1][j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, calc(z[i]));
    }
    cout << ans * 3 << endl;

    return 0;
}