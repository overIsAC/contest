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
const int N = 3 + 777;

struct BigInt {
    vector<int> a;

    BigInt(int b = 0) {
        do {
            a.push_back(b % 10);
            b /= 10;
        } while (b);
    }
    BigInt operator*(const int &b) const {
        BigInt ans;
        ans.a.resize(a.size());
        int g = 0;
        for (int i = 0; i < a.size(); ++i) {
            ans.a[i] = (a[i] * b + g);
            g = ans.a[i] / 10;
            ans.a[i] %= 10;
        }
        while (g) {
            ans.a.push_back(g % 10);
            g /= 10;
        }
        return ans;
    }
    BigInt operator*(const BigInt &b) const {
        const BigInt &a = *this;
        BigInt ans;
        ans.a.resize(a.a.size() + b.a.size());
        for (int i = 0; i < a.a.size(); ++i) {
            for (int j = 0; j < b.a.size(); ++j) {
                ans.a[i + j] += a.a[i] * b.a[j];
            }
        }
        for (int i = 0; i + 1 < ans.a.size(); ++i) {
            ans.a[i + 1] += ans.a[i] / 10;
            ans.a[i] %= 10;
        }
        while (ans.a.size() > 1 && ans.a.back() == 0) {
            ans.a.pop_back();
        }
        return ans;
    }
    bool operator<(const BigInt &b) const {
        const BigInt &a = *this;
        if (a.a.size() != b.a.size()) {
            return a.a.size() < b.a.size();
        }
        for (int i = (int)a.a.size() - 1; i >= 0; --i) {
            if (a.a[i] != b.a[i]) {
                return a.a[i] < b.a[i];
            }
        }
        return false;
    }
};

ostream &operator<<(ostream &output, const BigInt &value) {
    for (auto it = value.a.rbegin(); it != value.a.rend(); ++it) {
        output << *it;
    }
    return output;
}

vector<int> edge[N];
int n;
BigInt dp[N][N];
int sz[N];
BigInt temp[N];

void dfs(int x, int fa) {
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        for (int i = sz[x]; i > 0; --i) {
            temp[i] = dp[x][i];
        }
        for (int i = sz[x]; i > 0; --i) {
            for (int j = sz[y]; j > 0; --j) {
                dp[x][i] = max(dp[x][i], temp[i] * dp[y][j] * j);
                dp[x][i + j] = max(dp[x][i + j], temp[i] * dp[y][j]);
            }
        }
        sz[x] += sz[y];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = 1;
        }
    }

    dfs(1, 0);
    BigInt ans;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[1][i] * i);
    }
    cout << ans << endl;
    return 0;
}