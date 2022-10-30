#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int tr[3][N * 2];
int n, m;
char s[N];

void add(int *tr, int p, int v) {
    for (; p <= n * 2 + 1; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int *tr, int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s + 1;
        m = n + 1;
        LL ans = 0;
        int pre = 0;

        for (int i = 1; i <= 2 * n + 1; ++i) {
            tr[0][i] = tr[1][i] = tr[2][i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            add(tr[(pre % 3 + 3) % 3], pre + m, 1);
            if (s[i] == '-')
                pre += 1;
            else
                pre -= 1;
            ans += ask(tr[(pre % 3 + 3) % 3], pre + m);
        }
        cout << ans << endl;
    }
    return 0;
}
