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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int z = 0;
    for (auto& i : a) {
        z ^= i;
    }
    if (z) {
        cout << -1 << endl;
        return 0;
    }
    map<int, int, greater<int>> mp;
    for (auto& i : a) {
        mp[i] ^= 1;
    }
    for (auto& i : mp) {
        if (i.second) {
            cout << i.first - 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}