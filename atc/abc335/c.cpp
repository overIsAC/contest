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
deque<PII> dq;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        dq.push_back({i, 0});
    }
    while (q--) {
        int op, p;
        char c;
        cin >> op;
        if (op == 1) {
            cin >> c;
            auto [x, y] = dq.front();
            dq.pop_back();
            if (c == 'U') {
                ++y;
            } else if (c == 'D') {
                --y;
            } else if (c == 'R') {
                ++x;
            } else {
                --x;
            }
            dq.push_front({x, y});
        } else {
            cin >> p;
            cout << dq[p - 1].first << ' ' << dq[p - 1].second << endl;
        }
    }
    return 0;
}