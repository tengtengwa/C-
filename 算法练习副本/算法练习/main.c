











/*

//���n��ȫ����
#include <stdio.h>
int n,a[30],book[10];

int dfs(int cur)
{
    int i,j;

    if(cur==n+1)    //����߽磬���һ������
    {
        for(i=1;i<=n;i++) printf("%d",a[i]);
        printf("\n");
    }
    else{
        for(i=1;i<=n;i++)
        if(book[i]==0)
        {
            book[i]=1;
            a[cur]=i;       //����i�������뵱ǰ����λ�ã�����i���˿��Ʒ��뵱ǰ�����У�
            dfs(cur+1);
            book[i]=0;
        }
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        dfs(1);
    }
}

*/

/*

#include <stdio.h>

int hasSelect[10];
int store[10], id, n, m;

void DFS(int k){
    int i;

	if(k == m){
		for(i = 0; i < m; ++i) printf("%d", store[i]);
		printf("\n");
		return;
	}
	for(i = 1; i <= n; ++i){
		if(!hasSelect[i]){
			store[k] = i;
			hasSelect[i] = 1;
			DFS(k + 1);
			hasSelect[i] = 0;
		}
	}
}

int main(){
	int t, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);

		for(i = 0; i < 10; ++i) hasSelect[i] = 0;
		id = 0;

		DFS(0);
	}
	return 0;
}

*/


/*

//19-�ó����е�С��
#include<stdio.h>
int m,n,a[15];

void dfs(int cur){
	int i,j;
	if(cur==m+1){
		for(i=1;i<=m;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	else{
		for(i=1;i<=n;i++)
        {
			int flag=1;         //flagΪ0ʱ������ǰ��������Ѿ���i�����Ժ��治��ȡi
            for(j=1;j<=cur-1;j++)
            {
                if(a[j]==i) flag=0;
            }
            if(flag)
            {
                a[cur]=i;
                dfs(cur+1);
            }
		}
	}
}
int main(){
	int cases,i,j,cur;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&m);
		dfs(1);         //��a[1]��ʼ
	}
	return 0;
}

*/

/*

//5-Binary String Matching
#include<stdio.h>
#include<string.h>
int main()
{
    int N,sum,i,j,t,lena,lenb;
    char a[20],b[1020];

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lenb-lena+1;i++)
        {
            t=i;
            for(j=0;j<lena;j++)
            {
                if(a[j]-b[t++]==0) continue;
                else break;
            }
            if(j==lena) sum++;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//599-�ܶ���С��ţ
#include<stdio.h>
int main()
{
    int N,n,i,h;

    scanf("%d",&N);
    while(N--)
    {
        n=0;
        scanf("%d",&h);
        if(h<=10) printf("1\n");
        else{
        while(h>10)
        {
            h-=5;
            n++;
        }
        n+=1;
        printf("%d\n",n);
        }
        if(N) printf("\n");
    }
}

*/

/*

//24-������������
#include<stdio.h>
#include<math.h>
int primeJudge(int pri);
int primePrint(int m);

int main()
{
    int k;
    scanf("%d",&k);
    int num[k],i;
    for(i=0;i<k;i++)
    {
        scanf("%d",&num[i]);    //�����������
        primePrint(num[i]);     //���������������
    }

    return 0;
}
int primePrint(int m)
{
    int count=0,j;
    if(primeJudge(m))
            printf("%d %d\n",m,count);
    else
        for(j=1;;j++)
        {
            if(primeJudge(m-j))
            {
                printf("%d %d\n",m-j,count+j);      //�����ж�
                break;
            }
             if(primeJudge(m+j))
            {
                printf("%d %d\n",m+j,count+j);      //�����ж�
                break;
            }
        }
}
int primeJudge(int pri)
{
    int i;
    for(i=2;i<=sqrt(pri);i++)
        if(pri%i==0)
            i=pri;
    if(i>pri)
        return 0;
    else
        return 1;
}

*/

/*

//2-�����������(ֻ��ͬ�����������ڻ���ȥ������ʱ������ȥ)
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,len;
    char s[10010],t[10010];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        t[0]=s[0];
        j=1;
        len=strlen(s);

        for(i=1;i<len;i++)
        {
            if(s[i]=='(' || s[i]=='[')
            {
                t[j++]=s[i];        //�൱�ڽ�ջ
            }
            else if(s[i]==')')
            {
                if(t[j-1]=='(')
                {
                    j--;            //�൱�ڳ�ջ
                }
                else    t[j++]=s[i];    //��ƥ��ջ�����ţ����ջ
            }
            else if(s[i]==']')      //ͬ��
            {
                if(t[j-1]=='[')
                {
                    j--;
                }
                else    t[j++]=s[i];
            }
        }
        if(j==0) printf("Yes\n");
        else printf("No\n");

    }
}

*/

/*

//�����Ӧ������
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len,j;
    char a[5000]="1";
    int *p1,*p2;
    len=1;

    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        len=len*2+1;
        a[len/2]=i+'0';     //��������i�����ַ��м�
        p1=&a[len/2+1];
        p2=&a[0];
        strncpy(p1,p2,len/2);  //strncpy(*a,*b,n) �˺������ַ���b��n���ַ����Ƹ�a,������ָ��a��ָ��
    }
    for(i=0;i<len;i++) printf("%c",a[i]);
    printf("\n");
}

*/

