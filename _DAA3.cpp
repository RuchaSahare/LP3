#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum profit for the fractional knapsack problem
double fractionalKnapsack(int W, vector<int>& values, vector<int>& weights) {
    int n = values.size();
    vector<int> indices(n);
    
    // Initialize indices
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Sort items by their value-to-weight ratio using indices
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        double r1 = (double)values[i] / weights[i];
        double r2 = (double)values[j] / weights[j];
        return r1 > r2;
    });

    double maxProfit = 0.0;

    // Pick items in order of highest value-to-weight ratio
    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        if (weights[idx] <= W) {
            // Take the whole item
            maxProfit += values[idx];
            W -= weights[idx];
        } else {
            // Take the fraction of the remaining weight
            maxProfit += values[idx] * ((double)W / weights[idx]);
            break; // Knapsack is full
        }
    }

    return maxProfit;
}

int main() {
    int n, W;
    
    // Input the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    // Input values and weights
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // Input knapsack capacity
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    double maxProfit = fractionalKnapsack(W, values, weights);
    cout << "Maximum profit in the knapsack = " << maxProfit << endl;

    return 0;
}
