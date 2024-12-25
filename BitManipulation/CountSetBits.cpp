Asked in qualcomm: mistake done was that it did not handle data types like int float i used unsigned char by mistake, 
indeed it was correct but not efficient
code written in qualcomm:
#include <bits/stdc++.h>
using namespace std;



int countSetBits(void *ptr, size_t size){
    
    unsigned char *byte = (unsigned char *)ptr;
    
    int count  = 0 ;
    
    //ilterate through each byte
    for(size_t i = 0 ; i<size; i++){
        unsigned char b = byte[i];
        //count bits in the byte
        while(b){
            count += b & 1;
            b >>= 1;// right shift to 1 bit
        }
    }
    return count ; 
}
//

//Below code is better:
#include <iostream>
using namespace std;

// Function to count the number of set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1; // Increment count if the least significant bit is 1
        n >>= 1;        // Right shift n by 1 bit
    }
    return count;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    int result = countSetBits(num);
    cout << "Number of set bits in " << num << " is: " << result << endl;

    return 0;
}

dry run:
let number be 13: 1101
int count = 0
inside while:
1101 & 0001 = 0001 so lsb is 1 => count = 1
n >>=1    => 1101 right shift by 1 bit => 0110  which is 6 in integer

again :
0110 & 0001 => 0000 so lsb is 1 => count donot increment ans remain at 1
0110 >>=1  => 0011  which is integer 3

again:
0011 & 0001 => 0001 so lsb is 1 => count increment by one and count = 2
0011 >>=1 => 0001 which is integer 1

again:
0001 & 0001 = > 0001 so lsb is 1  => increment count => count = 3
0001 >>=1 => 0000 

now while loop breaks and count remain at 3




