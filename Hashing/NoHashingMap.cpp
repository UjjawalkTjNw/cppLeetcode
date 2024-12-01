#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute
    map<int, int> mpp;  //for unordered map just do unordered<int,int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q; // Query count
    cin >> q;
    while (q--) {
        int number;
        cin >> number;

        // Fetch
        cout << mpp[number] << endl;
    }

    return 0;
}
