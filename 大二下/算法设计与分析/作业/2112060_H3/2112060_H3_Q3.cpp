#include<iostream>
#include<queue>
using namespace std;
int* BFS(int i, int n, int matrix[50][50], int* layer)
{
	queue<int>q;//队列
	bool* visited = new bool[n];//记录是不是被访问过
	int* ans = new int[n];//保存输出结果

	int a = 0;
	for (int j = 0; j < n; j++)
	{
		visited[j] = false;//初始化都为false
	}
	q.push(i);//把第一个节点放进去
	visited[i] = true;
	layer[i] = 0;//第一个节点是第0层
	while (!q.empty())
	{
		ans[a] = q.front();//存头结点
		q.pop();//出头结点
		for (int b = 0; b < n; b++)//遍历找点
		{
			if (matrix[ans[a]][b] == 1 && visited[b] == false)//如果边存在且之前没有访问过
			{
				visited[b] = true;//访问过
				q.push(b);//加入队列
				layer[b] = layer[ans[a]] + 1;//l新加入的b节点层数是ans[a]节点层数+1
			}
		}
		a++;
	}
	return ans;
}
int main()
{
	int n;//无向图中有n个节点
	int m;//无向图中有m条边
	int i;//从i开始BFS
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	int matrix[50][50] = { 0 };//无向图的邻接矩阵
	int* layer = new int[n];//记录每个节点第几层
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	int* A = new int[n];
	int flag = 1;
	for (int i = 0; i < n; i++)//每个节点开始进行BFS遍历
	{
		A = BFS(i, n, matrix, layer);
		//cout <<"从"<<i<<"开始的BFS遍历序列" << endl;
		//for (int j = 0; j < n; j++)//输出的是BFS遍历序列
		//{
		//	cout << A[j] << " ";
		//}
		//cout << endl;
		//cout << "从" << i << "开始的BFS遍历序列每个节点所在层数" << endl;;
		//for (int j = 0; j < n; j++)
		//{
		//	cout << layer[j] << " ";
		//}
		//cout << endl;
		for (int p = 0; p < n; p++)
		{
			for (int q = i + 1; q < n; q++)//遍历找同层节点
			{
				if (layer[p] == layer[q] && matrix[p][q] != 0)//同层且有连线
				{
					flag = 0;//标记0，退出查找
					break;
				}
			}
		}
	}
	if (flag == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}