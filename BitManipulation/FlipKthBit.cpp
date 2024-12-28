#include <bits/stdc++.h>
using namespace std;

int flipBits(int n, int k){
    int m = 1 << (k-1);
    return m ^ n;
}

int main() {
	int num = 13;
	int k = 4;
	int result = flipBits(num, k);
	cout << result;
}


/*
Dry run:
k =4 
int m = 1 <<(4-1)   => 1 <<3  =>0001 << 3 i.e left shift 1 by 3 bit => 1000

now do xor of 1000 with 1101

1000
1101
------
0101 which is 5 ans