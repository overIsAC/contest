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
    vector<int> ans;
    while (n) {
        ans.push_back(0);
        for (int i = 100000000; i >= 1; i /= 10) {
            if (n / i % 10) {
                n -= i;
                ans.back() += i;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}