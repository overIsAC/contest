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

int n, x[N], y[N];

int query(int x, int y) {
    int ans;
    cout << "? " << x << ' ' << y << endl;
    cin >> ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        int p1 = query(l, r);
        if (p1 <= mid) {
            if (l == mid) {
                l = mid + 1;
            } else {
                int p2 = query(l, mid);
                if (p1 == p2) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        } else {
            if (r == mid + 1) {
                r = mid;
            } else {
                int p2 = query(mid + 1, r);
                if (p1 == p2) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
    }
    cout << "! " << r << endl;
    return 0;
}