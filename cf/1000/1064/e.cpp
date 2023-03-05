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
    int n;
    cin >> n;
    auto qry = [&](int x, int y) {
        cout << x << ' ' << y << endl;
        static string s;
        cin >> s;
        return s;
    };

    string col = qry(1, 0);
    int l = 1, r = 1e9;
    int p = 1;
    while (l <= r && p < n) {
        int mid = l + r >> 1;
        string now = qry(++p, mid);
        if (now == col) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }


    cout << 100 << ' ' << l << ' ' << 0 << ' ' << r << endl;

    return 0;
}