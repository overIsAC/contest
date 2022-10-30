#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

struct Node {
    int x, y, z;
} a[N], b[N];

int n;
int vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].x;
            a[i].z = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].y;
            b[i] = a[i];
        }
        sort(a + 1, a + n + 1,
             [](const Node &a, const Node &b) { return a.x < b.x; });
        sort(b + 1, b + n + 1,
             [](const Node &a, const Node &b) { return a.y < b.y; });
        vis[a[n].z] = vis[b[n].z] = 1;
        int p1 = n, p2 = n;
        int mn1 = min(a[n].x, b[n].x);
        int mn2 = min(a[n].y, b[n].y);
        while (true) {
            if (p1 - 1 >= 1 && vis[a[p1 - 1].z]) {
                --p1;
                continue;
            }
            if (p2 - 1 >= 1 && vis[b[p2 - 1].z]) {
                --p2;
                continue;
            }
            if (p1 - 1 >= 1 && a[p1 - 1].x > mn1) {
                --p1;
                vis[a[p1].z] = true;
                mn1 = min(mn1, a[p1].x);
                mn2 = min(mn2, a[p1].y);
                continue;
            }
            if (p2 - 1 >= 1 && b[p2 - 1].y > mn2) {
                --p2;
                vis[b[p2].z] = true;
                mn1 = min(mn1, b[p2].x);
                mn2 = min(mn2, b[p2].y);
                continue;
            }
            break;
        }
        for (int i = 1; i <= n; ++i) {
            cout << vis[i];
        }
        cout << endl;  
    }
    return 0;
}
// 3
// 5 2 3
// 4 3 1