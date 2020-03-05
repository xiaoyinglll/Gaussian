// Gaussian.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define maxn  20
double a[maxn][maxn];
double b[2][maxn];//用来记录解出来的根,本题用一维数组即可,二维数组是为完全主元素消元法做准备
int num;
void dengjia(int jj) {//把原矩阵转化成三角形的
    for (int i = jj + 1; i < num; i++) {
        double k =  a[i][jj]/ a[jj][jj];
        for (int j = jj; j <= num; j++) {
            a[i][j] = a[i][j] - a[jj][j] * k;
        }
    }
}
void jiefangcheng(int ii) {//解方程
    for (int j = ii + 1; j < num; j++)
    {
        a[ii][num] -= a[ii][j] * b[1][j];

        //cout << "l" << endl;
    }
    b[1][ii] = a[ii][num] / a[ii][ii];
    //cout << "h"<< b[1][ii] << endl;
}
int main()
{
    cout << "输入未知数个数:";
    cin >> num;
    cout << "输入用矩阵表示的线性方程组:" << endl;
    for (int i = 0; i < num; i++) {//输入方程组
        for (int j = 0; j <= num; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < num; i++) {//初始化计数数列
        b[0][i] = i;
        b[1][i] = 0;
    }
    for (int j = 0; j < num-1; j++)
    {
        dengjia(j);
       
    }
 
    for (int i = num - 1; i >= 0; i--) {
        jiefangcheng(i);
    }
   for (int j = 0; j < num; j++) {
        cout << "x"<<j+1<<"="<<b[1][j]<<endl;
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
