#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    if (!b) {
        if (a > 1 || k) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << "0\n0" << endl;
        }
        return 0;
    }

    string q = "1", w = "1";

    --b;
    if (k) {
        --a;
        --b;
        --k;
        if (a < 0 || b < 0) {
            cout << "No" << endl;
            return 0;
        }
        q += "1";
        w += "0";
        while (k--) {
            if (b) {
                --b;
                q += '1';
                w += '1';
            } else if (a) {
                --a;
                q += '0';
                w += '0';
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
        q += '0';
        w += '1';
    }
    while (b) {
        --b;
        q += '1';
        w += '1';
    }

    while (a) {
        --a;
        q += '0';
        w += '0';
    }

    cout << "Yes" << endl;
    cout << q << endl;
    cout << w << endl;
    
    return 0;
}