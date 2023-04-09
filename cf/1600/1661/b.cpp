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

int n, a[N], b[N];
int d[N];
vector<int> edge[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 32768; ++i) {
        edge[(i + 1) % 32768].push_back(i);
        edge[(i * 2) % 32768].push_back(i);
    }
    memset(d, 0x3f, sizeof(d));
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << d[a[i]] << ' ';
    }
    return 0;
}