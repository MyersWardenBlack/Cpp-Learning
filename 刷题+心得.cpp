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
