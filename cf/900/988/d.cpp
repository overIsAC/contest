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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    set<int> st(a.begin(), a.end());
    vector<int> ans = {*st.begin()};
    for (auto& i : st) {
        LL j = 1;
        while (j <= 2e9) {
            if (st.count(i - j) && st.count(i + j)) {
                cout << 3 << endl;
                cout << i << ' ' << i - j << ' ' << i + j << endl;
                return 0;
            }
            if (st.count(i - j)) {
                ans = {i, i - j};
            }
            j *= 2;
        }
    }
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << ' ';
    }
    return 0;
}