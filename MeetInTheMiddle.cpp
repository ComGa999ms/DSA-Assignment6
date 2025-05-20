#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define p2i pair<int,pii>
#define endl "\n"

using namespace std;

const int N = 2e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

int n, s, m, k;
int a[N], b[N], s1[N], s2[N];
int n1, n2, res;

void Try(int i, int sum, int a[], int n, int d[], int &id) {
    rep(j, i, n) {
        d[++id] = sum + a[j];
        if (d[id] == s) res++;
        Try(j + 1, d[id], a, n, d, id);
    }
}

void solve(void) {
    cin >> n >> s;
    rep(i, 1, n) {
        int x; cin >> x;
        if (i <= n / 2) a[++m] = x;
        else b[++k] = x;
    }

    Try(1, 0, a, m, s1, n1);
    Try(1, 0, b, k, s2, n2);

    sort(s2 + 1, s2 + 1 + n2);
    rep(i, 1, n1) {
        int L = lower_bound(s2+1, s2+1+n2, s-s1[i])-s2;
        if (L > n2 || s2[L] + s1[i] != s) continue;
        int R = upper_bound(s2+1, s2+1+n2, s-s1[i])-s2;
        res += (R - L);
    }
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}