/*

//517-��С������
#include<stdio.h>
int a[105];
int s[100];
int main()
{
    int a[105];
    int i,j,n,x;
    for(i=1;i<105;i++)
        a[i]=i;
    for(i=1; i<105; i++)
        for(j=i+1; j<105; j++)
            if(a[j]%a[i]==0)
                a[j]=a[j]/a[i];     //��������ɸȥ��
    while(~scanf("%d",&n))
    {
        x=0;
        memset(s,0,sizeof(s));
        s[0]=1;
       for(i=1;i<=n;i++)
       {
           for(j=0;j<100;j++)//������
           {
               int c=s[j]*a[i]+x;
               s[j]=c%10;
               x=c/10;
           }
       }
       for(i=99;i>=0;i--)
        if(s[i]) break;
       for(j=i;j>=0;j--)
        printf("%d",s[j]);
       printf("\n");
    }
   return 0;
}

*/


/*

//477-A+B Problem III

#include<stdio.h>
int main()
{
    int n;
    double a,b,c;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf %lf",&a,&b,&c);

        if(a+b-c<=0.0001 && a+b-c>=-0.0001) //ע��: �����������������ڣ�-0.0001��0.0001��������������ֱ�ӵ���
        printf("Yes\n");
        else printf("No\n");
    }
}

*/

/*

//114-ĳ������

#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,len1,len2,len3,q,h,d[100],e[100],f[100],g[100];
	char a[100],b[100],c[100];
	while(scanf("%s %s %s",a,b,c)!=EOF)
	{
	    memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		len1=strlen(a);
		len2=strlen(b);
		len3=strlen(c);
		if(len1==1&&len2==1&&len3==1&&a[0]=='0'&&b[0]=='0'&&c[0]=='0')
			printf("0\n");
		else
		{   //�˴���ʼ���ַ���ת��Ϊ����
			for( i=0,j=len1-1;j>=0;i++,j--)
				d[i]=a[j]-'0';
			for(i=0,j=len2-1;j>=0;i++,j--)
				e[i]=b[j]-'0';
			for(i=0,j=len3-1;j>=0;i++,j--)
				f[i]=c[j]-'0';
			for(i=0;i<=96;i++)
			{    int k=0;
				for(j=0;j<=99;j++)//�˴�Ϊ������ӵ�ģ��
				{
                    g[j]=d[j]+e[j]+f[j]+k;      //kΪ��λ��
				    k=g[j]/10;
				    g[j]=g[j]%10;
				}
				for(j=0;j<=99;j++)//�˴��ǽ��е������������������м��ɡ�������������
				{
					d[j]=e[j];
					e[j]=f[j];
					f[j]=g[j];
				}
			}
			for(i=99;i>=0;i--)
		        if(g[i])break;
			for(j=i;j>=0;j--)
				printf("%d",g[j]);
			printf("\n");
		}
	}return 0;
}

*/


/*

//463-�žų˷���
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,N,n;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=9;j++)
            {
                printf("%d*%d=%d ",i,j,i*j);
            }
            printf("\n");
        }
            if(N) printf("\n");
    }
}

*/

/*

//457-��Сд����
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char s[200];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z') s[i]-=32;
            else
            s[i]+=32;
        }
        printf("%s\n",s);
    }
}

*/

/*

//�����׳�


#include <stdio.h>
int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		int flag=1;
		int carry=0;        //���ý�λ
		int res=0;
		int str[40000];     //������ĿҪ����������Ĵ�С
		str[0]=1;
		for (i=2;i<=n;i++)   //��2��ʼ����׳�
		{
			for (j=1;j<=flag;j++)     //���ݽ�λflag��С���жϵ�ǰ�׳˽���ĵ�λ��
            {
                res=str[j-1]*i+carry;
                str[j-1]=res%10;
                carry=res/10;
            }
			while (carry)  //����λ����һʱ�������չ����һλ
			{
				flag++;
				str[flag-1]=carry%10;
                carry/=10;
			}
		}
		for (i=flag-1;i>=0;i--)    //��������鵹�������ע�����һλ��"i=flag-1",��Ϊ"flag=1" ��Ӧstr[0],�Դ�����
 		{
			 printf("%d",str[i]);
		}
		printf("\n");
	 }
 	return 0;
}

*/


/*

//����
#include <stdio.h>
int quicksort(int left,int right,int a[])
{
    int i,j,tem;

    if(left>right) return a;    //��ǰ��

    i=left;     j=right;    tem=a[left];    //����ֵ
    while(i!=j)     //������
    {
        while(a[j]>=tem && i<j) j--;    //ע��Ⱥ�
        while(a[i]<=tem && i<j) i++;
        if(i<j)
        {
            a[i]=a[i]^a[j];
            a[j]=a[i]^a[j];
            a[i]=a[i]^a[j];
        }
    }
    a[left]=a[i];       //��Ϊ��׼��
    a[i]=tem;

    quicksort(left,i-1,a);      //�ݹ�
    quicksort(i+1,right,a);
    return a;
}

int main()
{
    int i,a[20];

    for(i=1;i<=10;i++) scanf("%d",&a[i]);
    quicksort(1,10,a);
    for(i=1;i<=10;i++) printf("%d ",a[i]);
    printf("\n");

}

*/

