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

int n, a, b;

vector<int> get(int begin, int t) {
    vector<int> ans;
    for (int i = 1; i < t; ++i) {
        ans.push_back(begin + i);
    }
    ans.push_back(begin);
    return ans;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i * a <= n; ++i) {
        if ((n - i * a) % b) {
            continue;
        }
        int j = (n - i * a) / b;
        vector<int> ans;
        for (int k = 1; k <= i; ++k) {
            auto ve = get((k - 1) * a + 1, a);
            ans.insert(ans.end(), ve.begin(), ve.end());
        }
        for (int k = 1; k <= j; ++k) {
            auto ve = get((k - 1) * b + 1 + i * a, b);
            ans.insert(ans.end(), ve.begin(), ve.end());
        }
        for (auto &i : ans) {
            cout << i << ' ';
        }
        return 0;
    }

    cout << -1 << endl;

    return 0;
}