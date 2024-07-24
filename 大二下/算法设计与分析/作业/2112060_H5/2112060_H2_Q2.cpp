#include<iostream>
using namespace std;
int* dijkstra(int graph[50][50], int n, int x)//邻接矩阵，n个节点，从x节点开始访问其余节点
{
	int* distance = new int[n];//用来记录到每个节点的最短距离
	for (int i = 1; i <= n; i++)
	{
		distance[i] = 100000000000;//先设置成一个极大的数
		if (distance[i] > graph[x][i])
		{
			distance[i] = graph[x][i];//把从x可以直接到达的顶点的距离变成相应边的weight
		}
	}
	distance[x] = 0;//自己到自己的距离是0
	bool* visit = new bool[n];//表示每个节点还没被访问过
	for (int i = 1; i <= n; i++)
	{
		visit[i] = false;//初始化为0表示点未被访问
	}
	visit[x] = true;//自己一定访问过自己
	for (int i = 1; i <= n; i++)
	{
		int pos = -1;//用来记录到集合中元素距离最短的顶点
		int temp = 100000000000;//用来记录到集合中元素最短距离
		for (int j = 1; j <= n; j++)//用来找到下一个加入集合的点
		{
			if (visit[j] == 0 && distance[j] < temp)//这个节点没有访问过没在集合里
			{
				pos = j;//记录当前最短距离的顶点
				temp = distance[j];//记录当前的最短距离
			}
		}
		visit[pos] = true;//把找到的这个点加入集合
		for (int j = 1; j <= n; j++)//重新计算当前可到达的最短距离
		{
			if (visit[j] == 0 && distance[j] > graph[pos][j] + temp)//点没在集合里,但可达，或最短距离有变化可以更新
			{
				distance[j] = graph[pos][j] + temp;//记录当前没在集合中的点从x访问的最短距离
			}
		}
	}
	return distance;
}
int main()
{
	int n;//n个节点
	cin >> n;
	int m;//m条边
	cin >> m;
	int x;
	cin >> x;//表示从x节点开始访问其余节点
	int weight[50][50];//二维数组存储权值
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			weight[i][j] = 100000000000;//初始化成极大值
		}
	}
	for (int i = 0; i < m; i++)
	{
		int start;
		int end;
		cin >> start >> end;// start->end
		cin >> weight[start][end];//weight
	}
	int* Dis=dijkstra(weight, n, x);
	for (int i = 1; i <= n; i++)
	{
		cout << Dis[i] << " ";
	}
	return 0;
}