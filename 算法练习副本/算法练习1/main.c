









#include <stdio.h>

int main()
{
	int m;
	scanf("%d",&m);

	while (m--)
	{
		char x;
		int y;
        getchar();
		scanf("%c %d",&x,&y);
		if (x<= 'Z' && x >= 'A')
		{
			x = x - 'A'+1;
		}
		else
		{
			x = 'a'- x -1;
		}
		printf("%d\n",x+y);
	}
	return 0;
}







/*

//217-a letter and a number
#include<stdio.h>
int main()
{   int N,y,sum;
    char x;

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        fflush(stdin);
        scanf("%c%d",&x,&y);
        if(x-'A'<26) sum=(x-'A'+1)+y;
        else sum=y-(x-'a'+1);
        printf("%d\n",sum);
    }
}

*/


/*

//216-A problem is easy
#include<stdio.h>
int main()
{
    int T,N,i,j,x;
    scanf("%d",&T);
    while(T--)
    {
        x=0;
        scanf("%d",&N);
        for(i=1;i*i<N;i++)      //ѭ������???
        {
            j=(N-i)/(i+1);
            if(i*j+i+j==N && i<=j)
                x++;
        }
        printf("%d\n",x);
    }
}

*/

/*

//216-A problem is easy
#include<stdio.h>
int main()
{   int N,i,j,n,count;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&n);
        for(j=1;j<n;j++)
        {
            for(i=1;i<=j;i++) if((i*j+i+j)==n) count++;
        }
        printf("%d\n",count);
    }
}

*/

/*

//204-Coin Test
#include<stdio.h>
int main()
{   int n,m,i,count,max;
    double rate;
    char a[65536];

    scanf("%d",&n);
    scanf("%s",&a);
    count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='U') count++;
        else if(a[i]=='S') break;
    }
    rate=count*1.0/n;
    if(i!=n) printf("Bingo");
    else
    {
        if(rate>=0.497 && rate<=0.503)
        {
            for(i=2;i<n;i++)
            {
                if(count%i==0 && n%i==0) max=i;
            }
            printf("%d/%d\n",count/max,n/max);
        }
        else printf("Fail\n");
    }
}

*/

/*

//198-����
#include<stdio.h>
int main()
{   int N,i,a[20],len,n,j;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        i=0;
        while(n>0)
        {
            a[i++]=n%10;
            n/=10;
        }
        for(j=0;j<i;j++)
        {
            if(a[j]==1) printf("O");
            else if(a[j]==2) printf("T");
            else if(a[j]==3) printf("T");
            else if(a[j]==4) printf("F");
            else if(a[j]==5) printf("F");
            else if(a[j]==6) printf("S");
            else if(a[j]==7) printf("S");
            else if(a[j]==8) printf("E");
            else if(a[j]==9) printf("N");
            else if(a[j]==0) printf("O");
        }
            printf("\n");
    }
}

*/

/*

//169-������ɸ����������
#include<stdio.h>
#define MAX 1000010
int a[MAX];
void yjj()
{
	int i,j;
	for(i=0;i<MAX;++i)
	    a[i]=1;
	a[0]=a[1]=0;
	for(i=2;i<MAX;++i) //ɸ������ 1Ϊ������0Ϊ������
	{
		if(a[i]==1)                            //���i������
		{
			for(j=i+i;j<MAX;j+=i)       //ÿ��ɾȥi�ı���
			    a[j]=0;
		}
	}
}

int main()
{
	int N;
	yjj();
	scanf("%d",&N);
	while(N--)
	{
		int m,i,j;
		scanf("%d",&m);
		if(a[m]==1)  //mΪ����
		    printf("%d\n",m);
		else  //m ��Ϊ����
		{
			i=j=m;  //i������ң�j���Ҳ���
			while(a[i]==0 && i>=0) i--;
			while(a[j]==0) j++;
			if(i<0)
			    printf("%d\n",j);
			else if(m-i<j-m)
			    printf("%d\n",i);
			else
			    printf("%d\n",j);
		}
	}
	return 0;
}

*/

/*

//168-���䰲��
#include<stdio.h>
#include <memory.h>
int main()
{
 int T,N,a,b,c,num[200],i,max;
 scanf("%d",&T);
 while(T--)
 {
    max=0;
    memset(num,0,sizeof(num));
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(i=b;i<b+c;i++)
        {
            num[i]+=a;
            if(num[i]>max) max=num[i];
        }
    }
    printf("%d\n",max);
 }
 return 0;
}

*/

