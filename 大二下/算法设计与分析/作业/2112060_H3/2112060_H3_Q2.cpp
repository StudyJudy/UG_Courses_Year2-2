#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int* BFS(int i, int n, int matrix[50][50])
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
			}
		}
		a++;
	}
	return ans;
}
int* DFS(int i, int n, int matrix[50][50])
{
	stack<int>stk;//栈
	bool* visited = new bool[n];//记录是不是被访问过
	for (int j = 0; j < n; j++)
	{
		visited[j] = false;//初始化都为false
	}
	int* ans = new int[n];//保存输出结果
	int a = 0;
	visited[i] = true;//第一个节点访问过了
	stk.push(i);//第一个节点入栈
	ans[a] = i;//第一个节点进入输出数组
	a++;
	while (!stk.empty())
	{
		int front = stk.top();//栈顶节点
		int j;
		for (j = 0; j < n; j++)
		{
			if (matrix[front][j] == 1 && visited[j] == 0)//有连线且没被访问过
			{
				visited[j]=true;//j节点访问过
				stk.push(j);//该节点入栈
				ans[a++] = j;//j节点进入输出数组
				break;//找到一个就停
			}
		}
		if (j == n)//都加入过栈了
		{
			stk.pop();//栈顶退栈
		}
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
	cout << "i= ";
	cin >> i;
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
	A = BFS(i, n, matrix);
	cout << "BFS遍历序列" << endl;
	for (int j = 0; j < n ; j++)//输出的是BFS遍历序列
	{
		if (A[j] >= 0)
		{
			cout << A[j] << " ";
		}
	}
	cout << endl;
	int* B = new int[n];
	B = DFS(i, n, matrix);
	cout << "DFS遍历序列" << endl;
	for (int j = 0; j < n ; j++)//输出的是DFS遍历序列
	{
		if (B[j] >= 0)
		{
			cout << B[j] << " ";
		}
	}
	return 0;
}