#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

struct Node {
    int x, y, z;
    int r;
} a[N];

int n;
int vis[N];
vector<PII> p;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            a[i].x = i;
            a[i].y = (i + 1) % n;
            a[i].z = (i + 2) % n;
            cout << "? " << a[i].x + 1 << ' ' << a[i].y + 1 << ' ' << a[i].z + 1
                 << endl;
            cin >> a[i].r;
        }
        p.clear();
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            if (a[i].r ^ a[(i + 1) % n].r) {
                if (a[i].r) {
                    vis[a[i].x] = 1;
                    vis[a[(i + 1) % n].z] = 0;
                } else {
                    vis[a[i].x] = 0;
                    vis[a[(i + 1) % n].z] = 1;
                }
                p.push_back({a[i].x, a[(i + 1)].z});
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << i + 1 << ' ' << vis[i] << endl;
        // }
        for (int i = 0; i < n; ++i) {
            if (vis[i] > -1) continue;
            for (auto &j : p) {
                if (j.first == i || j.second == i) {
                    continue;
                }
                cout << "? " << j.first + 1 << ' ' << j.second + 1 << ' '
                     << i + 1 << endl;
                cin >> vis[i];
                break;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << i + 1 << ' ' << vis[i] << endl;
        // }
        cout << "!";
        int ans = 0;
        for (int i= 0; i < n; ++i) {
            if (vis[i] == 0) {
                ++ans;
            }
        }
        cout << " " << ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                cout << " " << i + 1;
            }
        }
        cout << endl;
    }
    return 0;
}