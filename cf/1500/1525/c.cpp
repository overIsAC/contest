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
const int N = 3 + 3e5;

struct Node {
    int x, id;
    char c;
} a[N];

int ans[N];
int n, m;

void solve() {
    cin >> n >> m;
    vector<Node> b[2];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x;
        a[i].id = i;
        ans[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].c;
        b[a[i].x & 1].push_back(a[i]);
    }

    auto calc = [&](Node a, Node b) {
        if (a.x > b.x) {
            swap(a, b);
        }
        if (a.c == 'L') {
            a.x = -a.x;
        }
        if (b.c == 'R') {
            b.x = 2 * m - b.x;
        }
        return (a.x + b.x) / 2 - a.x;
    };

    auto f = [&](vector<Node> &a) {
        if (a.empty()) {
            return;
        }
        sort(a.begin(), a.end(), [&](Node &a, Node &b) {
            return a.x < b.x;
        });
        stack<Node> stk;
        for (auto &i : a) {
            if (i.c == 'R') {
                stk.push(i);
            } else {
                if (stk.size()) {
                    ans[stk.top().id] = ans[i.id] = calc(stk.top(), i);
                    stk.pop();
                } else {
                    stk.push(i);
                }
            }
        }
        while (stk.size() >= 2) {
            auto x = stk.top();
            stk.pop();
            auto y = stk.top();
            stk.pop();
            ans[x.id] = ans[y.id] = calc(x, y);
        }
    };
    f(b[0]);
    f(b[1]);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}