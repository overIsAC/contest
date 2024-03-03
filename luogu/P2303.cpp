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

LL n;
int vis[N];
map<LL, LL> phi;
vector<LL> a;

int main() {
    vis[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) {
            LL cnt = i - 1;
            for (LL j = i; j < N; j *= i) {
                phi[j] = cnt;
                cnt *= i;
            }
        }
        for (int j = i + i; j < N; j += i) {
            vis[j] = 1;
        }
    }

    cin >> n;
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n) {
                a.push_back(n / i);
            }
        }
    }
    sort(a.begin(), a.end());

    phi[1] = 1;
    for (auto& i : a) {
        if (phi.count(i)) {
            continue;
        }
        for (auto [u, v] : phi) {
            if (i % u) {
                continue;
            }
            if (u != 1 && __gcd(u, i / u) == 1) {
                phi[i] = phi[u] * phi[i / u];
                break;
            }
        }
        if (!phi.count(i)) {
            phi[i] = i - 1;
        }
    }

    LL ans = 0;
    for (auto& i : a) {
        ans += i * phi[n / i];
    }
    cout << ans << endl;

    return 0;
}