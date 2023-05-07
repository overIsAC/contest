#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e4;

int n, a[N];

int main() {
    int T, id;
    cin >> T;
    while (T--) {
        cin >> id >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cout << id << ' ' << (n + 1) / 2 << endl;
        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        for (int i = 1; i <= n; ++i) {
            if (q2.empty() || a[i] < q2.top()) {
                q1.push(a[i]);
            } else {
                q2.push(a[i]);
            }
            while (q1.size() > q2.size() + 1) {
                q2.push(q1.top());
                q1.pop();
            }
            while (q1.size() < q2.size()) {
                q1.push(q2.top());
                q2.pop();
            }
            if (i % 2) {
                int p = (i + 1) / 2;
                cout << q1.top() << ' ';
                if (p % 10 == 0) {
                    cout << endl;
                }
            }
        }
        if ((n + 1) / 2 % 10) {
            cout << endl;
        }
    }

    return 0;
}