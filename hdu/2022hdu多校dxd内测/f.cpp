#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int val[N];

void build(int id, int l, int r) {
    val[id] += r - l + 1;
    if (l == r) return;
    int mid = (r + l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    return;
}

int main() {
    for (int i = 1; i <= 20; ++i) {
        cout << i << endl;
        build(1, 1, i);
        for (int j = 1;j <= 40; ++j) {
            cout << val[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}