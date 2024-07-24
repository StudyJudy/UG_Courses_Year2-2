#include <iostream>
#include <fstream>
#include <algorithm>
#include<cmath>
using namespace std;

FILE* stream;
int read()
{
    int x = 0, t = 1;
    char ch = getchar();
    while ((ch < '0' || ch>'9') && ch != '-')ch = getchar();
    if (ch == '-')t = -1, ch = getchar();
    while (ch <= '9' && ch >= '0')x = x * 10 + ch - 48, ch = getchar();
    return x * t;
}
int p, tA[101], tB[101], kA[101], kB[101];
int nA, nB;
int f1[101][101][101];
int C[101][101][101];
int P[101][101][2];

int main()
{
    freopen_s(&stream, "hpc.in", "r", stdin);
    freopen_s(&stream, "hpc.out", "w", stdout);
    nA = read();
    nB = read();
    p = read();
    for (int i = 1; i <= p; ++i)
    {
        tA[i] = read(), tB[i] = read(), kA[i] = read(), kB[i] = read();
    }
    for (int i = 1; i <= p; i++)//p
    {
        for (int K = 0; K < 101; K++)
        {
            for (int l = 0; l < 101; l++)
            {
                for (int m = 0; m <= 1; m++)
                {
                    P[K][l][m] = 10000000;
                }
            }
        }
        P[0][0][0] = 0;
        P[0][0][1] = 0;
        for (int j = 0; j <= nA; j++)//A
        {
            for (int m = 0; m <= nB; m++)//B
            {
                for (int w = 1; w <= j; w++)
                {
                    P[j][m][0] = min(P[j][m][0], P[j - w][m][1] + tA[i] + kA[i] * w * w);
                }
                for (int w = 1; w <= m; w++)
                {
                    P[j][m][1] = min(P[j][m][1], P[j][m - w][0] + tB[i] + kB[i] * w * w);
                }
                f1[j][m][i] = min(P[j][m][0], P[j][m][1]);
            }
        }
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            for (int m = 0; m < 101; m++)
            {
                C[i][j][m] = 10000000;
            }
        }
    }
    for (int j = 0; j <= nA; j++)
    {
        for (int m = 0; m <= nB; m++)
        {
            C[j][m][1] = f1[j][m][1];
        }
    }

    for (int i = 2; i <= p; i++)//p
    {
        for (int j = 0; j <= nA; j++)//A
        {
            for (int m = 0; m <= nB; m++)//B
            {
                for (int w1 = 0; w1 <= j; w1++)
                {
                    for (int w2 = 0; w2 <= m; w2++)
                    {
                        C[j][m][i] = min(C[j][m][i], max(C[j - w1][m - w2][i - 1], f1[w1][w2][i]));
                    }
                }
            }
        }
    }
    // 将结果输出到输出文件
    printf("%d\n", C[nA][nB][p]);
    return 0;
}
