//三只小猪称体重

#include <iostream>
using namespace std;
int main()
{
    int A,B,C;
    cout<<"请输入A小猪的体重:"<<endl;
    cin>>A;
    cout<<"请输入B小猪的体重:"<<endl;
    cin>>B;
    cout<<"请输入C小猪的体重:"<<endl;
    cin>>C;
    if(A<B)
    {
        if(B>C)
        {
            cout<<"体重最重的小猪是:B"<<endl;
        }
        else if(B<C)
        {
                cout<<"体重最重的小猪是:C"<<endl;
        }
    }
    else if(A>B)
    {
        if(A>C)
        {
            cout<<"体重最重的小猪是:A"<<endl;
        }
        else if(A<C)
        {
            cout<<"体重最重的小猪是:C"<<endl;
        }
    }
return 0;
}



//伪随机数

#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e;

    e = rand()%100;
    cout<<e<<endl;
    b = rand()%100;
    cout<<b<<endl;
    c = rand()%100;
    cout<<c<<endl;
    d = rand()%100;
    cout<<d<<endl;
return 0;
}



//水仙花数

#include <iostream>
using namespace std;
int main()
{
    int num = 100;
    int a,b,c;
    do
    {
        a = num%10;
        b = (num/10)%10;
        c = num/100;
        if(a*a*a+b*b*b+c*c*c==num)
        {
            cout<<num<<endl;
        }
        num++;
    }while(num<1000);

    return 0;
}



//乘法口诀表

#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; i < 10; i++)
    {

        for(int j=1; j<=i; j++)
        {
            cout<<j<<"*"<<i<<"="<<j*i<<" ";

        }
        cout<<endl;
    }

    return 0;
}



//寻找数组中的最大值

#include <iostream>
using namespace std;
int main()
    {
        int arr[5]={10,20,30,40,50};
        int max = 0;
        for(int i = 0;i<5;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }

    cout<<max<<endl;
    return 0;

    }


//寻找数组最大值2

#include <iostream>
#include <algorithm>
using namespace std;
int main()
    {
        int arr[5]={10,20,30,40,50};
        sort(arr,arr+5,greater<int>() );
        cout<<arr[0]<<endl;

        return 0;

    }



//数组元素逆置

#include <iostream>

using namespace std;
int main()
{
    int arr[5]={0,3,5,7,8};
    int arr2[5];
    for(int i=0;i<5;i++)
    {
        arr2[i]=arr[4-i];
        cout<<arr2[i]<<endl;
    }

return 0;
}



//冒泡排序
#include <iostream>
using namespace std;
int main()
 {
    int arr[9]={4,2,8,0,5,7,1,3,9};

    cout<<"排序前的结果是:"<<endl;
    for(int i=0; i<9; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;                     //换行

    for(int i = 1; i < 9; i++)          //一共需要排序几轮，总个数-1=8轮
    {
        for(int j = 0; j < 9-i; j++)       //每一轮需要排序几次，总个数-第几轮=次数
        {
            if(arr[j] > arr[j+1])
            {
                int mid=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=mid;           //交换两个元素的神秘代码 doge
            }
        }
    }
     cout<<"排序后的结果是:"<<endl;
     for(int i=0; i<9; i++)
     {
         cout<<arr[i]<<" ";             //输出
     }
    return 0;
 }



//二维数组  成绩单     我好不容易心动一次，你却让我输的这么彻底

#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {
            {100,100,100},
            {90,50,100},
            {60,70,80}
    };

    for(int i = 0; i < 3; i++)
    {
        int zong = 0;
        for(int j = 0; j < 3; j++)
        {
            zong=arr[i][j] + zong;

        }
        cout<<"score"<<zong<<endl;
    }

    return 0;
}



//函数常见形式 有参有返

#include <iostream>
using namespace std;
int test04(int a,int b)     //有返回值就有返回值类型
{
    return a;               //返回值
}
int main()
{
    int c = test04(100,200);
    cout<<c<<endl;

return 0 ;
}



//返回两个数之中的最大值
//函数的声明是定义的函数在main函数下边的情况

#include <iostream>
using namespace std;

int max(int a,int b);   //函数的声明，声明可以有多次，但是定义只能有一次

int main()
{
    int a = 10;
    int b = 30;
    cout<<max(a,b)<<endl;
    return 0;
}
int max(int a,int b)            //（函数的定义）这一行移上去，加个分号就可以了
{
    return (a > b ? a: b);
}





























































































