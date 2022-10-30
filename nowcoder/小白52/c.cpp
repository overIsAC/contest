#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, m;
int pre[N];

int main() {
    int op, x, y;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            ++pre[1];
            --pre[x];
            ++pre[y + 1];
        } else if (op == 2) {
            ++pre[1];
            --pre[x];
        } else {
            ++pre[x + 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }
    int _max = *max_element(pre + 1, pre + n + 1);
    int cnt = count(pre + 1, pre + n + 1, _max);
    cout << _max << ' ' << cnt << endl;
    return 0;
}