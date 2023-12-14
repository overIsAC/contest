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

int n, a[N];
vector<int> q;

int cmp(int u, int v) {
    if (a[u] > a[v]) {
        return u;
    } else {
        return v;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= (1 << n); ++i) {
        cin >> a[i];
        q.push_back(i);
    }
    while (q.size() > 2) {
        vector<int> w;
        for (int i = 0; i < q.size(); i += 2) {
            w.push_back(cmp(q[i], q[i + 1]));
        }
        q = w;
        // for (auto& i : q) {
        //     cout << i << ' ';
        // }
        // cout << endl;
    }
    if (a[q[0]] > a[q[1]]) {
        cout << q[1] << endl;
    } else {
        cout << q[0] << endl;
    }
    return 0;
}