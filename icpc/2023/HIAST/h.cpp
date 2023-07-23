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
const int N = 3 + 1e3;

template <typename T>
void print(T a) {
    for (auto &i : a) {
        cout << i << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    set<int> st;
    multiset<LL> st2;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        st.insert(i);
        st2.insert(b);
        a[i] = b;
    }

    cout << *st2.rbegin() << endl;

    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        st.erase(p);
        st2.erase(st2.find(a[p]));
        st2.erase(st2.find(a[*st.begin()]));
        a[*st.begin()] += a[p];
        st2.insert(a[*st.begin()]);
        cout << *st2.rbegin() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}