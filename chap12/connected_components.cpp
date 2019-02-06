#include<iostream>
#include<vector>
using namespace std;
static const int MAX = 100000;
static const int NIL = -1;

int n;
vector<int> G[MAX]; // List of vectors
int color[MAX];

void dfs_visit(int v, int id) {
    color[v] = id;
    for (int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (color[u]==NIL) {
            dfs_visit(u, id);
        }
    }
}

void dfs() {
    for (int v=0; v<n; v++) {
        color[v] = NIL;
    }
    int id = 0; // Cluster id
    for (int v=0; v<n; v++) {
        if (color[v]==NIL) {
            // If not clustered yet
            dfs_visit(v, id++);
        }
    }
}

int main() {
    int s,t,m,q;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs();

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> s >> t;
        if (color[s]==color[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

 return 0;
}