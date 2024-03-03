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
const int N = 3 + 1e6;

int n, a[N], m;

vector<int> b[N];
vector<int> p[N];
int siz[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] > m) {
            continue;
        }
        b[a[i]].push_back(i);
        ++siz[a[i]];
    }
    for (int i = m; i >= 1; --i) {
        for (int j = i + i; j <= m; j += i) {
            siz[j] += siz[i];
        }
    }
    int p = 0;
    for (int i = 1; i <= m; ++i) {
        if (siz[i] > siz[p]) {
            p = i;
        }
    }

    int g = 1;
    vector<int> seq;
    for (int i = 1; i <= p; ++i) {
        if (p % i == 0) {
            for (auto& j : b[i]) {
                g = g / __gcd(g, a[j]) * a[j];
                seq.push_back(j);
            }
        }
    }

    sort(seq.begin(), seq.end());
    cout << g << ' ' << siz[p] << endl;
    for (auto& i : seq) {
        cout << i << ' ';
    }
    return 0;
}