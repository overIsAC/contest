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

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for (auto &i : a) {
        cin >> i.first >> i.second;
    }
    sort(a.begin(), a.end());
    int p = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0;;) {
        if (i < n && p > a[i].second) {
            cout << "No" << endl;
            return;
        }
        if (q.size() && p > q.top()) {
            cout << "No" << endl;
            return;
        }
        if (q.empty()) {
            if (i < n) {
                q.push(a[i].second);
                p = a[i].first;
                ++i;
            } else {
                break;
            }
        } else if (i < n && p >= a[i].first) {
            q.push(a[i].second);
            ++i;
        } else {
            ++p;
            q.pop();
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}