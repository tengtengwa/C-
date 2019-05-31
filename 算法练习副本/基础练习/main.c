














/*

//计算多项式1-1/2+1/3-1/4+.....+1/99-1/100的值
#include <stdio.h>
int main()
{
    float sum=1,i,sign=1;

    for(i=2;i<=100;i++)
    {
        sign=-sign;
        sum+=sign/i;
    }
    printf("%f\n",sum);
}

*/



/*

#include <stdio.h>
int main()
{
    int i,j,k;
    for (i=0;i<4;i++)
    {
        for (j=0;j<3-i;j++)
        printf(" ");
        for (k=0;k<=2*i;k++)
            printf("*");
        printf("\n");
    }
    for (i=0;i<3;i++)
    {
        for (j=0;j<=i;j++)
        printf(" ");
        for (k=0;k<=4-2*i;k++)
            printf("*");
        printf("\n");
    }
    return 0;
}

*/





/*

//求1！+2！+3！+......+20！的值
#include <stdio.h>
int main()
{
    int i;
    float sum=0.0,t=1;

    for(i=1;i<=20;i++)
    {
        t*=i;
        sum+=t;
    }
    printf("%f\n",sum);
}

*/



/*

//strlen函数
#include <stdio.h>
char strcpy(char *a,const char *b)
{
    while(*b!='\0')
    {
        *a++=*b++;
    }
    *a=0;
}

int main()
{
    char a[20],b[20];
    gets(b);
    strcpy(a,b);
    printf("%s\n",a);
}

*/


/*

//计算下列式子前20项的和：1+1/2+2/3+3/5+5/8+8/13+...
#include <stdio.h>
int main()
{
    int i;
    float sum=0,fz=1.0,fm=1.0,t;

    for(i=1;i<=20;i++)
    {
        sum+=fz/fm;
        t=fz;
        fz=fm;
        fm+=t;
        printf("%f ",sum);
    }

}

*/

/*

//求1+1/2+1/3+1/4+1/5+„„+1/100的和
#include <stdio.h>
int main()
{
    int i;
    float sum=0.0;
    for(i=1;i<=100;i++)
    {
        sum+=1.0/i;
    }
    printf("%f\n",sum);
}

*/

/*

//水仙花数
#include <stdio.h>
int main()
{
    int g,s,b,i,t;

    for(i=100;i<1000;i++)
    {
        t=i;
        while(t>0)
        {
            g=t%10;     t/=10;
            s=t%10;     t/=10;
            b=t;        t/=10;
        }
        if(g*g*g+s*s*s+b*b*b==i) printf("%d ",i);
    }
}

*/

/*

#include <stdio.h>
int result[11];
int BottomUp(int n, int* p)
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        int tempMaxPrice = 0;
        for (j = 1; j <= i; j++)    //下面取得 钢条长度为i的时候的最大收益
        {
            int maxPrice = p[j] + result[i - j];
            if (maxPrice > tempMaxPrice)
            {
                tempMaxPrice = maxPrice;
            }
        }
        result[i] = tempMaxPrice;
    }
    return result[n];
}
int main()
{

    int n,p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };//索引代表 钢条的长度，值代表价格
    while(scanf("%d",&n))
    printf("%d\n",BottomUp(n,p));
}

*/


/*

#include <stdio.h>
int UpDown(int n, int * p)      //参数n是长度，参数p是价格表
{
    int i;

    if (n == 0) return 0;       //递归的基本问题
    int tempMaxPrice = 0;
    for (i = 1; i < n + 1; i++)
    {
        int maxPrice = p[i] + UpDown(n - i, p);
        if (maxPrice > tempMaxPrice)
        {
            tempMaxPrice = maxPrice;
        }
    }
    return tempMaxPrice;
}
int main()
{
    int n,p[11]={ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };     //索引代表 钢条的长度，值代表价格
    while(scanf("%d",&n))
    printf("%d\n",UpDown(n,p));
}

*/


