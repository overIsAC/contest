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

set<LL> a;

void dfs(LL x, int last) {
    a.insert(x);
    for (int i = last - 1; i >= 0; --i) {
        dfs(x * 10 + i, i);
    }
}

int main() {
    dfs(0, 10);

    int n;
    cin >> n;
    cout << vector<LL>(a.begin(), a.end())[n] << endl;
    return 0;
}