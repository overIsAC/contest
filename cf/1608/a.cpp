#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 2; i <= n + 1; ++i) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}