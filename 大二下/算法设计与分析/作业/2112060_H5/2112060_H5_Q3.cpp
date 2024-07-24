#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n;
	cin >> n;//n个节点
	int m;
	cin >> m;//m条边
	int weight[50][50];
	int* edge = new int[m];
	int* start = new int[m];
	int* end = new int[m];
	int k = 0;
	for (int i = 0; i < m; i++)//无向图
	{
		cin >> start[i] >> end[i];//start->end
		cin >> edge[i];//start->end的权值
	}
	//对edge从小到大进行排序,相应的，start，end也要调整顺序
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (edge[j] < edge[j - 1])
			{
				int temp = edge[j - 1];
				edge[j - 1] = edge[j];
				edge[j] = temp;

				int temp1 = start[j - 1];
				start[j - 1] = start[j];
				start[j] = temp1;

				int temp2 = end[j - 1];
				end[j - 1] = end[j];
				end[j] = temp2;
			}
		}
	}
	set<int>node;//点集合，用来判断有没有环出现
	//krusal算法求解
	int edgenum = 0;//当前生成树中边的条数
	int sum = 0;//最小生成树的路径和
	for (int i = 0; i < m; i++)//m条边
	{
		if (node.count(start[i]) && node.count(end[i]))//count用来返回某个值的元素个数，如果两个返回的都是1，那么加入这条边后一定会出现环，所以不能加入这条边
		{
			continue;//找下一条边
		}
		node.insert(start[i]);//
		node.insert(end[i]);//把这条边的两个点加进集合
		edgenum++;//生成树中的边的数量+1
		sum += edge[i];//权值和加上这条边
	}
	cout << sum;
	return 0;
}