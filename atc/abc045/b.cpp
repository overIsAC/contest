#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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

map<char, string> mp;

int main() {
    char now = 'a';
    for (int i = 'a'; i < 'd'; ++i) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        mp[i] = s;
    }
    while (mp[now].size()) {
        int p = mp[now].back();
        mp[now].pop_back();
        now = p;
    }
    cout << (char)toupper(now) << endl;
    return 0;
}