/*

//�������
#include <stdio.h>
int quicksort(int left, int right, int a[])
{
    int i, j;
    int temp, t;
    if (left>right) return a;

    temp = a[left]; //temp�д�ľ��ǻ�׼��
    i = left;
    j = right;
    while (i != j)
    {
        while (a[j] >= temp && i<j) j--;     //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��;  ע����ں�!!!
        while (a[i] <= temp && i<j) i++;      //����zuo�ߵ�

        if (i<j)    //�����������������е�λ��
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //���ս���׼����λ
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1, a);//����������ߵģ�������һ���ݹ�Ĺ���
    quicksort(i + 1, right, a);//���������ұߵ� ��������һ���ݹ�Ĺ���
    return a;
}
int main()
{
    int i,j,t,n,a[20];

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    quicksort(1,n,a); //�����������

    for(i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}

*/



/*

//����

#include <stdio.h>
#include <stdlib.h>

#define n 10

//--------------------------------------------------
//��������display
//���ã���ӡ����Ԫ��
//������array - ��ӡ�����飬maxlen - ����Ԫ�ظ���
//����ֵ����
//--------------------------------------------------
void display(int array[], int maxlen)
{
    int i;

    for(i = 0; i < maxlen; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");

    return ;
}

//--------------------------------------------------
//��������swap
//���ã�������������ֵ
//������������������
//����ֵ����
//--------------------------------------------------
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

//--------------------------------------------------
//��������quicksort
//���ã����������㷨
//������
//����ֵ����
//--------------------------------------------------
void quicksort(int array[], int maxlen, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
        j = end;        // array[end]����������һλ

        while(i < j)
        {
            if(array[i] > array[begin])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                swap(&array[i], &array[j]);  // ����������
                j--;
            }
            else
            {
                i++;  // �����������һλ���������׼���Ƚϡ�
            }
        }

        // ����whileѭ����i = j��
        // ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
        //                          -->  array[i+1] ~ array[end] > array[begin]
        // ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
        // ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���

        if(array[i] >= array[begin])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // ����array[i]��array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}

// ������
int main()
{
    int n;
    int array[n] = {12,85,25,16,34,23,49,95,17,61};
    int maxlen = n;

    printf("����ǰ������\n");
    display(array, maxlen);

    quicksort(array, maxlen, 0, maxlen-1);  // ��������

    printf("����������\n");
    display(array, maxlen);

    return 0;
}

*/






/*

#include <stdio.h>
int main(int argc,char*argv[])
{

	int d1,d2,d3;
	int min;
	while(scanf("%d%d%d",&d1,&d2,&d3)==3)
	{
		min=d1+d2+d3;
		if(d1+d2+d3>2*(d1+d2))
			min=2*(d1+d2);
		if(min>2*(d1+d3))
			min=2*(d1+d3);
		if(min>2*(d2+d3))
			min=2*(d2+d3);
		printf("%d\n",min);
	}
}

*/

/*

//324-���ӳ�������
#include<stdio.h>
int main()
{
    int N,m,i,sum;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        sum=1;
        for(i=0;i<m;i++)
        {
            sum=(sum+1)*2;

        }
        printf("%d\n",sum);
    }
}

*/

/*

//277-���ƺ�
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
        int m;
        char a[6],c[6];
        scanf("%d",&m);
        getchar();
        while(--m)
        {
            gets(c);
            gets(a);
            if(strcmp(a,c)<0) strcpy(c,a);  //�ַ�������(�Ѻ���ĸ��Ƹ�ǰ����ַ���)
        }                                   //�ַ����Ƚ�:
                                            //��s1<s2ʱ������Ϊ����;��s1=s2ʱ������ֵ= 0;��s1>s2ʱ����������.
                                            //�����ַ���������������ַ���ȣ���ASCIIֵ��С��Ƚϣ���ֱ�����ֲ�ͬ���ַ�����'\0'Ϊֹ
        puts(c);
	}
	return 0;
}

*/

/*

//276-�Ƚ���ĸ��С
#include<stdio.h>
int main()
{
    int N;
    char a,b,c;

    scanf("%d",&N);
    while(N--)
    {
        getchar();//������뻺�����еĿո��
        scanf("%c %c",&a,&b);
        if(a>b) {c='<';}
        if(a==b) {c='=';}
        if(a<b) {c='>';}
        printf("%c%c%c\n",a,c,b);

    }
}

*/

/*

//275-�ӻ��ķ���һ(ʮ����ת������)
#include<stdio.h>
int main()
{
    int i,n,a[100];

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) printf("0\n");
        else
        {
            i=0;
            while(n>0)
            {
                a[i++]=n%2;
                n/=2;
            }
            i-=1;;
            for(;i>=0;i--) printf("%d",a[i]);
            printf("\n");
        }

    }
}

*/

/*

//274-�������ε����Բ���
#include<stdio.h>
#define pi 3.1415926
int main()
{
    int N;
    double s,r,l;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%lf",&l);
        s=1.0/3.0*pi*l*l;
        printf("%.2f\n",s);
    }
}

*/

/*

//273-��ĸС��Ϸ
#include<stdio.h>
#include<string.h>
int main()
{
    int N,n,i;
    char s[200],a;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        n=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z') n++;
        }
        n%=26;
        a='a'-1;
        if(n==0) printf("z\n");
        else
        printf("%c\n",a+n);
    }
}

*/

/*

//268-������������
#include<stdio.h>
#include<string.h>
int main()
{
    int N,r,b,w,i;
    char s[1000];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        for(i=0;i<strlen(s);i++) if(s[i]=='R') printf("R");
        for(i=0;i<strlen(s);i++) if(s[i]=='W') printf("W");
        for(i=0;i<strlen(s);i++) if(s[i]=='B') printf("B");
        printf("\n");
    }
}

*/

