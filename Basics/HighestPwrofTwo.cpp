#include <iostream>
using namespace std;

int highestPowerOf2(int n) {
    int res = 1;
    while (res <= n) {
        res <<= 1; // Shift left by 1 (equivalent to multiplying by 2)
    }
    return res >> 1; // Shift right by 1 to get the largest power of 2 ≤ n
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The highest power of 2 less than or equal to " << n << " is " << highestPowerOf2(n) << endl;
    return 0;
}
// eg: n =19
//2^2 = 4 , 2^3 =8 , 2^4 =16 , 2^5 =32
//Therefore, 16 is highest power of two which is less than 19
//res = 1
//1<=19:  left shift by one bit so it become: 10 which is equal to 2
//2<=19 left shift by one bit so it become 100 which is equal to 4
//4<=19 left shift by one bit so it become 1000 which is equal to 8 
//8<=19 left shift by one bit so it become 10000 which is equal to 16
//16<=19 left shift by one bit so it become 100000 which is equal to 32
//now 32 is greater than 19 so highest was 16 and since 32 >19 so while loop will not trun 
//so after loop is exited we have 32 but we need 16 so right shift by one bit i.e: 100000 right shift it by 1 bit 
// which makes it 10000 and it will be answer