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
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        map<int, int> m;
        for (auto &i : a) {
            ++m[i];
        }
        int ans = m.size();
        priority_queue<PII, vector<PII>, greater<PII> > q;
        for (auto &i : m) {
            if (i.second > 1) q.push({i.second, i.first});
        }
        for (int i = 1; i <= ans; ++i) {
            cout << ans << ' ';
        }
        for (int i = ans + 1; i <= n; ++i) {
            auto x = q.top();
            q.pop();
            --x.first;
            ++ans;
            if (x.first == 1)
                ;
            else
                q.push(x);
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}