/*

//266-�ַ����������
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i,len1,len2;
    char a[20],b[20];

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s%s",&a,&b);
        len1=strlen(a);
        len2=strlen(b);
        for(i=len2-1;i>=0;i--)
        {
            if(b[i]>'9') printf("%c",b[i]);
        }
        for(i=len1-1;i>=0;i--)
        {
            if(a[i]>'9') printf("%c",a[i]);
        }
        printf("\n");
    }
}

*/

/*

//unsolved question

//264-������ħ��
#include<stdio.h>
#include<string.h>
int main()
{
    int N,i,j,len;
    char s[100];

    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",&s);
        len=strlen(s);
        if(len==1) printf("1\n");
        else
        {
            while(len%2==0)
            {
                if(len==2 && s[0]!=s[1]) break;
                for(i=0,j=len-1;i<len/2;i++,j--)
                {
                    if(s[i]==s[j]) continue;
                    else break;
                }
                if(i==len/2) len/=2;
                else break;
            }
            printf("%d\n",len);
        }
    }
}

*/

/*

//263-����ϸѡ
#include<stdio.h>
int main()
{
    int n,m,i,a,b,c,x,y,z;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        a=0;    b=0;    c=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x>a||x==a && y<b||x==a && y==b && z>c) { a=x;b=y;c=z; }
        }
        printf("%d\n",c);
    }
    return 0;
}

*/

/*

//260-����Сľ��
#include<stdio.h>
int main()
{
    int N,n,i,j,sum;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        sum=0;
        while(n>0)
        {
            for(i=n;i>0;i--) sum+=i;      //��n�����������
            n--;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//259-����ĵ�һ��
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{
    int N,i,len;
    char a[20];

    scanf("%d",&N);
    while(N--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",&a);
        len=strlen(a);
        for(i=0;i<len;i++) printf("%c",a[i]);
        printf("\n");
    }
}

*/

/*

//255-CС�� ֮ �����
#include<stdio.h>
int main()
{
    int N,n,i,j,a[100],b[100],t,nums;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            t=a[i];
            for(j=i+1;j<n;j++)
            {
                if(t==a[j]) a[j]=0;
            }
        }
        j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                b[j]=a[i];
                j++;
            }
        }
    //sort
        nums=j;
        for(i=0;i<nums-1;i++)
        {
            for(j=i+1;j<nums;j++)
            {
                if(b[i]>b[j])
                {
                    b[i]=b[i]^b[j];
                    b[j]=b[i]^b[j];
                    b[i]=b[i]^b[j];
                }
            }
        }
        printf("%d\n",nums);
        for(i=0;i<nums;i++) printf("%d ",b[i]);
        printf("\n");
    }
}

*/

/*

//103-A+B Problem II
#include<stdio.h>
#include<string.h>
int main()
{
    char a1[1100],b1[1100];
    int    T;
    while(scanf("%d",&T)!=EOF)
    {
        int i1,i,j,k,k1,La,Lb,t,L;

        for(i1=1;i1<=T;i1++)
        {
            int a[1100]={0},b[1100]={0},c[1100]={0};
            scanf("%s%s",&a1,&b1);
            La=strlen(a1);
            Lb=strlen(b1);
            printf("Case %d:\n",i1);
            for(i=0;i<La;i++)//�����һ����
            {
                printf("%c",a1[i]);
            }
            printf(" + ");
            for(i=0;i<Lb;i++)//����ڶ�����
            {
                printf("%c",b1[i]);
            }
            printf(" = ");
            for(j=La-1,t=0;j>=0;j--,t++)//����
            {
                a[t]=a1[j]-'0';
            }
            for(k=Lb-1,t=0;k>=0;k--,t++)//����
            {
                b[t]=b1[k]-'0';
            }
            L=(La>=Lb?La:Lb);
           for(i=0;i<=L-1;i++)//�ӷ�����
           {
               c[i]+=(a[i]+b[i]);
               if(c[i]>=10)     //��λ
               {
                   c[i]%=10;
                   c[i+1]++;
               }
           }
           if(c[L]!=0)
           {
               L++;
           }
           for(i=L-1;i>=0;i--)//���������
           {
               printf("%d",c[i]);
           }
           printf("\n");

        }
    }
    return 0;
}

*/

/*

//244-16���Ƶļ�����
#include<stdio.h>
#include<string.h>
int main()
{   int N,i,s1,s2,sum;
    char ch;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%x%c%x",&s1,&ch,&s2);
        switch (ch)
        {
        case '+':
            sum=s1+s2;
            printf("%o\n",sum);
            break;

        case '-':
            sum=s1-s2;
            printf("%o\n",sum);
            break;
        }
    }
}

*/

/*

//243-�������
#include<stdio.h>
int main()
{   int N,a[100],i,t,min;

    for(;;)
    {
        scanf("%d",&N);
        if(N==0) break;
        for(i=0;i<N;i++) scanf("%d",&a[i]);
        min=a[0];
        for(i=0;i<N;i++)
        {
            if(min>a[i])
            {
                min=a[i];
                t=i;        //��¼�±�
            }
        }
        if(min!=a[0])       //��һ����������С
        {
            a[0]=a[0]^a[t];
            a[t]=a[0]^a[t];
            a[0]=a[0]^a[t];
        }
        for(i=0;i<N;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}

*/

