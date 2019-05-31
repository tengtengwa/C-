#include <stdio.h>
//利用下面的公式计算π的近似值，计算精度取1E-07。
int main()
{float sum=0.0,i=1.0,a=1.0;
    while(1/i<1e-7)
    {
        sum+=a/i;
        a=a*(-1);
        i+=2;
    }
    sum*=4;
    printf("π的值为%.7f",sum);
    return 0;

}
