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

set<vector<int>> st;

void dfs(vector<int> ve) {
    if (st.count(ve)) {
        return;
    }
    st.insert(ve);
    for (int i = 0; i < ve.size(); ++i) {
        if (ve[i] != 1) {
            auto a = ve;
            a.insert(a.begin() + i + 1, a[i] - a[i] / 2);
            a.insert(a.begin() + i + 1, a[i] / 2);
            a.erase(a.begin() + i);
            dfs(a);

            a = ve;
            a.insert(a.begin() + i + 1, a[i] / 2);
            a.insert(a.begin() + i + 1, a[i] - a[i] / 2);
            a.erase(a.begin() + i);
            dfs(a);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a = {n};

    dfs(a);

    cout << st.size() << endl;

    return 0;
}