/*

//242-���������
#include<stdio.h>
#define pi 3.1415926
int main()
{   double r,v;

    while(~scanf("%lf",&r))
    {
        v=4.0/3.0*pi*r*r*r;
        printf("%.0f\n",v);
    }
}

*/

/*

//241-��ĸͳ��
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{   int N,len,n,a[26],i,max,tem;
    char s[1010],t;

    scanf("%d",&N);
    while(N--)
    {
        memset(a,0,sizeof(a));  //��������
        scanf("%s",&s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            n=s[i]-'a';
            a[n]++;             //��¼ÿ����ĸ���ִ���
        }
        tem=a[0];   max=0;
        for(i=0;i<26;i++)
        {
            if(tem<a[i])
            {
                max=i;
                tem=a[i];
            }
        }
        t='a'+max;
        printf("%c\n",t);
    }
}

*/

/*

//113-�ַ����滻
#include<stdio.h>
#include<string.h>
int main()
{   int i;
    char s[1002];

    while(gets(s)!=0)
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            {
                printf("we");
                i+=2;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
}

*/

/*

//111-�����Ӽ���
#include<stdio.h>
#include<math.h>
int yjj(int n,int m)        //�����Լ��
{
	int t,x;
	if(m>n)
	{t=n;n=m;m=t;}
	while(m)
	{
		x=n%m;
		n=m;
		m=x;
	}
	return n;
}
int main()
{
	int a,b,c,d,e,f;//��ͻ������eΪ���ӣ�fΪ��ĸ
	char ch;
	while(scanf("%d/%d%c%d/%d",&a,&b,&ch,&c,&d)!=EOF)
	{
		int k,temp=1;//tepm�жϽ��������1Ϊ����0Ϊ�� ��kΪ���Լ��
		f=b*d;
		switch(ch)
		{
			case '+':
				e=a*d+b*c;
				break;
			case '-':
				e=a*d-b*c;
				if(e<0)
				{
					e=fabs(e);
					temp=0;
				}
				break;
		}
		if(temp==0) printf("-");
		if(e==0) printf("0\n");
		else if(e%f==0) printf("%d\n",e/f);         //��������������ֱ�����һ������
		else
		{
			k=yjj(e,f);
			e/=k;
			f/=k;
			printf("%d/%d\n",e,f);
		}
	}
	return 0;
}

*/

/*

//101-�������
#include<stdio.h>
#include<math.h>
int main()
{   double x1,y1,x2,y2,t;
    int N;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);      //�����ʱ�����뵥����(float��)Ҫ��%f������˫����(double��)Ҫ��%lf
        t=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2f\n",t);
    }
}

*/

/*

//100-1�ĸ���
#include<stdio.h>
int main()
{   int N,i,n,a[20],count;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&n);
        i=0;
        while(n>0)
        {
            a[i]=n%2;
            n/=2;
            i++;
        }
        i-=1;
    for(;i>=0;i--) if(a[i]==1) count++;
    printf("%d\n",count);
    }
}

*/

/*

//97-�ֵܽ�������
#include<stdio.h>
int main()
{   int N,x,y,z,m;
    float t,s;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d%d%d",&m,&x,&y,&z);
        t=x*m*1.0/(y-x);                             //�������һ���ĵ�ΪɶҪ��1.0?
        s=z*t;
        printf("%.2f\n",s);
    }
}

*/

/*

#include<stdio.h>
int main()
{
    int M,n,t;
    int i,j,k,c;
    scanf("%d",&M);
    for(i=1;i<=M;i++)
        {
            scanf("%d",&n);
            j=0;t=n;c=1;
            while(t)
            {
                t/=10;
                j++;            //j��¼n��λ��
            }
            for(k=0;k<j-1;k++)
            {
                c=c*10;         //c�Ĵ�СΪ(n-1)*10
            }
            printf("%d\n",n%c);
        }

return 0;
}

*/

/*

//96-n-1λ��
#include "stdio.h"
#include <string.h>
int main()
{	int N,n,a[20],i,count1,count2;

	scanf("%d",&N);
	while(N--)
	{
	    count2=0;
		scanf("%d",&n);
		i=0;
		while(n>10)
		{
			a[i]=n%10;
			n/=10;
			count2++;
			i++;
		}
		count1=0;
		for(i=count2-1;i>=0;i--)
		{
			if(a[i]==0) count1++;	//��¼�ж���λ��0
			printf("%d",a[i]);
		}
		if(count1==count2) printf("0");		//��n-1λ����0
		printf("\n");
	}
}

*/

/*

//cigarettes
#include <stdio.h>
int main()
{   int N,a,b,i,sum;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        sum=a;
        while(a/b>=1)
        {
            if(a==1) break;
            sum=sum+a/b;
            a/=b;
        }
    printf("%d\n",sum);
    }
}

*/


/*

//�����(һ��
#include <stdio.h>
int main()
{   int n,m,a[1001],b[1101],i,j;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        for(j=0;j<m;j++)
        {
            if(b[i]==a[j])
            {
                printf("YES\n");
                break;
            }
        }
        if(j==m) printf("NO\n");
    }
}


*/


/*

//��������
#include <stdio.h>
int main()
{   int n,k,i,j,a[1001];

    scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++) a[i]=1;
        for(j=2;j<=k;j++)
        {
            for(i=j;i<=n;i+=j)
            {
                if(a[i]==0) a[i]=1;
                else a[i]=0;
            }
        }
    for(i=1;i<=n;i++) if(a[i]==1) printf("%d ",i);
}

*/


