#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
    // DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table (bottom-up)
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 🧠 Backtrack to find which items were chosen
    int res = dp[n][W];
    int w = W;
    vector<int> chosenItems;

    for (int i = n; i > 0 && res > 0; i--) {
        // If item i was included
        if (res != dp[i - 1][w]) {
            chosenItems.push_back(i - 1); // store index
            res -= value[i - 1];
            w -= weight[i - 1];
        }
    }

    // 🟢 Print chosen items
    cout << "\nItems taken (value, weight):\n";
    for (int i = chosenItems.size() - 1; i >= 0; i--) {
        int idx = chosenItems[i];
        cout << "Value: " << value[idx] << ", Weight: " << weight[idx] << endl;
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> value(n), weight(n);
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter maximum weight of knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, weight, value, n);
    cout << "\nMaximum value in Knapsack = " << maxValue << endl;

    return 0;
}
