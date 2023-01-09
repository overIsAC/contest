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
const int N = 3 + 1e5;

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    int u = a * (n - 1);
    int v = b * (k - 1 + n - 1);
    if (u == v) {
        cout << "0" << endl;
    } else if (u < v) {
        cout << "2" << endl;
    } else {
        cout << "1" << endl;
    }
    return 0;
}