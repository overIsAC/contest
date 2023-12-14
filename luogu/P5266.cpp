#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

map<string, int> mp;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int op, score;
        string name;
        cin >> op;
        if (op == 1) {
            cin >> name >> score;
            mp[name] = score;
            cout << "OK" << endl;
        } else if (op == 2) {
            cin >> name;
            if (mp.count(name)) {
                cout << mp[name] << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if (op == 3) {
            cin >> name;
            if (mp.count(name)) {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else {
            cout << mp.size() << endl;
        }
    }
    return 0;
}