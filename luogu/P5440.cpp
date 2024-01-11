#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;
int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ans;
string s;
vector<int> p;
int v[N];

int isPrime(int n) {
    if (n < N) {
        return !v[n];
    }
    for (auto& i : p) {
        if (i * i > n) {
            break;
        }
        if (n % i == 0) {
            return 0;
        }
    }
    return n > 1;
}

int toInt(int a, char b) {
    return a * 10 + b - '0';
}

template <typename T, typename... U>
int toInt(int a, T b, U... c) {
    return toInt(a * 10 + b - '0', c...);
}

template <typename... U>
int toInt(U... b) {
    return toInt(0, b...);
}

int toInt(vector<char> a) {
    int ans = 0;
    for (auto& i : a) {
        ans = ans * 10 + i - '0';
    }
    return ans;
}

void updateLeap(int y) {
    if (y % 4 == 0 && y % 100 || y % 400 == 0) {
        month[2] = 29;
    } else {
        month[2] = 28;
    }
}

void dfs(int p) {
    if (p == 2) {
        int z = toInt({s[1], s[0]});
        if (!(1 <= z && z <= 31)) {
            return;
        }
        if (!isPrime(z)) {
            return;
        }
    }
    if (p == 4) {
        int z = toInt({s[3], s[2]});
        if (!(1 <= z && z <= 12)) {
            return;
        }
        z = toInt(s[3], s[2], s[1], s[0]);
        if (!isPrime(z)) {
            return;
        }
    }
    if (p == 8) {
        int y = toInt(s[7], s[6], s[5], s[4]), m = toInt(s[3], s[2]), d = toInt(s[1], s[0]);

        if (!(1 <= y && y <= 9999)) {
            return;
        }

        updateLeap(y);

        if (!(1 <= d && d <= month[m])) {
            return;
        }
        if (!isPrime(toInt(vector(s.rbegin(), s.rend())))) {
            return;
        }
        ++ans;
        return;
    }
    if (isdigit(s[p])) {
        dfs(p + 1);
    } else {
        for (char i = '0'; i <= '9'; ++i) {
            s[p] = i;
            dfs(p + 1);
        }
        s[p] = '-';
    }
}

int main() {
    v[1] = v[0] = 1;
    for (int i = 2; i < N; ++i) {
        if (!v[i]) {
            p.push_back(i);
        }
        for (int j = i + i; j < N; j += i) {
            v[j] = 1;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        reverse(s.begin(), s.end());

        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}