/*

#include<stdio.h>
int main()
{
    int i=0,j=0,m,n,w[16],a[350]={4,0,4,0,4,0,4,32,-1,-16,4,32,4,32,4,32,4,32,32,8,32,8,32,16,34,16,34,32,30,-64,0,
16,64,16,64,34,68,127,126,66,-124,67,4,66,4,66,-124,126,100,66,36,66,4,66,4,66,4,126,4,66,40,0,16,
4,0,4,0,4,0,4,32,-1,-16,4,32,4,32,4,32,4,32,4,32,8,32,8,32,16,34,16,34,32,30,-64,0,
0,-128,64,-128,48,-128,17,8,1,-4,2,8,8,80,16,64,32,64,-32,64,32,-96,32,-96,33,16,34,8,36,14,40,4,
4,0,3,0,1,0,0,4,-1,-2,4,0,4,16,7,-8,4,16,4,16,4,16,8,16,8,16,16,16,32,-96,64,64,
16,64,20,72,62,-4,73,32,5,16,1,0,63,-8,1,0,-1,-2,0,64,0,80,63,-8,8,64,4,64,1,64,0,-128,
0,16,63,-8,1,0,1,0,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,5,0,2,0,
2,0,2,0,7,-16,8,32,24,64,37,-128,2,-128,12,-128,113,-4,2,8,12,16,18,32,33,-64,1,0,14,0,112,0,
1,0,1,0,1,0,9,32,9,16,17,12,17,4,33,16,65,16,1,32,1,64,0,-128,1,0,2,0,12,0,112,0,
0,0,0,0,7,-16,24,24,48,12,56,12,0,56,0,-32,0,-64,0,-128,0,0,0,0,1,-128,3,-64,1,-128,0,0};

    while(j<160)
    {
        m=a[j++]; n=a[j++];
        for(i=7;i>=0;i--) {w[i]=m & 1;  m>>=1;}
        for(i=15;i>=8;i--) {w[i]=n & 1; n>>=1;}
        for(i=0;i<=15;i++)
        {
            printf("%d ",w[i]);
        }
        printf("\n");
        if(j%16==0) printf(" ");
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int i,m,n,w[16];
    while(scanf("%d %d",&m,&n))
    {
        for(i=7;i>=0;i--){w[i]=m&1;m>>=1;}
        for(i=15;i>=8;i--){w[i]=n&1;n>>=1;}
        for(i=0;i<=15;i++){printf("%d ",w[i]);}
        printf("\n");
    }
}

*/

/*

//明码
#include<stdio.h>
#include<math.h>
#include<string.h>
int arr[110];
int change(int x)
{
	int i,j,k;
	k = abs(x);
	i = 0;
	while(k != 0)
	{
		arr[i] = k % 2;
		k /= 2;
		i ++;
	}
	if(x < 0)
	{
		for(i = 0;i <= 7;i ++)
		{
			if(arr[i] == 1 && i < 7)
			{
				for(j = i+1 ;j <= 7;j ++)
				{
					if(arr[j] == 0)
						arr[j] = 1;
					else
						arr[j] = 0;
				}
				break;
			}
		}
	}
}
int main()
{
	int a[32];
	int i,j,k;
	for(k = 0;k < 9;k ++)
	{
		for(i = 0;i < 32;i ++)
		{
			scanf("%d",&a[i]);
			change(a[i]);
			for(j = 7 ;j >= 0;j --)
			{
				if(arr[j] == 1)
					printf("%d",arr[j]);
				else
					printf(" ");
			}
			memset(arr,0,sizeof(arr));
			if(i % 2 == 1)
				printf("\n");
		}
	}
	return 0;
}

*/

/*

#include<stdio.h>
main()
{
    int i,j,k;
    int sum=0;
    for(i=0;i<=50;i++)
    {
        for(j=0;j<=20;j++)
        {
            k=100-2*i-5*j;
            if(k>=0 && i+j+k==50)
            {
                printf("1分%3d张    2分%3d张     5分%3d张\n",100-2*i-5*j,i,j);
                sum++;
            }
        }

    }

    printf("\n%d\n",sum);
    return 0;
}

*/

/*

#include<stdio.h>
int main()
{
    int a[4][4]={
        {11,12,13,14},
        {21,22,23,24},
        {31,32,33,34},
        {41,42,43,44}
    };
    printf("%d\n",*(*(a+1)+2));
}

*/

/*

#include<stdio.h>

void fun(char *s,char *p){
    while((*p=*s,p++,*s++))
    {

    }
    *p=0;

}

int main()
{
    char s[]="you";
    char p[]="funk";
    fun(s,p);
        printf("%s\n",s);
        printf("%s\n",p);
}

*/




/*

//选择法排序
#include<stdio.h>
int main()
{
    int a[10],i,j,index;
    for(i=0;i<10;i++) scanf("%d",&a[i]);

    for(i=0;i<10;i++)
    {
        index=i;
        for(j=i+1;j<10;j++)
        {
            if(a[index]>a[j])
            {
                index=j;
            }
        }
        if(index==i) continue;
        else{
            a[i]=a[i]^a[index];
            a[index]=a[i]^a[index];
            a[i]=a[i]^a[index];
        }
    }
    for(i=0;i<10;i++) printf("%d ",a[i]);

}

*/




/*

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[2]="ve";
    printf("%d\n",a);

}

*/


/*

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct PNode{
    char a1[4];
    int a;
    char a2[4];
};

int main()
{
    struct PNode p;
    strcpy(p.a1,"I love");
    p.a=0x20206576;
    strcpy(p.a2,"3G!");
    printf("%s\n",p.a1);
    printf("%d",p.a);

}

*/

/*

#include<stdio.h>
#include<string.h>
int main()
{
    int a[4]={541663264,1163284300,1431263520,0};
    printf("\n\n%s\n",a);
}

*/

/*

#include<stdio.h>
#include<string.h>
int main()
{
    char a[30]="\ta\017bc";
    char *b=a;
    printf("%d %d\n",sizeof(a),strlen(a));
    printf("%d %d\n",sizeof(b),strlen(b));
}

*/

