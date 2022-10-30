#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
PII a[N];

LL tr1[N], tr2[N], tr3[N], tr4[N];
set<int> s1, s2;

void add(LL *tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL *tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        // add(tr1, i, i);
        add(tr3, i, 1);
    }
    sort(a + 1, a + n + 1);
    LL cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s1.empty() || *s1.rbegin() > a[i].second) {
            s1.insert(a[i].second);
        } else {
            s2.insert(a[i].second);
        }
        while (s1.size() < s2.size()) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        while (s1.size() > s2.size() + 1) {
            s2.insert(*s1.rbegin());
            s1.erase(prev(s1.end()));
        }

        int p = *s1.rbegin();

        add(tr1, a[i].second, a[i].second);
        add(tr2, a[i].second, 1);
        add(tr3, a[i].second, -1);
        cnt += ask(tr2, n) - ask(tr2, a[i].second);
        LL ans = -ask(tr1, p) + ask(tr1, n) - ask(tr1, p);

        // cout << "i p ans: " << i << ' ' << p << ' ' << ans << endl;

        if (i & 1) {
            ans += (LL)(i + 1) / 2 * (p + (p - (i + 1) / 2 + 1)) / 2;
            ans -= (LL)i / 2 * (p + 1 + (p + 1 +  i / 2 - 1)) / 2;
            // cout << "odd " << (p - (i + 1) / 2 + 1) << ' ' << p << endl;
            // cout << " " << (p + 1 +  i / 2 - 1) << ' ' << p + 1 << endl;
        } else {
            ans += (LL)i / 2 * (p + (p - i / 2 + 1)) / 2;
            ans -= (LL)i / 2 * (p + 1 + (p + 1 + i / 2 - 1)) / 2;
            // cout << "even " << p - i / 2 + 1 << ' ' << p << ' ' << p + 1 << ' '
            //      << (p + 1 + i / 2 - 1) << endl;
        }

        cout << ans + cnt << ' ';
        // cout << ans + cnt << '\n';
    }

    return 0;
}