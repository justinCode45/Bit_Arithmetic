
#include <iostream>
using namespace std ;
int adder(int& a,int& b){
    //串行進位全加法器
    int an=0;
    int cin=0;
    int power=0;
    while (a>0 or b>0){
        if ((a%2^b%2^cin)!=0){
            an=(an|(1<<power));
        }
        cin= (a%2&b%2|(a%2^b%2)&cin);
        a>>=1;
        b>>=1;
        int m=1;
        while( power & m ){
            power = power ^ m;
            m <<= 1;
        }
        power = power ^ m;
    }
    if (cin !=0){
        an=(an|(1<<power));
    }
    return an;
}