/*

//���ڼ���
#include <stdio.h>
int is_runnian(int y)
{
    if(y%400==0) return 1;
    else
    {
        if(y%100 !=0 && y%4==0) return 1;
        else return 0;
    }
}

int main()
{   int N,i,a,b,c,sum;
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d",&N);
    while(N--)
    {
        sum=0;
        scanf("%d%d%d",&a,&b,&c);
        if(is_runnian(a))
        {
            for(i=0;i<b-1;i++) sum+=m[i];
            if(b>=2) sum+=(c+1);
            else sum+=c;
        }
        else
        {
            for(i=0;i<b-1;i++) sum+=m[i];
            sum+=c;
        }
    printf("%d\n",sum);
    }
}

*/

/*

//Сѧ������
#include <stdio.h>
int main()
{   int i,j,m,n,ge1,shi1,bai1,ge2,shi2,bai2,count;

    while(scanf("%d%d",&m,&n) != EOF, m!=0 && n!=0)
    {
        count=0;
        ge1=m%10;
        ge2=n%10;
        shi1=m/10%10;
        shi2=n/10%10;
        bai1=m/100%10;
        bai2=n/100%10;
        if(ge1+ge2>9)
        {
            shi1+=1;
            count++;
        }
        if(shi1+shi2>9)
        {
            bai1++;
            count++;
        }
        if(bai1+bai2>9) count++;
    printf("%d\n",count);
    }
}

*/

/*

//�����ȴ�С
#include <stdio.h>
#include <string.h>
#define max 1000+10
char s1[max],s2[max];

int main()
{   int i,l1,l2;
    while(scanf("%s%s",s1,s2) != EOF)
    {
        if(s1[0]=='0' && s2[0]=='0' ) break;
        l1=strlen(s1);
        l2=strlen(s2);
        if(s1[0] == '-' && s2[0] != '-') printf("a<b\n");              //s1����s2��
        else if(s1[0] != '-' && s2[0] == '-') printf("a>b\n");       //s1����s2��
        else if(s1[0] != '-' && s2[0] != '-')                               //��Ϊ��
        {
            if(l1>l2) printf("a>b\n");
            else if(l1<l2) printf("a<b\n");
            else
            {
                if(strcmp(s1,s2)>0) printf("a>b\n");    //�����ַ���������������ַ���ȣ���ASCIIֵ��С��Ƚϣ���ֱ�����ֲ�ͬ���ַ�����'\0'Ϊֹ
                else if(strcmp(s1,s2)<0) printf("a<b\n");
                else printf("a==b\n");
            }
        }
        else                                                                    //��Ϊ��
        {
            if(l1>l2) printf("a<b\n");
            else if(l1<l2) printf("a>b\n");
            else
            {
                if(strcmp(s1,s2)>0) printf("a<b\n");
                else if(strcmp(s1,s2)<0) printf("a>b\n");
                else printf("a==b\n");
            }
        }
    }
}

*/

/*

//��С��
#include <stdio.h>
#include <memory.h>

#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))

void get_num(int a[], char str[])	            // �õ�ÿ����ĸ���ֵĸ���
{
	int i = 0;
	while (str[i]) a[str[i++]-'a']++;               //ѭ�����ַ�������λ��ֹͣѭ��
}

int is_prime(int x)	// �ж��ǲ�������
{   int i;
	if (x == 0 || x == 1) return 0;
	for (i=2; i<x; i++)
    {
        if (x%i == 0) return 0;
    }
       if(i==x) return 1;
}

int main()
{
	int T,i; char str[105];
	int a[26], minn, maxn;
	scanf("%d", &T);	                                        // ��һ�����������
	while (T--)
	{
		scanf("%s", str);	                                        // ÿ������ĵ��ʣ�ע����������붼��Сд��ĸ�ģ�û�пո�
		minn = 100;	                                            // ��minn��Ϊ���ֵ
		maxn = 0;	                                                // ��maxn��Ϊ��Сֵ
		memset(a, 0, sizeof(a));	                            // ����¼��������0���Ա��´μ�¼
		get_num(a, str);
		for(i=0;i<26;i++)
			if(a[i])	                                                // ���������һ����Ҫ���ֹ������������ж��ǲ��ǳ������Ļ������ٵ�,��Ȼ��ı���Сֵ
			{
				maxn = MAX(maxn, a[i]);
				minn = MIN(minn, a[i]);
			}	                                                         // ���ﲻ����������ĸ��Ӷ�������O(nlogn)�����õ���ֵ�ĸ��Ӷ�ֻҪɨһ��
		if (is_prime(maxn-minn))	                          // �����������ٵĲ��ǲ�������
            printf("Lucky Word\n%d\n", maxn-minn);
		else printf("No Answer\n0\n");
	}
}

*/

/*

//��һ�ֽ׳�����
#include<stdio.h>
int main()
{   int N,n,i,j,sum,Sum;
    scanf("%d",&N);
    while(N--)
    {
  Sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            sum=1;                  //ÿ���½׳�ǰ��sum����
            for(j=1;j<=i;j+=2)
            {
                sum*=j;
            }
                Sum+=sum;
        }
        printf("%d\n",Sum);
    }
}

*/

/*

//����ͬ��
#include<stdio.h>
int main()
{   int N,n,m,i,a,b;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&n,&m);
        a=n;    b=n-a;              //aΪ��������bΪ����
        for(i=1;i<100;i++)
        {
            if((a*4+b*2)==m) break;
            else
            {
                a--;
                b++;
            }
        }
        if(a>=0 && b>=0) printf("%d %d\n",b,a);
        else printf("No answer\n");
    }

}

*/

