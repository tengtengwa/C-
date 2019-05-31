










/*

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,i,j,t=2,m;
    int *p;
    char s[500]={0};
    s[1]=1;
    while(scanf("%d",&n))
    {
        if(n==1) printf("1\n");
        else
        {
            for(i=2;i<=n;i++)
            {
                p=i;
                s[i]=*p;
                m=0;
                for(j=2;j<=n;j++) s[j+1]=s[m++];
            }
        printf("%s\n",s);
        }

    }


}

*/

/*

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int a[255]={0},i,min,t,sum=0;
    char s[50];

    while(scanf("%s",s))
    {
        for(i=0;i<strlen(s);i++)
        {
            t=s[i]-0;
            a[t]++;
        }


        for(i=0;i<=255;i++)
        {
            if(a[i]!=0) sum++;  //×ÖÄ¸×ÜÊý
        }
        while(sum!=0)
        {
            for(i=0;i<256;i++) if(a[i]!=0) min=i;
            for(i=0;i<256;i++)
            {
                if(a[i]!=0) if(a[i]<a[min]) min=i;
            }
            printf("%c",min);
            a[min]=0;
            sum--;
        }
        printf("\n");

    }

}

*/

