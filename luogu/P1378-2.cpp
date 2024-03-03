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
const int N = 3 + 1e5;
const double PI = acos(-1);

int n;
int x[11], y[11];
int vis[11];
int X1, Y1, X2, Y2;
double ans;

double dist(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double get(int p, vector<double>& R) {
    double r = min({abs(x[p] - X1), abs(x[p] - X2), abs(y[p] - Y1), abs(y[p] - Y2)});

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            r = min(r, dist(i, p) - R[i]);
        }
    }

    return max(0.0, r);
}

void dfs(vector<double> R, double sum) {
    ans = min(ans, sum);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        auto r = get(i, R);
        R[i] = r;
        vis[i] = 1;
        dfs(R, sum - PI * r * r);
        vis[i] = 0;
        R[i] = 0;
    }
}

int main() {
    cin >> n;
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    ans = 100000000;
    dfs(vector<double>(11), abs(X1 - X2) * abs(Y1 - Y2));
    cout << fixed << setprecision(0) << ans << endl;
    return 0;
}