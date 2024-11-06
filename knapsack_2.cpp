#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the knapsack problem
int knapsack(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    
    // Create a 2D dp table initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp table
    for (int item = 1; item <= n; ++item) {
        for (int weight = 1; weight <= capacity; ++weight) {
            if (weights[item - 1] <= weight) {
                dp[item][weight] = max(dp[item - 1][weight - weights[item - 1]] + values[item - 1], dp[item - 1][weight]);
            } else {
                dp[item][weight] = dp[item - 1][weight];
            }
        }
    }

    // Return the maximum value
    return dp[n][capacity];
}

int main() {
    while (true) {
        cout << "Press Ctrl+C to terminate..." << endl;
        
        int n;
        cout << "Enter number of items: ";
        cin >> n;

        vector<int> values(n), weights(n);

        cout << "Enter values of items: ";
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        cout << "Enter weights of items: ";
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }

        int capacity;
        cout << "Enter maximum weight: ";
        cin >> capacity;

        // Call the knapsack function
        int maximum_value = knapsack(values, weights, capacity);

        // Output the result
        cout << "The maximum value of items that can be carried: " << maximum_value << endl;
    }

    return 0;
}
