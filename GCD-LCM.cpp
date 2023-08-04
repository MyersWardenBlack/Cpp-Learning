//《算法训练营（入门篇）》-陈小玉


//1-29
#include <iostream>
using namespace std;

int GCD(int x, int y){         //最大公因数GCD
   int t;
   t = x % y;
   while(t != 0){
      x = y;
      y = t;               //交换
      t = x % y;
   }
   return y;
}

int LCM(int x, int y){         //最小公倍数LCM
   int g;
   g = GCD(x, y);
   return (x * y / g);         //LCM = 两个数相乘除以最大公因数
}

int main()
{
   int a, b;
   cin>>a>>b;
   cout<<GCD(a, b)<<" "<<LCM(a, b)<<endl;
   return 0;
}
