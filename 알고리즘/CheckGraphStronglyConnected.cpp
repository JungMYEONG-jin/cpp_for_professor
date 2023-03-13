class Graph
{
    int V;    // No. of vertices
    list<int>* adj;    // An array of adjacency lists

    // A recursive function to print DFS starting from v
    void BFSUtil(int v, bool visited[]);
public:

    // Constructor and Destructor
    Graph(int V) { this->V = V;  adj = new list<int>[V]; }
    ~Graph() { delete[] adj; }

    // Method to add an edge
    void addEdge(int v, int w);

    // The main function that returns true if the
    // graph is strongly connected, otherwise false
    bool isSC();

    // Function that returns reverse (or transpose)
    // of this graph
    Graph getTranspose();
};


Graph Graph::getTranspose() {
    Graph g(V);
    for (int i = 0; i < V; i++) {
        for (auto num : adj[i]) {
            g.adj[num].push_back(i);
        }
    }
    return g;
}

void Graph::BFSUtil(int v, bool visited[]) {
    list<int> q;
    q.push_back(v);
    visited[v] = true;

    while (!q.empty()) {
        auto it = q.front();
        q.pop_front();

        for (auto num : adj[it]) {
            if (!visited[num]) {
                q.push_back(num);
                visited[num] = true;
            }
        }
    }
}

bool Graph::isSC() {
    bool visited[V];
    fill(visited, visited + V, false);

    BFSUtil(0, visited);

    // all visit check
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            return false;
    }

    // reverse
    Graph g = getTranspose();

    fill(visited, visited + V, false);

    g.BFSUtil(0, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}
