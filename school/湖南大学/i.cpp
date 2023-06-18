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
    int n, m;
    cin >> n >> m;
    LL t = 1;
    vector<pair<LL, LL>> a;
    set<LL> st;
    for (int i = 1; i <= m; ++i) {
        if (st.count(t * 10 % n)) {
            break;
        }
        a.push_back({t * 10 / n, t * 10 % n});
        st.insert(t * 10 % n);
        t = t * 10 % n;
    }
    if (!t) {
        cout << 0 << endl;
        return 0;
    }
    if (a.size() == m) {
        cout << a.back().first << endl;
        return 0;
    }
    reverse(a.begin(), a.end());
    while (a.back().second != t * 10 % n) {
        a.pop_back();
        --m;
    } 
    --m;
    m %= a.size();
    reverse(a.begin(), a.end());
    cout << a[m].first << endl;
    return 0;
}