#include <stdio.h>

double myPow(double x, int n) {
    if(n == 0)
        return x;
    else if(n<0){
        n = -n;
        x = 1/x;
    }
    double result = 1;
    while(n>0){
        if(n&1)
            result *= x;
        n /= 2;
        x *= x;
    }
    return result;
}

int 
main()
{
    printf("%f\n", myPow(2,10));
    return 0;
}