/*
//ʮ����ת������
#include<stdio.h>
#include<string.h>
int a[35];
int main()
{
	int n, i, j;
	while (scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		i=0;
        while(n!=0)
		{
			a[i++]=n%2;
			n=n/2;
		}
		while (i--)
        printf("%d", a[i]);
		printf("\n");
	}
}

*/


/*

//6174����
#include <stdio.h>
int sort(int num)
{   int a[4],b[4],i,j,max,min,tem;

        a[0]=num%10;
        a[1]=num/10%10;
        a[2]=num/100%10;
        a[3]=num/1000;
        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(a[i]<a[j])
                {
                    a[i]=a[i]^a[j];
                    a[j]=a[i]^a[j];
                    a[i]=a[i]^a[j];
                }
            }
        }
        min=a[3]*1000+a[2]*100+a[1]*10+a[0];
        max=a[0]*1000+a[1]*100+a[2]*10+a[3];
        tem=max-min;
        return tem;
}

int main()
{   int N,num,count,t;

    scanf("%d",&N);
    while(N--)
    {
        count=0;
        scanf("%d",&num);
        t=sort(num);
        while(t !=6174)
        {
            t=sort(t);
            count++;
            if(t==sort(t)) break;
        }
        printf("%d\n",count+2);
    }
}

*/

/*

//�׳���ʽ�ֽ�(һ)
#include <stdio.h>
int main()
{   int t;

    scanf("%d",&t);
    while(t--)
    {
        int n,m,sum=0;      //ÿ�θ���sum��ֵ

        scanf("%d%d",&n,&m);
        while(n>=m)
        {
        n/=m;
        sum+=n;
        }
        printf("%d\n",sum);
    }
}

*/

/*

//�ַ��������������磺<ABCDE-EDCBA>
#include<string.h>
int main()
{   char str[80];
    int i,j;

    printf("Enter a string:");
    scanf("%s",str);                            // Ҳ����gets(str);puts(str);
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        str[i]=str[i]+str[j];
        str[j]=str[i]-str[j];
        str[i]=str[i]-str[j];
    }
    printf("Reversed string:%s",str);
}

*/

/*

//�����׳�
#include <stdio.h>
int main()
{   int a[100001];                                     //����ÿһλ���õ�����
	int temp,digit,n,i,j=0;                           //tempÿ�εĵ���   digitÿ�ε�����λ��

	scanf("%d",&n);
	a[0]=1;                                                //��1��ʼ��
	digit=1;                                               //λ���ӵ�һλ��ʼ
	for(i=2;i<=n;i++)                                  //�˵�n������n
	{
		int num=0;                                      //���λ����
		for(j=0;j<digit;j++)
		{
			temp=a[j]*i+num;                        //��һ������ÿһλ�����ֱ����i��
			a[j]=temp%10;                            //��һ������ÿһλ������������д���
			num=temp/10;                           //num���浱ǰ���λ
		}
		while(num)                                    //�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0
		{
			a[digit]=num%10;                       //��������
			num/=10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)                            //�������ÿһλ
    printf("%d",a[i]);
	printf("\n");
}

*/



/*

//�׳���ʽ�ֽ⣨һ��

#include <stdio.h>
int main()
{
	int n,m,sum,s;
	scanf("%d",&s);
	while(s--)
	{
		sum=0;
		scanf("%d%d",&n,&m);
		while(n)
		{
			sum+=n/m;
			n=n/m;
		}
		printf("%d\n",sum);
	}
}

*/


/*

//�����˵�С��
#include<stdio.h>
int main()
{   int N,a[7],b[7],c[7],i,j,max,u;
    scanf("%d",&N);
    while(N--)
    {
        max=0;
        for(i=0;i<7;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            c[i]=a[i]+b[i];                 //��ʱ��
        }
        max=c[0];
        u=1;
        for(i=0;i<7;i++)    //�ж����ʱ��
        {
                if(max<c[i])
                {
                    max=c[i];
                    u=i+1;
                }
        }
        if(max<=8) printf("0\n");
        else printf("%d\n",u);
    }
}

*/

/*

//��ż������
#include<stdio.h>
int main()
{   int N,n,i;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=1;i<=n-1;i+=2) printf("%d ",i);
        printf("\n");
        for(i=2;i<=n;i+=2) printf("%d ",i);
        printf("\n\n");
    }
}

*/

/*

//���Լ������С������
#include<stdio.h>
int main()
{   int N,m,n,k,a,b;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&m,&n);
        if (m<n)
		{
			m=m^n;
			n=m^n;
			m=m^n;
		}

		if (m%n==0)         //m��n�ı��������
		{
			printf("%d %d\n",n,m);
		}

		else
		{	//��m��n�����Լ��
			for (k=1;k<n;k++)
			{
				if (m%k==0 && n%k==0)
				{
					a=k;                            // �������¹�Լ����ֱ�����
				}
			}
			b=m*n/a;//����С������
			printf("%d %d\n",a,b);
		}
    }
}

*/



/*

//ˮ�ɻ���
#include<stdio.h>
int main()
{   int i,n,bai,shi,ge;

    while(scanf("%d",&n), n!=0)
    {
        bai=n/100;
        shi=(n/10)%10;
        ge=n%10;
        if((bai*bai*bai+shi*shi*shi+ge*ge*ge)==n) printf("Yes\n");
        else printf("No\n");
    }
}

*/

