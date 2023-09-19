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

int n, m;

struct Node {
    int i, cnt;
    bool operator<(const Node& other) const {
        if (cnt != other.cnt) {
            return cnt < other.cnt;
        }
        if (abs((m + 1) - 2 * i) != abs((m + 1) - 2 * other.i)) {
            return abs((m + 1) - 2 * i) < abs((m + 1) - 2 * other.i);
        }
        return i < other.i;
    }
};

int main() {
    cin >> n >> m;
    set<Node> st;
    for (int i = 1; i <= m; ++i) {
        st.insert({i, 0});
    }
    for (int i = 1; i <= n; ++i) {
        auto x = *st.begin();
        st.erase(*st.begin());
        cout << x.i << endl;
        ++x.cnt;
        st.insert(x);
    }
    return 0;
}