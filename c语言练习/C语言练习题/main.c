




#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int i,j,n;
    n=sizeof(nums)/4;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        if(*(nums+i)+*(nums+j)==target)

}


/*

//������ܺͽ���
#include <stdio.h>
#include<string.h>
int main()
{
    char s1[100],s2[100]={0},s3[100]={0},i;     //ע�⽫�ַ�����ʼ�����������ִ���

    scanf("%s",s1);
    printf("���������Ϊ:%s\n",s1);
    for(i=0;i<strlen(s1);i++)
        s2[i]=s1[i]^0x66;
    printf("���ܺ������Ϊ:%s\n",s2);
    for(i=0;i<strlen(s2);i++)
        s3[i]=s2[i]^0x66;
    printf("���ܺ������Ϊ:%s\n",s3);
}

*/

/*

#include <stdio.h>
#include<stdlib.h>
int main()
{
    struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2)
    {
        int x=0,y=0,sum=0,carry=0,num[100]={0},i=0;
        struct ListNode *p1=l1,*p2=l2,*head,*curr;
        head=NULL;  curr=head;
        while(l1!=NULL || l2!=NULL)
        {
            x=p1->val

        }
    }

}

*/

/*

//Elevator
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,a[200],t,sum;

    while(scanf("%d",&n),n!=0)
    {
        sum=0;
        scanf("%d",&a[0]);
        t=a[0];
        sum+=t*6+5;
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>t)
            {
                sum+=(a[i]-t)*6+5;
            }
            else sum+=abs(a[i]-t)*4+5;
            t=a[i];
        }
        printf("%d\n",sum);

    }

}

*/

/*

//9. ������
#include <stdio.h>
#include<string.h>
int main()
{
    int flag=1;
    char s[200],i,j;

    scanf("%s",s);
    for(i=0,j=strlen(s)-1;i<strlen(s)/2;i++,j--) if(s[i]!=s[j]) flag=0;
    if(flag==0) printf("false\n");
    else printf("true\n");
}

*/

/*

//1075 �����������
#include <stdio.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n,i,j,a[110],b[110],t;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    //ȥ��
    for(i=0;i<n;i++)
    {
        t=a[i];
        for(j=i+1;j<n;j++) if(t==a[j]) a[j]=-1;
    }
    j=0;
    for(i=0;i<n;i++) if(a[i]!=-1) b[j++]=a[i];
    //����
    qsort(b,j,sizeof(b[0]),cmp);    //b[0]�ǵ�һ��Ԫ�ض������׵�ַ,&b[0]�����׵�ַ

    printf("%d\n",j);
    for(i=0;i<j;i++)
    printf("%d ",b[i]);
}

*/



