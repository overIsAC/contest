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

int n, m, a[N], b[N], x, y;

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    int u = 1, v = 1;
    for (int i = x - 1, j = 1; j <= m; --i, ++j) {
        if (i == 0) {
            u = 0;
            break;
        }
        if (a[i] != b[j]) {
            u = 0;
            break;
        }
    }
    for (int i = x + 1, j = 1; j <= m; ++i, ++j) {
        if (i > n) {
            v = 0;
            break;
        }
        if (a[i] != b[j]) {
            v = 0;
            break;
        }
    }
    if (u && v) {
        cout << "Unsure" << endl;
    } else if (u) {
        if (y < x) {
            cout << "Right" << endl;
        } else {
            cout << "Wrong" << endl;
        }
    } else if (v) {
        if (y < x) {
            cout << "Wrong" << endl;
        } else {
            cout << "Right" << endl;
        }
    } else {
        assert(false);
    }
    return 0;
}