/*

#include<stdio.h>
#include<string.h>
#define n 99
int main()
{
	char a[100],b[100],c[100];
	int i,j,k,up,len1,len2,len3,str[100],str1[100],str2[100],str3[100];
	while(~scanf("%s %s %s",a,b,c))
	{
		memset(str,0,sizeof(str));      memset(str1,0,sizeof(str1));              //������ʹ�
		memset(str2,0,sizeof(str2));        memset(str3,0,sizeof(str3));
		len1=strlen(a);     len2=strlen(b);     len3=strlen(c);                               //�����鳤�ȱ�ʾ����
		for(k=0,i=len1-1;i>=0;i--)                      //��������ӣ������λ���⣬Ȼ����Ǽ����������
		{
			str1[k++]=a[i]-'0';
		}
		for(k=0,i=len2-1;i>=0;i--)
		{
			str2[k++]=b[i]-'0';
		}
		for(k=0,i=len3-1;i>=0;i--)
		{
			str3[k++]=c[i]-'0';
		}
		for(i=0;i<=n-3;i++)                                 //��Ϊ�����99������str1[],str2[],str3[]����������������Ӻ���Ϊһ����
		{
			for(up=0,j=0;j<=n;j++)
			{
				str[j]=str1[j]+str2[j]+str3[j]+up;
				up=str[j]/10;
				str[j]=str[j]%10;
			}
			for(j=0;j<=n;j++)                   //������ĸţ��ĸţ�ĵ�����ֻ�Ƕ����һ����
			{
				str1[j]=str2[j];
				str2[j]=str3[j];
				str3[j]=str[j];
			}
		}
		for(i=n;i>=0;i--)                               //ȥ��ǰ������0
		{
			if(str[i]) break;
		}
		if(len1==1&&len2==1&&len3==1&&a[0]=='0'&&b[0]=='0'&&c[0]=='0')          //������ˣ�0+0+0=0��������
		{
			printf("0\n");
		}
		for(k=i;k>=0;k--)
		{
			printf("%d",str[k]);
		}
		printf("\n");
	}
	return 0;
}

*/

/*

#include<stdio.h>
void move(int n,char x,char y,char z)
{
    if(n==1) printf("%c -> %c\n",x,z);
    else
    {
        move(n-1,x,z,y);
        printf("%c -> %c\n",x,z);
        move(n-1,y,x,z);
    }
}
int main()
{   int n;

    while(1)
    {
        printf("�������:\n");
        scanf("%d",&n);
        printf("�ƶ�����:\n");
        move(n,'1','2','3');
    }
}


*/



/*

#include<stdio.h>

void f ();

int main ()
{
    int n;
    scanf("%d", &n);

    while (n)
    {
        f();
        n--;
    }
    return 0;
}

void f ()
{
    int a[99], i, j, k, m, n, b;
    scanf("%d", &m);

    for ( i = 0; i < m; i++ ) {
        scanf("%d", &a[i]);
    }

    for ( i = 0; i < m; i++ ) {
        n = 0;
        for ( j = 0; j < m; j++ ) {
            if ( a[i] == a[j] ) {
                n++;
            }
        }
        if ( n > b ) {
            k = a[i];
            b = n;
        }
    }

    printf("%d %d\n", k, b);
}

*/



/*

//���125λ,С�������75λ
//����������������,������������˶��ٱ�
//�������ָ߾��ȿ�����, ������n*log10()ֱ�Ӽ����С����λ��

#include<stdio.h>
#include<memory.h>
#include<string.h>

void mul(int *a,int *b)
{   int i,j;
	int temp,c[250];
	memset(c,0,sizeof(c));
	for(i=0;i<125;i++)
    {
		int nC=0;
		for(j=0;j<125;j++)
		{
			temp=c[i+j]+a[j]*b[i]+nC;
			nC=temp/10;
			c[i+j]=temp%10;
		}
	}
	memcpy(a,c,sizeof(c));
}

int main()
{
	char str[8];
	char astr[150];
	int n,len,dot,i,k;
	int ans[250];
	int base[250];
	while(scanf("%s",str)!=EOF)
    {
		memset(ans,0,sizeof(ans));
		memset(base,0,sizeof(base));
		memset(astr,'0',sizeof(astr));
//
		scanf("%d",&n);
		len=strlen(str);
		ans[0]=1;
		int j=0;
		dot=0;
		for(i=len-1;i>=0;i--)
        {
			//�ҵ�С�����λ��
			if(str[i]=='.')
				dot=len-i-1;
			//��������base
			if(str[i]!='.')
				base[j++]=(str[i]-'0');
        }

		dot *=n;

		//������
		while(n>0)
		{
			if(n&1) mul(ans,base);
			mul(base,base);
			n>>=1;
		}

		//������
		//���͵㶼�ŵ��ַ�������
		j=0;

		int count=0;//��¼С������һ����Ϊ0��λ�� ,��С������Ϊ0

		if(dot!=0)              //��С����
		{
			for(i=0;i<150;i++)
			{
				if(dot!=i)
				{
					astr[j] = ans[i]+'0';
					j++;
				}
				else if(dot==i)
				{
					astr[j]= '.';
					j++;
					astr[j]= ans[i]+'0';
					j++;
				}
			}
			//�� С��������
			for(k=0;k<124;k++)
			{
				if(astr[k]!='0')
				{
					count=k;
					break;
				}
			}
			//С����λ�õ���count,����С�������û����Ч����,+1�����С����
			if(count==dot)
				count++;
		}
		else                            //��С����
		{
			for(i=0;i<150;i++)
			{
				astr[j++] = ans[i]+'0';
			}
		}



		//���
		int flag=0;
		for(i=124;i>=count;i--)
		{
			if(flag!=0)
				printf("%c",astr[i]);
			else if(astr[i]!='0')
			{
					printf("%c",astr[i]);
					flag=1;
			}
		}
		printf("\n");
    }
}

*/
