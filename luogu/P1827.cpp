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
    int left, right, value;
} node[N];

int id;
string a, b;

int dfs(int L1, int R1, int L2, int R2) {
    if (L1 > R1) {
        return 0;
    }
    if (L1 == R1) {
        node[++id].value = a[L1];
        return id;
    }
    int p1 = L1;
    while (p1 <= R1) {
        if (a[p1] == b[L2]) {
            break;
        }
        ++p1;
    }
    int p2 = L2 + (p1 - L1);
    /*
        L1,p1-1      L2,p2
        p1+1,R1      p2+1,R2-1
    */
    int z = ++id;
    node[z].value = b[L2];
    node[z].left = dfs(L1, p1 - 1, L2 + 1, p2);
    node[z].right = dfs(p1 + 1, R1, p2 + 1, R2);
    return z;
}

void dfs(int root) {
    if (!root) {
        return;
    }
    dfs(node[root].left);
    dfs(node[root].right);
    cout << (char)node[root].value;
}

int main() {
    cin >> a >> b;
    int root = dfs(0, a.size() - 1, 0, b.size() - 1);
    dfs(root);
    return 0;
}