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
const int N = 3 + 1e6;

int n;
char op;
int v;
int ans[N];
int stk[N], top;
int sz;

struct Node {
    int type;
    int v;
};

vector<Node> a;
vector<int> b;

int main() {
    cin >> n;
    for (int i = 1; i <= n * 2; ++i) {
        cin >> op;
        if (op == '+') {
            ++op;
            ++sz;
            stk[++top] = sz;
            a.push_back({0});
        } else {
            cin >> v;
            if (!top) {
                cout << "NO" << endl;
                return 0;
            }
            ans[stk[top]] = v;
            --top;
            a.push_back({1, v});
        }
    }

    cout << "YES" << endl;

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}