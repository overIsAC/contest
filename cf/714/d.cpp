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

int qm(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
    int x;
    cin >> x;
    return x;
};

vector<int> query(int x1, int y1, int x2, int y2, int v) {
    int l = y1, r = y2;
    while (l < r) {
        int mid = l + r >> 1;
        if (qm(x1, y1, x2, mid) >= v) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int R = r;
    l = y1;
    r = R;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (qm(x1, mid, x2, R) >= 2) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int L = r;

    l = x1;
    r = x2;

    while (l < r) {
        int mid = l + r >> 1;
        if (qm(x1, L, mid, R) >= v) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int D = r;

    l = x1;
    r = D;

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (qm(mid, L, D, R) >= v) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int U = r;

    return {U, D, L, R};
}

int main() {
    int x1, y1, x2, y2;
    int n;

    cin >> n;

    auto c = query(1, n, 1, n, 2);

    return 0;
}