#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coin[n];

    cout << "Enter coin denominations: ";

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    cout << "Enter amount: ";
    cin >> amount;

    int dp[amount+1];

    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        dp[i] = 32767;

        for(int j = 0; j < n; j++) {
            if(coin[j] <= i && dp[i-coin[j]] != 32767) {
                dp[i] = min(dp[i],
                            dp[i-coin[j]]+1);
            }
        }
    }

    if(dp[amount] == 32767)
        cout << "Amount cannot be formed";
    else
        cout << "Minimum number of coins required = "
             << dp[amount] << endl;

    return 0;
}
