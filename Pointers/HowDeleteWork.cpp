/*How delete knows how much memory to delete:
*/

#include <bits/stdc++.h>

int const n = 10;

class Base{
       public:
       int b_var ; 

};

int main(){

Base *bp = new Base[n];
/* How the above allocation happens:
1. char* tmp = (char*) operator new[] (WORDSIZE + n*sizeof(Base));
This is like malloc this will allocate memory,Lets say n= 10 so it will allocate  4byte + 4*10 
Here 4 byte is WORDSIZE which is allocated because compiler is 32 bit lets say
so, tmp = 0 1 ...43 i.e point at start(0th) index 

2. Base* bp = (Base*) (tmp + WORDSIZE); .i.e point p at 4th index
So we need memory to allocate 4*10 bytes i.e 40 bytes so we typecast it to base 
so , bp  =4,5,...43


3. Now we have to store this n at [0 3] location ; means in this memory we have to store the size

*(size_t*)tmp = n 

size_t is like integer and if 32 bit system then it is 4 byte and for 64 bit it is 8 byte
now we r converting tmp to integer nd placing out n there
so now  0 to 3 will store size information.


4. Now we have to call constructor as n times
so we loop through n times and call constructor

for(i = 0; i < n; i++){
     new(bp + i ) Base() ; //Placement new
}

Generally we call like new Base(); there our kernel is involved to allocate memory
But here we already got our memory in step 1, so we dont want kernel to be involved, we just need to create object on that memory i.e we r responsible to allocate memory not kernel
when we do bp + i  and lets say i = 1 then it is bp + 1 so keep incrementing 4 bytes with each i.
*/

delete[] bp;

/*
1. Now we need to grab n so that we can call destructor n times
size_t  n = *(size_t*) ((char*)bp - WORDSIZE) ; 
so we decremented p by wordsize, so above we saw that p was pointing to 4th index now here it start pointing to 0th index
and now we grabbed n

2. we have to call destructor n times so we perform while operation in rev order:
while(n--!=0)


3. Since we used placement new to allocate memory so now we have to manually deallocate it
(bp + n) -> Base(); 

so this will call desturctor on last element of this array then second last then third last and so on

4. Dellocate whole array now:

operator delete[] ((char*)bp - WORDSIZE);
*/



