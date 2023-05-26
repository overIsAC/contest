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

set<LL> st;
map<LL, LL> mex;
int q;
LL x;
char c;

int main() {
    cin >> q;
    while (q--) {
        cin >> c >> x;
        if (c == '+') {
            st.insert(x);
        } else {
            if (!mex.count(x)) {
                mex[x] = x;
            }
            while (st.count(mex[x])) {
                mex[x] += x;
            }
            cout << mex[x] << endl;
        }
    }
    return 0;
}