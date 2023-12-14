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

struct Node {
    int left, right;
} node[N];

int id;
int n;

void dfs(int x) {
    if (!x) {
        return;
    }
    cout << (char)x;
    dfs(node[x].left);
    dfs(node[x].right);
}

int main() {
    cin >> n;
    char root;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s[1] != '*') {
            node[s[0]].left = s[1];
        }
        if (s[2] != '*') {
            node[s[0]].right = s[2];
        }
        if (i == 1) {
            root = s[0];
        }
    }
    dfs(root);

    return 0;
}