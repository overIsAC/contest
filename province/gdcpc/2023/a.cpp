#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, n;
        cin >> x >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        cin >> y;
        int ans = y - x + 1;
        for (auto &i : a) {
            if (y >= i) {
                --ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}