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
const int N = 3 + 5e5;

vector<int> edge[N];
char s[N];
int n;
int id;
int dp1[N][3];
int dp2[N][3];

int build() {
    int x = ++id;
    for (int i = s[id] - '0'; i >= 1; --i) {
        edge[x].push_back(build());
    }
    return x;
}

void dfs(int x) {
    for (auto &y : edge[x]) {
        dfs(y);
    }
    if (edge[x].empty()) {
        dp1[x][0] = 1;
        dp1[x][1] = 0;
        dp1[x][2] = 0;
        dp2[x][0] = 1;
        dp2[x][1] = 0;
        dp2[x][2] = 0;
    } else if (edge[x].size() == 1) {
        int &y = edge[x][0];
        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (i == j) {
                    continue;
                }
                dp1[x][i] = max(dp1[x][i], dp1[y][j] + (i == 0));
                dp2[x][i] = min(dp2[x][i], dp2[y][j] + (i == 0));
            }
        }
    } else {
        int &y1 = edge[x][0];
        int &y2 = edge[x][1];
        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (i == j) {
                    continue;
                }
                for (int k = 0; k <= 2; ++k) {
                    if (i == k || j == k) {
                        continue;
                    }
                    dp1[x][i] = max(dp1[x][i], dp1[y1][j] + dp1[y2][k] + (i == 0));
                    dp2[x][i] = min(dp2[x][i], dp2[y1][j] + dp2[y2][k] + (i == 0));
                }
            }
        }
    }
}

int main() {
    cin >> s + 1;
    n = strlen(s + 1);
    build();
    memset(dp2, 0x3f, sizeof(dp2));
    dfs(1);
    cout << max({dp1[1][0], dp1[1][1], dp1[1][2]}) << ' ';
    cout << min({dp2[1][0], dp2[1][1], dp2[1][2]}) << ' ';
    return 0;
}