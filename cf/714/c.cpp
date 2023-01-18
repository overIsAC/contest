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

int trie[N * 20][2], cnt[N * 20], tot;
int n;
char type;
string s;

void insert(string &s, int v) {
    int rt = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 18; ++i) {
        int id = i < s.size() ? (s[i] & 1) : 0;
        int &p = trie[rt][id];
        if (!p) {
            p = ++tot;
        }
        cnt[p] += v;
        rt = p;
    }
}

int query(string &s) {
    int rt = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 18; ++i) {
        int id = i < s.size() ? (s[i] & 1) : 0;
        int &p = trie[rt][id];
        if (!p) {
            return 0;
        }
        rt = p;
    }
    return cnt[rt];
}

int main() {
    cin >> n;
    while (n--) {
        cin >> type >> s;
        if (type == '+') {
            insert(s, 1);
        } else if (type == '-') {
            insert(s, -1);
        } else {
            cout << query(s) << endl;
        }
    }
    return 0;
}