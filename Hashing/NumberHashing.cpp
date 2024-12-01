/*Description
N= 5 elements in array
Array 1 3 2 1 3
q= 5 Queries like:
1
4
2
3
12*/ //Run it on codechef compiler enter all above things as it is above


#include <bits/stdc++.h>
using namespace std;
//here we can make a global hash map upto 10^7 if we are not making inside int main while precompute
// int hash[10000000];

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute
    int hash[13] = {0}; //this hash map can only be 10^6 inside int main
    //we can write it like int hash[1000000] here but cant like int hash[10000000] because it will give segmentation
    //error

    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q; // Query count
    cin >> q;
    while (q--) {
        int number;
        cin >> number;

        if (number < 0 || number >= 13) {
            // Handle out-of-bounds queries
            cout << "0" << endl;
        } else {
            // Fetch the frequency from the hash array
            cout << hash[number] << endl;
        }
    }

    return 0;
}
