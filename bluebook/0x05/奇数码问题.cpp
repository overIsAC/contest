#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 500 * 500;

int n, a[N], b[N];
int ans;

void sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + r >> 1;
    sort(l, mid);
    sort(mid + 1, r);
    int u = l, v = mid + 1, w = l;
    while (u <= mid && v <= r) {
        if (a[u] <= a[v]) {
            b[w++] = a[u++];
        } else {
            b[w++] = a[v++];
            ans += mid - u + 1;
        }
    }
    while (u <= mid) {
        b[w++] = a[u++];
    }
    while (v <= r) {
        b[w++] = a[v++];
    }
    for (int i = l; i <= r; ++i) {
        a[i] = b[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        int m = n * n;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            if (!a[i]) {
                --i;
                --m;
            }
        }
        ans = 0;
        sort(1, m);
        int u = ans;
        ans = 0;
        m = n * n;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            if (!a[i]) {
                --i;
                --m;
            }
        }
        ans = 0;
        sort(1, m);
        int v = ans;
        if (u - v & 1) {
            cout << "NIE" << endl;
        } else {
            cout << "TAK" << endl;
        }
    }

    return 0;
}