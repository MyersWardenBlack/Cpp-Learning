//第一题 蓝桥杯真题

//输入一行包含一个单词，单词只由小写英文字母组成。对于所有的评测用例，输入的单词长度不超过 1000。
//输出两行，第一行包含一个英文字母，表示单词中出现得最多的字母是哪 个。如果有多个字母出现的次数相等，输出字典序最小的那个。
//第二行包含一个整数，表示出现得最多的那个字母在单词中出现的次数。
//示例： 输入 longlonglongistoolong
//输出：
//o
//6

#include <bits/stdc++.h>      //万能头文件 
using namespace std;
int c[26];                    //应该是建一个26位的 “列表” ？

int main()
{
  string a;                   //字符串
  char max;                   //出现最多的字母
  int maxcount = 0;          //出现的次数
  cin>>a;
  for(int i = 0; i< a.length(); i++)
  {
    c[a[i]-97]++;       //有一个字母 就加一
  }
  for(int i = 0; i < 26; i++)
  {
    if(c[i]>maxcount)       
    {
      maxcount = c[i];          //  个数转化为次数
      max = i + 97;             
    }
  }
  cout<<max<<endl<<maxcount<<endl;
  return 0;
}


//蓝桥杯 第二题
//小蓝给学生们组织了一场考试，卷面总分为 100 分，每个学生的得分都是一个 0 到 100 的整数。如果得分至少是 60 分，则称为及格。如果得分至少为 85 分，则称为优秀。
//请计算及格率和优秀率，用百分数表示，百分号前的部分四舍五入保留整 数。
//输入的第一行包含一个整数 n 表示考试人数。接下来 nn 行，每行包含一个 0 至 100 的整数，表示一个学生的得分。
//输出两行，每行一个百分数，分别表示及格率和优秀率。百分号前的部分 四舍五入保留整数。
//输入
7
80
92
56
74
88
100
0
//输出
71%
43%
  
//第一次提交
#include <iostream>
using namespace std;
int main()
{
    int n;
    int num1 = 0;       // num1 及格的数量 ，num2 优秀的个数
    int num2 = 0;       //这里一开始没有定义好 num1, num2
    cin>>n;
    int score[n];          //创建一个数组，每个元素代表每个成绩
  
    for(int i = 0; i < n; i++)
    {
        cin>>score[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(score[i] >= 60)
        {
            num1++;
        }
        if(score[i] >= 85)
        {
            num2++;
        }
    }
  
    int A = (num1*100/n) + 0.5;         //下边会说到，num1*100/n 仍然是整数运算，失精度
    int B = (num2*100/n) + 0.5;

    cout<<A<<"%"<<endl;
    cout<<B<<"%"<<endl;

    return 0;
}

//第二次提交
//这次只写改动的部分 循环体改动了一下
    for(int i = 0; i < n; i++)
    {
        cin>>score[i];
        if(score[i] >= 60)
        {
            num1++;      //计算 num1
        }
        if(score[i] >= 85)
        {
            num2++;      //计算num2
        }
    }

//第三次提交 最终结果
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;             //输入第一行， n
    int a = 0,b = 0;   //a 及格的数量 ，b优秀的数量
    for(int i = 0; i < n; i++)
    {
        int x;       // x输入的每一行成绩
        cin>>x;
        if(x >= 60)
        {
            a++;      //计算a
        }
        if(x >= 85)
        {
            b++;      //计算b
        }
    }
    cout<<(int)((100.*a/n)+0.5)<<"%\n"<<(int)((100.*b/n)+0.5)<<"%\n";
    //100 . * 中的 . 主要是为了保证 100*a/n的计算过程中不失精度(毕竟不加 . 的话也算是整数型计算)

    return 0;
}
