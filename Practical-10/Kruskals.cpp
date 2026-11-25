#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 20

struct Edge {
    int u, v, w;
};

Edge edge[MAX];
int parent[MAX];

int find(int x) {
    while(parent[x] != x)
        x = parent[x];

    return x;
}

void Union(int a, int b) {
    parent[a] = b;
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int v, e, totalCost = 0;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter Source Destination Weight:\n";

    for(int i = 0; i < e; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    for(int i = 0; i < v; i++)
        parent[i] = i;

    sort(edge, edge+e, compare);

    cout << "\nEdges in Minimum Spanning Tree:\n";

    int count = 0;

    for(int i = 0; i < e && count < v-1; i++) {
        int p1 = find(edge[i].u);
        int p2 = find(edge[i].v);

        if(p1 != p2) {
            Union(p1, p2);

            cout << edge[i].u << " --> "
                 << edge[i].v
                 << " Cost = " << edge[i].w << endl;

            totalCost += edge[i].w;
            count++;
        }
    }

    if(count != v-1)
        cout << "MST does not exist";
    else
        cout << "\nMinimum Cost = " << totalCost;

    return 0;
}
