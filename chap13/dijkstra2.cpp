#include<algorithm>
#include<queue>
using namespace std;
static const int MAX = 10000;
static const int INFTY = (1<<20);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX]; // Adjacency list

void dijkstra(int s) {
    priority_queue<pair<int, int> > PQ;
    int color[n], d[n], p[n];
    for (int i=0; i<n; i++) {
        color[i] = WHITE;
        d[i] = INFTY;
    }
    d[s] = 0;
    PQ.push(make_pair(0, s));
    color[s] = GRAY;

    while (!PQ.empty()) {
        pair<int, int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        color[u] = BLACK;
        if (d[u] < f.first * (-1)) {
            continue; // Not the minimum
        }

        for (int j=0; j<adj[u].size(); j++) {
            int v = adj[u][j].second;
            if (color[v]==BLACK) {
                continue;
            }
            int tmp = d[u] + adj[u][j].first;
            if (tmp < d[v]) {
                d[v] = tmp;
                color[v] = GRAY;
                PQ.push(make_pair(d[v]*(-1), v)); // Descending order
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d %d\n", i, d[i]);
    }
}

int main() {
    scanf("%d", &n);
    int u, k, v, c;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &u, &k);
        for (int j=0; j<k; j++) {
            scanf("%d %d", &v, &c);
            adj[u].push_back(make_pair(c, v));
        }
    }
 
    dijkstra(0);
    return 0;
}