//


//1-29
#include <iostream>
using namespace std;

int GCD(int x, int y){
   int t;
   t = x % y;
   while(t != 0){
      x = y;
      y = t;
      t = x % y;
   }
   return y;
}

int LCM(int x, int y){
   int g;
   g = GCD(x, y);
   return (x * y / g);
}

int main()
{
   int a, b;
   cin>>a>>b;
   cout<<GCD(a, b)<<" "<<LCM(a, b)<<endl;
   return 0;
}
