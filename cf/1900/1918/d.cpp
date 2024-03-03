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

struct Node {
    LL v;
    int id;
    bool operator<(const Node& other) const {
        if (v != other.v) {
            return v > other.v;
        }
        return id < other.id;
    }
};

int n, a[N];
LL pre[N];
LL dp[N];

int ok(LL z) {
    for (int i = 0; i <= n; ++i) {
        dp[i] = z + 1;
    }

    priority_queue<Node> q;
    dp[0] = 0;
    dp[1] = a[1];
    q.push({dp[0], 1});
    q.push({dp[1], 2});
    for (int i = 2; i <= n; ++i) {
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (pre[i - 1] - pre[mid - 1] <= z) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        while (q.size() && q.top().id < r) {
            q.pop();
        }
        if (q.empty()) {
            break;
        }
        dp[i] = q.top().v + a[i];
        if (dp[i] <= z) {
            q.push({dp[i], i + 1});
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (pre[n] - pre[i] <= z && dp[i] <= z) {
            return 1;
        }
    }
    return 0;
}
/*
1
5
1 2 3 4 5


1
8
1 1 1 1 1 1 1 1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i];
        }

        LL l = *max_element(a + 1, a + n + 1);
        LL r = accumulate(a + 1, a + n + 1, 0LL);

        while (l < r) {
            LL mid = l + r >> 1;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << '\n';
    }
    return 0;
}