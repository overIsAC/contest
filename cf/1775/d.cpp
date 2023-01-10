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
const int N = 3 + 3e5;

int n, a[N];
int s, t;
int d[N], pre[N];
vector<int> fac[N];
vector<int> point[N];
queue<int> q;
int wh[N];
int mp[N];

int main() {
    for (int i = 2; i < N; ++i) {
        if (fac[i].size()) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            fac[j].push_back(i);
            point[i].push_back(j);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    cin >> s >> t;
    mp[a[s]] = s;
    mp[a[t]] = t;

    if (s == t) {
        cout << 1 << endl;
        cout << t << endl;
        return 0;
    }
 
    if (a[s] == 1 || a[t] == 1) {
        cout << -1 << endl;
        return 0;
    }
 
    if (a[s] == a[t]) {
        cout << 2 << endl;
        cout << s << ' ' << t << endl;
        return 0;
    }

    s = a[s];
    t = a[t];

    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(s);

    // cout << mp[6] << endl;

    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &f : fac[x]) {
            for (auto &y : point[f]) {
                // if (y < 10)
                //     cout << ' ' << x << ' ' << f << ' ' << y << ' ' << mp[y] << endl;
                if (!mp[y]) {
                    continue;
                }
                // cout << "*****" << endl;
                if (d[y] > d[x] + 1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                    pre[y] = x;
                }
            }
            point[f].clear();
        }
        fac[x].clear();
    }

    // for (int i = 1; i <= 15; ++i) {
    //     cout << "ddd " << i << ' ' << d[i] << endl;
    // }

    if (d[t] > 1e8) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    do {
        ans.push_back(mp[t]);
        t = pre[t];
    } while (t != s);
    ans.push_back(mp[s]);
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}