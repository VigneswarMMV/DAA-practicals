#include<iostream>
#include<climits>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;
int minCost = INT_MAX;

void tsp(int current, int count, int cost) {

    if(count == n) {
        if(graph[current][0] != 0) {
            int total = cost + graph[current][0];

            if(total < minCost)
                minCost = total;
        }
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i] && graph[current][i] != 0) {

            visited[i] = 1;

            tsp(i, count+1, cost+graph[current][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    tsp(0, 1, 0);

    if(minCost == INT_MAX)
        cout << "No possible tour exists";
    else
        cout << "Minimum travelling cost = " << minCost;

    return 0;
}
