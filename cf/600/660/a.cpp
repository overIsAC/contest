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
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (__gcd(a[i], a[i - 1]) != 1) {
            b.push_back(1);
        }
        b.push_back(a[i]);
    }
    cout << b.size() - a.size() << endl;
    for (auto &i : b) {
        cout << i << ' ';
    }
    return 0;
}