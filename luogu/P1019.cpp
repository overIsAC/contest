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
const int N = 3 + 222;

int n;
string s[N];
int cnt[N];
char head;
int ans;
string stk;

int minOk[N][N];

int check(int p, int q) {
    return minOk[p][q];
}

int calc(int p, int q) {
    int length = 1;
    while (length < s[p].size() && length < s[q].size()) {
        if (s[p].substr(s[p].size() - length) == s[q].substr(0, length)) {
            return length;
        }
        ++length;
    }
    return 0;
}

void dfs(int last, int remain) {
    if (remain + stk.size() <= ans) {
        return;
    }
    ans = max<int>(ans, stk.size());
    if (stk.size() == 0) {
        for (int i = 1; i <= n; ++i) {
            if (s[i][0] == head) {
                ++cnt[i];
                stk = s[i];
                dfs(i, remain - s[i].size());
                stk.clear();
                --cnt[i];
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 2) {
                continue;
            }
            int z = check(last, i);
            if (!z) {
                continue;
            }
            ++cnt[i];
            stk += s[i].substr(z);
            dfs(i, remain - s[i].size());
            for (int j = 1; j <= s[i].size() - z; ++j) {
                stk.pop_back();
            }

            --cnt[i];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    cin >> head;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            minOk[i][j] = calc(i, j);
        }
    }

    dfs(0, accumulate(s + 1, s + n + 1, 0, [&](int a, string& b) {
               return a + b.size();
           }) * 2);

    cout << ans << endl;
    return 0;
}