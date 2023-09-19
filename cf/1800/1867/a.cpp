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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<PII> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            a[i].first = n - i;
            swap(a[i].first, a[i].second);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cout << a[i].second << ' ';
        }
        cout << endl;
    }
    return 0;
}