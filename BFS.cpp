#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define sz(v) (int)(v).size()
#define vii vector <char>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

map <char, vii> adj;

int n, m;
vii e;

void BFS(char source, char sink) {
    map <char, bool> used;
    map <char, char> trace;
    queue <char> q;

    for (auto T : adj) used[T.first] = 0;
    
    q.push(source);
    trace[source] = '\0';

    while (q.size()) {
        char u = q.front(); q.pop();

        if (adj.find(u) != adj.end()) {
            for (char v : adj[u]) {
                if (!used[v]) {
                    used[v] = 1;
                    trace[v] = u;
                    q.push(v);

                    if (v == sink) {
                        vii path;
                        char node = sink;

                        path.push_back(sink);
                        while (trace[node] != source) {
                            node = trace[node];
                            path.push_back(node);
                        }
                        path.push_back(source);
                    
                        repd(i, sz(path) - 1, 0) cout << path[i] << ' '; cout << endl;
                        return ;
                    }
                }
            }
        }
    }
    cout << "no_path" << endl;
}

void solve(void) {
    cin >> n >> m;
    
    rep(i, 1, n) {
        char c; cin >> c;
        e.push_back(c);
    }
    
    for (auto T : e) adj[T].clear();
    rep(i, 1, m) {
        char u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    int ntest;
    cin >> ntest;

    while (ntest-- ) {
        char u, v;
        cin >> u >> v;
        
        if (adj.find(u) == adj.end() || adj.find(v) == adj.end()) {
            cout << "no_path" << endl;
            continue;
        }

        BFS(u, v);
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