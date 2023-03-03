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
const int N = 3 + 1e5;

int main() {
    int ref[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

    // for (int i = 0; i <= 9; ++i) {
    //     cout << i << ' ' << ref[i] << endl;
    // }
    int T;
    cin >> T;
    while (T--) {
        int h, m;
        int H, M;
        cin >> h >> m;
        string s;
        cin >> s;
        H = (s[0] - '0') * 10 + s[1] - '0';
        M = (s[3] - '0') * 10 + s[4] - '0';

        auto valid = [&]() {
            if (ref[H / 10] == -1 || ref[H % 10] == -1 || ref[M / 10] == -1 || ref[M % 10] == -1) {
                return false;
            }
            int hh = ref[M % 10] * 10 + ref[M / 10];
            int mm = ref[H % 10] * 10 + ref[H / 10];
            return hh < h && mm < m;
        };

        // cout << valid() << endl;

        // cout << H << " " << M << ' ' << s << endl;
        while (!valid()) {
            ++M;
            if (M == m) {
                ++H;
                M = 0;
            }
            H %= h;
            // printf("%02d:%02d\n", H, M);
            // printf("%02d:%02d\n", ref[M % 10] * 10 + ref[M / 10], ref[H % 10] * 10 + ref[H / 10]);
            // printf(" |||| %02d:%02d\n", H, M);
        }
        // cout << H << " " << M << endl;
        // printf("%02d:%02d\n", ref[M % 10] * 10 + ref[M / 10], ref[H % 10] * 10 + ref[H / 10]);
        printf("%02d:%02d\n", H, M);
    }
    return 0;
}