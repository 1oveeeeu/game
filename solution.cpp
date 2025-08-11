#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
long long total_sum = 0;

// Build the rooted tree structure
void build_tree(int node, int parent, vector<vector<int>>& tree) {
    for (int child : adj[node]) {
        if (child != parent) {
            tree[node].push_back(child);
            build_tree(child, node, tree);
        }
    }
}

// DFS to collect all nodes in subtree rooted at 'node'
void collect_subtree(int node, const vector<vector<int>>& tree, vector<int>& nodes) {
    nodes.push_back(node);
    for (int child : tree[node]) {
        collect_subtree(child, tree, nodes);
    }
}

// Calculate fixed points for a given set of nodes
int calculate_fixed_points(vector<int>& nodes) {
    vector<int> sorted_nodes = nodes;
    sort(sorted_nodes.begin(), sorted_nodes.end());
    
    int fixed_points = 0;
    for (int i = 0; i < sorted_nodes.size(); i++) {
        if (sorted_nodes[i] == i + 1) {
            fixed_points++;
        }
    }
    return fixed_points;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Build rooted tree with root = n
    vector<vector<int>> tree(n + 1);
    build_tree(n, -1, tree);
    
    // For each node, calculate its subtree weight in the rooted tree
    for (int root = 1; root <= n; root++) {
        vector<int> nodes;
        collect_subtree(root, tree, nodes);
        total_sum += calculate_fixed_points(nodes);
    }
    
    cout << total_sum << endl;
    
    return 0;
}