/*

//���ŵ��
#include<stdio.h>
int main()
{   int a,b,c,min;
    scanf("%d %d %d",&a,&b,&c);
    min=a*70+b*21+c*15;
    while(min>105) min-=105;
    if(min>100 ||min<10 || a>=3 || b>=5 || c>=7) printf("No answer\n");
    else printf("%d\n",min);
}



//���ŵ������
#include <stdio.h>
int main()
{
    int a=0,b=0,c=0,x;
    scanf("%d%d%d",&a,&b,&c);
    for (x=10;x<=100;x++)
        if (x%3==a&&x%5==b&&x%7==c)
            {
                printf("%d",x);
                break;
            }
        else if(x==100)
                printf("no answer\n");
}

*/

/*

//���һ����5��������ȡ��С����������ĳ���
#include<stdio.h>
int main()
{   int i,j,t,a[5],max=0,min=0;

    for(i=0;i<5;i++) scanf("%d",&a[i]);
    for(i=0;i<5;i++)            //������
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    max=a[4]; min=a[0]; //
    printf("%d %d",min,max);
}

*/



/*

//��һ���������е�ת�þ���
#include<stdio.h>
int main()
{   int N,i,a[9];

    scanf("%d",&N);
    while(N--)
    {
        for(i=0;i<9;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d %d %d\n",a[0],a[3],a[6]);
        printf("%d %d %d\n",a[1],a[4],a[7]);
        printf("%d %d %d\n\n",a[2],a[5],a[8]);
    }
}

*/




/*

//���ڸ�����һЩ����Ҫ����д��һ�����������Щ����������������������������೤�ȡ�
//��������еȾ��볤�����������������ֵ����Ӧ���롣�����������������������������������������������0

#include<stdio.h>
int main()
{   int N,i,m,l,r,zss,yss;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&m);
        for(i=2;i<m;i++)
        {
            if(m%i==0) break;
        }
        if(m==i) printf("%d 0\n",m);      //m��������ֱ�Ӵ�ӡ
        else                                        //m��������
        {
                l=m;    r=m;
                zss=0;
                while( l>=2 && zss==0 )    //Ѱ������������
                      {
                            l--;
                            for(i=2;i<l;i++)
                            {
                                if(l%i==0) break;
                            }
                            if(l==i) zss=1;      //�ҵ������������
                      }
                yss=0;
                while(yss==0)    //Ѱ���ұ��������
                      {
                            r++;
                            for(i=2;i<r;i++)
                            {
                                if(r%i==0) break;
                            }
                            if(r==i) yss=1;      //�ҵ������������
                      }
        if(m-l>r-m) printf("%d %d\n",r,r-m);
        else if(m-l<=r-m) printf("%d %d\n",l,m-l);
        }
    }
}

*/

/*

//���ڸ���N������0<N<1000��������Ҫ����д��һ�������ҳ���N�����е����������������
#include<stdio.h>
void main()
{   int n,N,i,j,a[1001],sum;

    scanf("%d",&N);
    while(N--)              //��������
    {
        sum=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)   //ÿ�������������
        {
            scanf("%d",&a[j] );
            for(i=2;i<a[j];i++)
            {
                if(a[j]%i==0) break;            //�б��Լ���ͷ�����������ѭ��
            }
            if(i==a[j]) sum+=a[j];
        }
    printf("%d\n",sum);
    }
}

*/


/*

//A number sequence is defined as follows:
//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//Given A, B, and n, you are to calculate the value of f(n).

#include<stdio.h>
void main()
{   int p,n,a,b,i;
    int array[48];

    while( scanf("%d%d%d",&a,&b,&n),a || b || n )       //�ж����������ʽ�ӵ�ֵ�����һ�����ź��ʽ�ӵ�ֵ
    {
        array[1]=1; array[2]=1;
            for(i=3;i<48;i++) array[i]=(a*array[i-1]+b*array[i-2]) %7;
                printf("%d\n",array[n%48]);
    }
}

*/



/*

//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
//For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14

#include<stdio.h>
void main()
{   int N,n,i,j;
    int a[100001];

    scanf("%d",&N);     //��������

    for(j=1;j<=N;j++)
    {
        scanf("%d",&n);             //�������ֵĸ���
        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        int maxsum=a[i],sum=0,l=1,r=1,teml=1;

        for(i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum>maxsum)              //sum����һ������
            {
                maxsum=sum;
                l=teml;
                r=i;
            }
            if(sum<0)                       //sum����һ����С�ĸ���
            {
                sum=0;
                teml=i+1;
            }
        }
            printf("Case %d:\n",j);
            printf("%d %d %d\n",maxsum,l,r);
            if(j< N) printf("\n");
    }

}

*/


/*

#include<stdio.h>
int main()
{
    int N;
    int count=1;
    scanf("%d",&N);
    while(N--)
    {
        int n,i;
        int a[100002];

        scanf("%d",&n);

        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

        int max=a[1];
        int sum=0;
        int l=1,left=1,right=1;

        for(i=1;i<=n;i++)
        {
            sum=sum+a[i];
            if(sum>max)
            {
                max=sum;
                left=l;
                right=i;
            }
            if(sum<0)
            {
                sum=0;
                l=i+1;
            }
        }
        printf("Case %d:\n",count);
        printf("%d %d %d\n",max,left,right);
        if(N)printf("\n");
        count++;
    }
    return 0;
}


*/
