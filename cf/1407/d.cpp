#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, a[N];
int stk[N], top;
vector<int> edge[N];
int d[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        edge[i].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        int last = 0;
        while (top && a[stk[top]] > a[i]) {
            if (last != a[stk[top]]) {
                edge[stk[top]].push_back(i);
            }
            last = a[stk[top]];
            --top;
        }
        if (top) {
            edge[stk[top]].push_back(i);
        }
        stk[++top] = i;
    }
    top = 0;
    for (int i = 1; i <= n; ++i) {
        int last = 0;
        while (top && a[stk[top]] < a[i]) {
            if (last != a[stk[top]]) {
                edge[stk[top]].push_back(i);
            }
            last = a[stk[top]];
            --top;
        }
        if (top) {
            edge[stk[top]].push_back(i);
        }
        stk[++top] = i;
    }
    queue<int> q;
    q.push(1);
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
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
    cout << d[n] << endl;
    return 0;
}