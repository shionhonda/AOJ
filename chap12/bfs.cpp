#include<iostream>
#include<queue>
#include <limits>
using namespace std;
#define N 100

int inf = numeric_limits<int>::max();
int n, M[N][N], d[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    for (int i; i<n; i++) {
        d[i] = inf;
    }
    d[s] = 0;
    int u;
    while (!q.empty()) {
        u = q.front(); // Get the first element
        q.pop();
        for (int v=0; v<n; v++) {
            if (M[u][v]==0) {
                continue;  
            }
            if (d[v]!=inf) {
                // Already visited
                continue;
            }
            d[v] = d[u] +1;
            q.push(v);
        }
    }
    for (int i=0; i<n; i++) {
        if (d[i]!=inf) {
            cout << i+1 << " " << d[i] << endl;
        } else {
            cout << i+1 << " " << -1 << endl;
        }
    }
}

int main() {
    int u, k, tmp;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            M[i][j] = 0;
        }
    }
    // Directed graph
    for (int i=0; i<n; i++) {
        cin >> u >> k;
        for (int j=0; j<k; j++) {
            cin >> tmp;
            M[u-1][tmp-1] = 1;
        }
    }

    bfs(0);
    return 0;
}