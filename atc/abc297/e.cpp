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

int n, k;
int a[N];
set<LL> s;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        s.insert(a[i]);
    }
    for (int i = 1; i < k; ++i) {
        LL v = *s.begin();
        s.erase(s.begin());
        for (int j = 1; j <= n; ++j) {
            s.insert(v + a[j]);
        }
    }
    cout << *s.begin() << endl;
    return 0;
}