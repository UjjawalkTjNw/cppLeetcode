/*
here we consider ascii value of characters
like small "a" starts from 97 
so logic wise we compute like eg: 'f' -'a' is 102-97 = 5 so f will be stored at 5th index in hash array

eg:
abcdabehf
query q = 5
a
b
h
b
c

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s;

    //precompute
    int hash[26] = {0};
    for(int i = 0 ; i < s.size();i++){
        hash[s[i]- 'a']++;
    }
    /*
      int hash[256] = {0};  /if u are considering  string has capital and small letters both 
    for(int i = 0 ; i < s.size();i++){
        hash[s[i]]++;
    }
    */

    int q;// query
    cin >> q;

    while(q--){
        char c;
        cin >> c;

        //fetch 
        cout << hash[c - 'a'] << endl ;
        //here you do hash[c -'a'] only if u consider string has small letters and hash array is hash[26];
        // but if u consider has array to contain all characters(small and capital letters) the hash array 
        //will be of 256 size ; hash[256]
        //in that case we do cout << hash[c] << endl;


    }
    return 0;
}