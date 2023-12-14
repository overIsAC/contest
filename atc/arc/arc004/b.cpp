#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, x[N], y[N];

int main() {
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    cout << accumulate(a.begin(), a.end(), 0) << endl;
    if (*max_element(a.begin(), a.end()) * 2 <=
        accumulate(a.begin(), a.end(), 0)) {
        cout << 0 << endl;
    } else {
        cout << abs(*max_element(a.begin(), a.end()) * 2 -
                    accumulate(a.begin(), a.end(), 0))
             << endl;
    }
    return 0;
}