/*

#include<stdio.h>
int main()
{
    int a[]={6,7,8,9,10};
    int *p=a;
    *(p++)+=123;
    printf("%d,%d\n",*p,*(++p));
    printf("%d,%d,%d,%d,%d\n",*p--,*p+20,*(p--),*p,*(++p));

}

*/



/*

#include<stdio.h>
int main()
{
    int a,b,i=65;
    printf("%d\n",printf("%d",printf("%d %d",scanf("%d %d",&a,&b),i)));

}

*/

/*

#include<stdio.h>
#define F(n) 2*n
#define X(x) x;x;x;x;x;

void T(int data)
{
    printf("%d ",data++);
    printf("%d ",data++);
    printf("%d ",data++);
    printf("%d ",data++);
    printf("%d ",data++);
}

int main()
{
    int a=2,b=3;
    X(T(F(a+b++)));

}

*/

/*

#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int grade;
    char name[20];
}Student;

int cmp(const void*a,const void *b)
{
    return (((Student *)a)->grade>((Student *)b)->grade?1:-1);

}

int main()
{
    int i;
    Student stus[50]={{34,"tom"},{66,"jerry"},{20,"bob"},{40,"john"},{90,"lisa"},{72,"peter"}};
    qsort(stus,6,sizeof(Student),cmp);
    for(i=0;i<6;i++) printf("%d %s\n",stus[i].grade,stus[i].name);

}

*/








//筛选法求质数
#include <stdio.h>
#define N 10000
int main()
{
    int i,j,a[N+1];

    for(i=2;i<=N;i++) a[i]=1;

    for(i=2;i*i<=N;i++) for(j=i*2;j<=N;j++) if(j%i==0) a[j]=0;
    for(i=2;i<=N;i++)
    {
        if(a[i]==1) printf("%-5d",i);
    }

}



/*

//冒泡法排序
#include<stdio.h>
int main()
{
    int a[10],i,j;
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    for(i=0;i<10;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]^a[j+1];
                a[j+1]=a[j]^a[j+1];
                a[j]=a[j]^a[j+1];
            }
        }
    }
    for(i=0;i<10;i++) printf("%d ",a[i]);
}

*/

/*
//交换法排序

#include<stdio.h>
int main()
{
    int a[10],i,j;

    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
    for(i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
}

*/


/*

//十进制数转换为其他进制数
void tran(int m,int r,char str[],int *n)
{
    char sb[]="0123456789ABCDEF"; int i=0,g;
    do
    {
        g=m%r;
    	str[i]=sb[g];
        m/=r;
        i++;
	}while(m!=0);
    *n=i;
}

main()
{
    int x,r0;	//r0为进制基数
    int i,n;	//n中存放生成序列的元素个数
    char a[50];
    scanf("%d%d",&x,&r0);
    if(x>0 && r0>=2 && r0<=16)
    {
        tran(x,r0,a,&n);
        for(i=n-1;i>=0;i--) printf("%c",a[i]);
        printf("\n");
    }
    else exit(0);
}

*/

/*

//插入法排序 (升序)

#include<stdio.h>
#define n 10
main()
{
	int a[n],i,j,k,x;

	scanf("%d",&a[0]);
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		if(x>a[i-1]) a[i]=x;   //比原数列最后一个数还小就往最后一个元素之后存放新读的数
		else	//以下查找待插位置
		{
			j=0;
			while(j<i && x>a[j]) j++;
			//以下for循环从原最后一个数开始直到待插位置上的数依次后移一位
			for(k=i-1;k>=j;k--) a[k+1]=a[k];
			a[j]=x;		//插入待插数
		}
	}
	for(i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}

*/

/*

//折半查找（即二分法）
#include<stdio.h>
#define n 10
main()
{
    int x,high,low,mid;
	int a[n]={1,16,22,34,45,53,66,88,92,100};
	mid=n/2;	high=n-1;	low=0;

	scanf("%d",&x);
	while(x!=a[mid] && low<high)
	{
		if(x>a[mid])
		{
			low=mid+1;
			mid=(low+high)/2;
		}
		else if(x<a[mid])
		{
			high=mid;
			mid=(low+high)/2;
		}
	}
	if(x==a[mid]) printf("find %d\n",x);
	else printf("not found\n");
}

*/


/*

//汉诺塔
#include<stdio.h>
void move(int n,char A,char B,char C)
{
    if(n==1) printf("%c->%c\n",A,C);
    else
    {
        move(n-1,A,C,B);        //第一次递归，表示把头上n－1块从a经过c移到b
        printf("%c->%c\n",A,C); //表示把最后一块，从a移到c
        move(n-1,B,A,C);        //第二次递归，表示把剩下n－1块从b经过a移到c
    }
}

int main()
{
    int n;
    printf("input a num:\n");
    scanf("%d",&n);
    move(n,'A','B','C');
}

*/














