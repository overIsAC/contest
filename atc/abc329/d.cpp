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
const int N = 3 + 2e5;

struct Node {
    int num, id;
};

int n, m, a[N];
int num[N];

int operator<(Node a, Node b) {
    if (a.num != b.num) {
        return a.num < b.num;
    } else {
        return a.id > b.id;
    }
}

set<Node> st;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        st.insert({0, i});
    }
    for (int i = 1; i <= m; ++i) {
        ++num[a[i]];
        st.insert({num[a[i]], a[i]});

        auto p = --st.end();
        while (p->num != num[p->id]) {
            st.erase(p);
            p = --st.end();
        }
        cout << p->id << endl;
    }

    return 0;
}