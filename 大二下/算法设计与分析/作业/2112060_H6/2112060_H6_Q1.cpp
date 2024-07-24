#include<iostream>
#include<map>
#include<set>
using namespace std;
int main() 
{
	int n;//点的数量
	cin >> n;
	int e;
	cin >> e;//边的数量
	int* start = new int[e];//起始点
	int* end = new int[e];//终点
	int* length = new int[e];//权值
	int matrix[50][50];
	set<int>node;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			matrix[i][j] = 0;//邻接矩阵全部初始化为0
		}
    }
	for (int i = 0; i < e; i++)
	{
		cin >> start[i] >> end[i] >> length[i];
		matrix[start[i]][end[i]] = length[i];
		matrix[end[i]][start[i]] = length[i];//邻接矩阵
	}
	for (int i = 0; i < e - 1; i++)
	{
		for (int j = 0; j < e - i - 1; j++)
		{
			if (length[j] > length[j + 1])
			{
				int temp;
				temp = length[j];//根据length大小调整顺序
				length[j] = length[j + 1];
				length[j + 1] = temp;

				int temp1;
				temp1 = start[j];
				start[j] = start[j + 1];
				start[j + 1] = temp1;

				int temp2;
				temp2 = end[j];
				end[j] = end[j + 1];
				end[j + 1] = temp2;
			}
		}
	}
	int sum = 0;//路径和
	//假设从最短的那条边的其中一个顶点开始
	node.insert(start[0]);
	node.insert(end[0]);//把最短的那条边的两个点加入集合
	sum += length[0];
	while (node.size() != n)//点集没满，继续查找点
	{
		int min_length = 10000000;//先设置成比较大的length
		int pos;//记录最短边的位置
		for (int i = 0; i < e; i++)
		{
			if (node.count(start[i]) || node.count(end[i]))
			{
				if (node.count(start[i])&& node.count(end[i]) == 0)//找集合中现有的点出发的其他边，不能找到重复的边，也不能和已经访问过的点形成环
				{
					if (min_length > length[i])//更短
					{
						min_length = length[i];
						pos = end[i];
					} 
				}
				else if (node.count(end[i]) && node.count(start[i]) == 0)//找集合中现有的点出发的其他边，不能找到重复的边，也不能和已经访问过的点形成环
				{
					if (min_length > length[i])//更短
					{
						min_length = length[i];
						pos = start[i];
					}
				}
			}
		}
		sum += min_length;//加上下一个最短边
		node.insert(pos);//把这个点加入集合
	}
	cout << sum;
	return 0;
}