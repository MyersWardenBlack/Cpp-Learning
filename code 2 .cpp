//快速排序

void quick_sort(int s[],int l, int r)   //l is left, r is right
{
    int i = l, j = r;
    int x = s[l];   //s[l] is the first element in the list

    while (i < j)
    {
        while(i < j && s[j] > x)    //从右向左找大于x的数
        {
            j--;
            if(i < j)
            {
                s[i] = s[j];    //s[i] 即第一个数已经赋值给了 x
                i++;
            }
        }
        while(i < j && s[i]<=x)
        {
            i++;
            if(i < j)
            {

            }
        }
    }

}



#include <iostream>
using namespace std;

int main()
{
    int a[] = {};
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i <= N ; i++)
    {
        for (int j = i + 1; j <= N; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i<N;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}


//冒泡排序更新1.2
#include <iostream>
using namespace std;

int main()
{
    int arr[9]={4,2,8,0,5,7,1,3,9};

    for(int i = 0; i < 9-1 ; i++)       //-1
    {
        int flag = 0;
        for(int j = 0; j < 9-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }

    for(int i = 0; i<9; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0 ;
}




//归并排序-蓝桥杯讲解-洛谷1177

/*
假定有两个非递减的序列，如何将它们合并为一个非递减序列，分别比较其中的最小值，将最小的值依次放入另外一个序列
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100005;
int a[N],t[N];

void merge_sort(int L, int R){      //L是左序列的左端，R是右序列的右端
    if(L == R) return;
    int mid = (L + R) / 2;
    merge_sort(L, mid);
    merge_sort(mid+1, R);
    /*
    658行，保证L 到 mid 是有序的 一直二分下去，直到单个数字，再按照下边的函数重新排序，达到非递减的目的
     */
    int i = L, j = mid + 1, p = L;

    while(i <= mid && j <= R){
        if(a[i] <= a[j]) t[p++] = a[i++];   //小于等于保证了排序的稳定性，不同组中的相同数字，顺序一致
        else t[p++] = a[j++];
    }
    while(i <= mid) t[p++] = a[i++];
    while(j <= R) t[p++] = a[j++];
    for(int i=L ;i <= R; ++i) a[i] = t[i];
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }
    merge_sort(1,n);
    for(int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}




//前缀和
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
int a[N],s[N];
int main()
{
    int n; cin>>n;
    for(int i = 0; i< n; i++)		//要注意数组是以0开头的 所以下边的L 最小是0，R最大是4  得出的结果就是全部相加
    {
        cin>>a[i];
        s[i] = s[i-1] + a[i];       //循环 高中数列
    }

    int q; cin>>q;      //询问次数
    while(q--)
    {
        int L, R;		// S(R)-S(L-1),
        cin>>L>>R;		//输入的L R 位置和输出的位置相反哦
        cout<<s[R] - s[L-1]<<"";
    }
    return 0;
}



//二维数组前缀和

#include <iostream>
#include <cstdio>

using namespace std;
const int N =5005;
int a[N][N];    //N*N的二维数组
int s[N][N];    //直播里没有出现
int main()
{
    int n,m;            //n 行，m 列
    cin>>n;cin>>m;
    for(int i = 0; i < n;i++)
    {
        for(int j = 0 ;j < m; j++)
        {
            cin>>a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1] ;  //for循环里边是通解
        }
    }
    int q; cin>>q;
    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        cout<<s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]<<"";
    }
    return 0;
}





//差分思想 - 一维

#include <iostream>
using namespace  std;
const int N = 100005;
int a[N],d[N];
int main()
{
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int q; cin>>q;
    while(q--)      //q次更改，每次更改都让 L到R之间的范围每个加k
    {
        int L,R,k;
        cin>>L>>R>>k;
        d[L] += k;
        d[R+1] -= k;
    }
    for(int i = 0; i < n; i++)		//修改之后的数组 输出
    {
        d[i] += d[i-1];
        a[i] += d[i];
        cout<<a[i]<<" ";
    }
    return 0;
}
/*输入输出
5				//5个元素，分别是1 2 3 4 5
1 2 3 4 5
3				//进行三次更改（询问三次）
0 2 1			//第一个元素到第三个元素 每个加1
1 3 2			//第二个元素到第四个元素 每个加2
4 4 6			//第5个元素 加6
2 5 6 6 11 		//输出
*/




//二维差分
#include <iostream>
#include <cstdio>

using namespace std;
const int N =5005;
int a[N][N];    //N*N的二维数组
int d[N][N];

int main()
{
    int n,m;            //n 行，m 列
    cin>>n;cin>>m;
    for(int i = 0; i < n;i++)
    {
        for(int j = 0 ;j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    int q; cin>>q;
    while(q--)          //询问q次
    {
        int x1,x2,y1,y2,k;          //从(x1,y1) 到(x2,y2)的正方形 整体加上k
        cin>>x1>>y1>>x2>>y2>>k;
        d[x1][y1] += k;
        d[x2+1][y1] -=k;
        d[x1][y2+1] -= k;
        d[x2+1][y2+1] += k;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            a[i][j] += d[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n"<<"";
    }
    return 0;
}


//二分法 洛谷P1102 A-B 数对  有错误 未改正
#include <iostream>
using namespace std;
const  int N = 200005;
int a[N],t[N];

void merge_sort(int L, int R)
{
    if(L == R) return;
    int mid = (L+R)/2;
    merge_sort(L,mid);
    merge_sort(mid + 1,R);
    int i = L,j = mid + 1,p = L;
    while(i <= mid && j <=R)
    {
        if(a[i] <= a[j]) t[p++] = a[i++];
        else t[p++] = a[j++];
    }
    while(i<=mid) t[p++] = a[i++];
    while(j <= R) t[p++] = a[j++];
    for(int i = L; i <= R; i++) a[i] = t[i];

}
int main()
{
    int n,C;
    cin>>n>>C;
    for(int i = 0; i < n;i++)
    {
        cin>>a[i];
    }
    merge_sort(1,n);

    long long ans= 0;

    for(int i = 0; i < n; i++)
    {
        int B = a[i];
        int A = a[i] +C;
        int L = 1, R = n,AL = 0,AR = n+1;
        while(L <= R)
        {
            int mid = (L+R)/2;
            if(a[mid] >= A){
                AL = mid;
                R = mid -1;
            }else L = mid + 1;
        }

        L = 1, R = n;
        while(L <= R)
        {
            int mid = (L+R)/2;
            if(a[mid] <= A)
            {
                AR = mid;
                L = mid + 1;
            }else R = mid -1;
        }
        if(a[AL] != A || a[AR]!= A || AL>AR) continue;
        else ans += AR-AL +1 ;
    }
    cout<<ans<<"";
    return 0;
}
