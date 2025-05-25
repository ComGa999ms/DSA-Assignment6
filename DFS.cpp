#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define sz(v) (int)(v).size()
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

int n, m;
map <char, int> e;
vector<int> adj[N];
char b[N];
bool vis[N];
int trace[N];
vector <char> path, res;
bool ok = 0;

void dfs(int u, int en) {
    vis[u] = 1;
    path.push_back(b[u]);

    if (u == en) {          
        // repd(i, sz(path) - 1, 0) cout << path[i] << ' '; cout << endl;
        if (sz(res) > sz(path) || sz(res) == 0) res = path;
        ok = 1;
    }
    for (int v : adj[u]) if (!vis[v]) {
        dfs(v, en);
    }

    vis[u] = 0;
    path.pop_back();
}

void solve(void) {
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> b[i];
        e[b[i]] = i;
    }
    
    rep(i, 1, m) {
        char u, v;
        cin >> u >> v;
        
        adj[e[u]].push_back(e[v]);
    }

    int ntest;
    cin >> ntest;
    while (ntest--) {
        char x, y;
        cin >> x >> y;
        
        if (x == y) {
            cout << x << ' ' << x << endl;
            continue;
        }

        ok = 0;
        rep(i, 1, n) vis[i] = 0;
        res.clear();  path.clear();
        dfs(e[x], e[y]);

        if (ok == 0) cout << "no_path" << endl;
        else {
            for (auto T : res) cout << T << ' '; cout << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();

    return 0;
}