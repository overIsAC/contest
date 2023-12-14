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
const int N = 3 + 4e5;

int n, q, a[N];
int tr[N];
map<int, int> mp;

void add(int p, int v) {
    for (; p < N; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

void inc(int x) {
    if (0 < x && x < N) {
        add(x, 1);
    }
}

void dec(int x) {
    if (0 < x && x < N) {
        add(x, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (!mp[a[i]]) {
            inc(a[i]);
        }
        ++mp[a[i]];
    }

    while (q--) {
        int p, v;
        cin >> p >> v;

        --mp[a[p]];
        if (!mp[a[p]]) {
            dec(a[p]);
        }
        a[p] = v;
        if (!mp[a[p]]) {
            inc(a[p]);
        }
        ++mp[a[p]];

        if (!mp[0]) {
            cout << 0 << endl;
            continue;
        }
        int L = 1, R = N - 1;
        while (L < R) {
            LL mid = L + R >> 1;
            if (ask(mid) == mid) {
                L = mid + 1;
            } else {
                R = mid;
            }
        }
        cout << R << endl;
    }
    return 0;
}