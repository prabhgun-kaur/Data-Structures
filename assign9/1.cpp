#include <iostream>
#include <climits>
using namespace std;

#define MAXV 100  

int V;  
int adj[MAXV][MAXV]; 
bool visited[MAXV];


void BFS(int src) {
    bool used[MAXV] = {false};
    int q[MAXV];
    int front = 0, rear = 0;
    used[src] = true;
    q[rear++] = src;
    cout << "BFS from " << src << ": ";
    while (front < rear) {
        int u = q[front++];
        cout << u << " ";
        for (int v = 0; v < V; v++) {
            if (!used[v] && adj[u][v] != 0) {
                used[v] = true;
                q[rear++] = v;
            }
        }
    }
    cout << "\n";
}


void DFS_util(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < V; v++) {
        if (!visited[v] && adj[u][v] != 0) {
            DFS_util(v);
        }
    }
}

void DFS(int src) {
    for (int i = 0; i < V; i++) visited[i] = false;
    cout << "DFS from " << src << ": ";
    DFS_util(src);
    cout << "\n";
}

void primMST() {
    bool inMST[MAXV] = {false};
    int key[MAXV];
    for (int i = 0; i < V; i++) key[i] = INT_MAX;
    key[0] = 0;

    for (int cnt = 0; cnt < V; cnt++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        if (u == -1) break;  
        inMST[u] = true;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && adj[u][v] != 0 && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    cout << "Prim MST (approximate via key weights): \n";
    for (int i = 1; i < V; i++) {
        cout << "Key[" << i << "] = " << key[i] << "\n";
    }
}


void dijkstra(int src) {
    bool used[MAXV] = {false};
    int dist[MAXV];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1, minDist = INT_MAX;
        for (int j = 0; j < V; j++) {
            if (!used[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        used[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !used[v] && dist[u] != INT_MAX
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra distances from " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) cout << src << " -> " << i << " = INF\n";
        else cout << src << " -> " << i << " = " << dist[i] << "\n";
    }
}

int main() {
    
    cout << "Enter number of vertices (<= " << MAXV << "): ";
    cin >> V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    int E;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges in format: u v w  (0-based indices, w=0 means unweighted edge)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;  
    }

    BFS(0);
    DFS(0);
    primMST();
    dijkstra(0);

    return 0;
}
