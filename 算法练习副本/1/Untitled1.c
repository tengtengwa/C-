#include <stdio.h>
//��������Ĺ�ʽ����еĽ���ֵ�����㾫��ȡ1E-07��
int main()
{float sum=0.0,i=1.0,a=1.0;
    while(1/i<1e-7)
    {
        sum+=a/i;
        a=a*(-1);
        i+=2;
    }
    sum*=4;
    printf("�е�ֵΪ%.7f",sum);
    return 0;

}
