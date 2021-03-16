#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define vi vector<int>
#define mii map<int,int>
using namespace std;
int n, m;
long double dp[1001][1001];
set <pair<int, int>> v;

// int Ceil_check(long double x) {
//     if (x == (int)x) {
//         return 0;
//     }
//     else {
//         return 1;
//     }
// }

long double rec(int i, int j) {
    if (dp[i][j] != -1.0) {
        return dp[i][j];
    }

    if (i == m && j == n) {
        return 0.0;
    }
    long double ans = 10000000.00;
    long double e = sqrt(20000);
    pair<int, int> ar;
    ar.first = i + 1;
    ar.second = j + 1;
    if (v.find(ar) != v.end()) {
        if (i + 1 <= m && j + 1 <= n) {
            ans = min(ans, e + rec(i + 1, j + 1));
        }
    }

    if (i + 1 <= m) {
        ans = min(ans, 100 + rec(i + 1, j));
    }
    if (j + 1 <= n) {
        ans = min(ans, 100 + rec(i, j + 1));
    }
    // cout << i << " HI " << j << " " << ans << "\n";
    dp[i][j] = ans;
    return ans;
}


void solve() {
    cin >> n >> m;
    int k, i, j, x, y;
    cin >> k;
    i = 0;
    while (i < k) {
        cin >> x >> y;
        pair<int, int> s;
        s.first = y;
        s.second = x;
        v.insert(s);
        i = i + 1;
    }
    i = 0;
    while (i <= m) {
        j = 0;
        while (j <= n) {
            dp[i][j] = -1.0;
            j = j + 1;
        }
        i = i + 1;
    }
    long double r = rec(0, 0);
    cout << round(r) << "\n";
}


int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    solve();
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}