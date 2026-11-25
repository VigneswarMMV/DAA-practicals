#include <iostream>
#include <algorithm>
using namespace std;

class Knapsack {
private:
    int w[10], v[10];
    int n, W;
    int dp[10][100];

public:
    void getInput() {
        cout << "Enter number of items: ";
        cin >> n;

        cout << "Enter knapsack capacity: ";
        cin >> W;

        for (int i = 1; i <= n; i++) {
            cout << "Item " << i << " weight and value: ";
            cin >> w[i] >> v[i];
        }
    }

    void solve() {
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= W; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (w[i] <= j) {
                    dp[i][j] = max(
                        v[i] + dp[i-1][j-w[i]],
                        dp[i-1][j]
                    );
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    void printTable() {
        cout << "\nDP Table:\n";

        for (int j = 0; j <= W; j++)
            cout << j << " ";

        cout << endl;

        for (int i = 0; i <= n; i++) {
            cout << "i=" << i << " ";

            for (int j = 0; j <= W; j++)
                cout << dp[i][j] << " ";

            cout << endl;
        }
    }

    void showResult() {
        cout << "\nMaximum Value = " << dp[n][W] << endl;
    }

    void findItems() {
        cout << "\nSelected Items:\n";
        int j = W;

        for (int i = n; i >= 1; i--) {
            if (dp[i][j] != dp[i-1][j]) {
                cout << "Item " << i << " TAKEN\n";
                j -= w[i];
            } else {
                cout << "Item " << i << " NOT taken\n";
            }
        }
    }
};

int main() {
    Knapsack k;

    k.getInput();
    k.solve();
    k.printTable();
    k.showResult();
    k.findItems();

    return 0;
}
