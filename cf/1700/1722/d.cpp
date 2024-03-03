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
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        LL ans = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                ans += i;
                q.push(max(0, n - 1 - i - i));
            } else {
                ans += n - 1 - i;
                q.push(max(0, i - (n - 1 - i)));
            }
        }
        while (q.size()) {
            ans += q.top();
            cout << ans << ' ';
            q.pop();
        }
        cout << endl;
    }
    return 0;
}