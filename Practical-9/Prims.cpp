#include<iostream>
using namespace std;

#define MAX 20
#define INF 9999

int main() {
    int graph[MAX][MAX];
    int selected[MAX];

    int n, edge = 0, cost = 0;
    int x = 0, y = 0, min;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter Cost Adjacency Matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for(int i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while(edge < n-1) {
        min = INF;

        for(int i = 0; i < n; i++) {
            if(selected[i]) {
                for(int j = 0; j < n; j++) {
                    if(!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(min == INF) {
            cout << "Graph is disconnected";
            return 0;
        }

        cout << x << " --> " << y
             << " Cost = " << min << endl;

        cost += min;
        selected[y] = 1;
        edge++;
    }

    cout << "\nMinimum Cost = " << cost;

    return 0;
}
