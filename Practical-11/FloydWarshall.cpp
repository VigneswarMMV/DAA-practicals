#include<iostream>
using namespace std;

#define INF 99999

int main() {
    int n, dist[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (99999 for INF):\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INF &&
                   dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
