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

int n, x;
vector<int> a;

int ok(int v) {
    auto b = a;
    b.push_back(v);
    sort(b.begin(), b.end());
    b.erase(b.begin());
    b.pop_back();
    if (accumulate(b.begin(), b.end(), 0) >=  x) {
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> x;
    a.resize(n - 1);
    for (auto& i : a) {
        cin >> i;
    }
    for (int i = 0; i <= 100; ++i) {
        if (ok(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}