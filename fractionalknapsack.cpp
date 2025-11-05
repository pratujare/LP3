#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double knapsack(int W, vector<Item> &arr) {
    sort(arr.begin(), arr.end(), comp);
    int currWt = 0;
    double finalVal = 0;
    
    cout << "\nValue\tWeight\tValue Taken\tWeight Taken\n";
    for (int i = 0; i < arr.size(); i++) {
        if (currWt + arr[i].weight < W) {
            currWt += arr[i].weight;
            finalVal += arr[i].value;
            cout << arr[i].value << "\t" << arr[i].weight << "\t" << arr[i].value << "\t\t" << arr[i].weight << "\n";
        } else {
            int remain = W - currWt;
            double fractionVal = (arr[i].value / (double)arr[i].weight) * remain;
            finalVal += fractionVal;
            cout << arr[i].value << "\t" << arr[i].weight << "\t" << fractionVal << "\t\t" << fixed << setprecision(2) << remain << "\n";
            break;
        }
    }
    return finalVal;
}

int main() {
    int n, W;
    cout << "Enter no. of items: ";
    cin >> n;
    vector<Item> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }
    
    cout << "Enter maximum weight: ";
    cin >> W;
    
    double ans = knapsack(W, arr);
    cout << "Maximum value: " << fixed << setprecision(2) << ans;
    
    return 0;
}