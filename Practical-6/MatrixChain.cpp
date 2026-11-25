#include <iostream>
#include <climits>
using namespace std;

class MatrixChain {
private:
    int p[20];
    int n;
    int C[20][20];

public:
    void getInput() {
        cout << "Enter number of matrices: ";
        cin >> n;

        cout << "Enter dimensions: ";

        for (int i = 0; i <= n; i++)
            cin >> p[i];
    }

    void solve() {
        for (int i = 1; i <= n; i++)
            C[i][i] = 0;

        for (int length = 2; length <= n; length++) {
            for (int i = 1; i <= n - length + 1; i++) {
                int j = i + length - 1;
                C[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = C[i][k] + C[k+1][j]
                             + p[i-1] * p[k] * p[j];

                    if (cost < C[i][j])
                        C[i][j] = cost;
                }
            }
        }
    }

    void printTable() {
        cout << "\nDP Table:\n";

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j < i)
                    cout << "-\t";
                else
                    cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void showResult() {
        cout << "\nMinimum number of scalar multiplications = "
             << C[1][n] << endl;
    }
};

int main() {
    MatrixChain m;

    m.getInput();
    m.solve();
    m.printTable();
    m.showResult();

    return 0;
}
