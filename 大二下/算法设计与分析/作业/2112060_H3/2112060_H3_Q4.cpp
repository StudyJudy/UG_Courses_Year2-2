#include<iostream>
using namespace std;
int main()
{
	int n;//有向图中有n个节点
	int m;//有向图中有m条边
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	int matrix[50][50] = { 0 };//有向图的邻接矩阵
	int a, b;
	int* ans = new int[n];//储存答案
	int c = 0;
	int* visited = new int[n];//记录是不是已经查到过
	for (int i = 0; i < n; i++)//初始都是没查到过，为0
	{
		visited[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;//一条边的两个点
        matrix[a][b] = 1;//邻接矩阵中该点标记为1
	}
	int flag = 1;
	while (flag)//不是所有点都进入了输出数组
	{
		for (int i = 0; i < n ; i++)//从0开始遍历每个点没被找到过的点，一个点只有出度，没有入度才能输出从有向图中拿掉
		{
			int j;
			if (visited[i] == 0)
			{
				for (j = 0; j < n; j++)//找每个点的列
				{
					if (matrix[j][i] != 0)
					{
						break;
					}
				}
				if (j == n)//一整列都是0
				{
					ans[c++] = i;//找到一个点，进入输出数组
					visited[i] = 1;
					//cout << i << " ";
					for (int k = 0; k < n; k++)//把这个点从有向图中拿掉，在矩阵中这一行均变成0
					{
						matrix[i][k] = 0;
					}
					if (c == n)
					{
						flag = 0;
					}
					break;
				}
			}

		}
	}
	cout << "拓扑排序序列" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}