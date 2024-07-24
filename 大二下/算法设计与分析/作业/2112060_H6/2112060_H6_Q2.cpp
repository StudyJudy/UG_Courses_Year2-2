#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
class Node//节点类
{
public:
	int data;//节点值
	int weight;//权值
	int parent;//父节点数组中位置
	int lchild;//左孩子数组中位置
	int rchild;//右孩子数组中位置
	int level = 0;
};
class Huffman//Huffman tree
{
public:
	Node huffmantree[1000];//存Haffman tree
	int n;//节点个数
	void Set(int data[], int weight[], int N);//初始化,data是节点值，weight是权值，n是节点个数
	void create();//建Haffman tree
};
void Huffman::Set(int data[], int weight[], int N)
{
	n = N;//节点个数
	for (int i = 0; i < n; i++)
	{
		Node* node = new Node();//新节点
		node->data = data[i];//节点值是节点值
		node->weight = weight[i];//权重是权重
		huffmantree[i] = *node;//把建好的点加入huffmantree中
	}
}
void Huffman::create()
{
	for (int i = 0; i < (2 * n - 1); i++)//为所有节点的相关域置初值-1
	{
		huffmantree[i].parent = -1;
		huffmantree[i].lchild = -1;
		huffmantree[i].rchild = -1;
	}
	for (int i = n; i < (2 * n - 1); i++)//构造哈夫曼树，仅求非叶子结点
	{
		int lNode = -1, rNode = -1;//记录将作为左孩子和右孩子的节点在数组的位置
		int min1 = 100000, min2 = 100000;//记录两个最小的权值的点
		for (int j = 0; j < i; j++)//在huffman数组中找到data最小的两个点
		{
			if (huffmantree[j].parent == -1) //没找过的
			{
				if (huffmantree[j].weight < min1) //当前的点比min1最小的还要小
				{
					min2 = min1;//min1原来的值用min2记录，min1更新成当前节点的data值
					rNode = lNode;
					min1 = huffmantree[j].weight;
					lNode = j;
				}
				else if (huffmantree[j].weight < min2 && huffmantree[j].weight>=min1)
				{
					min2 = huffmantree[j].weight;//min2更新成当前节点的data值
					rNode = j;
				}
			}
		}
		huffmantree[lNode].parent = i;//父节点在数组的位置是i
		huffmantree[rNode].parent = i;//父节点在数组的位置是i
		huffmantree[i].weight = huffmantree[lNode].weight + huffmantree[rNode].weight;//huffmantree数组第i个位置的的weight是huffmantree[lNode].weight + huffmantree[rNode].weight
		huffmantree[i].data = huffmantree[lNode].data + huffmantree[rNode].data; //huffmantree数组第i个位置的的data是huffmantree[lNode].data + huffmantree[rNode].data
		huffmantree[i].lchild = lNode;//huffmantree[i]左孩子在数组的位置是lNode
		huffmantree[i].rchild = rNode;//huffmantree[i]右孩子在数组的位置是rNode
		huffmantree[lNode].level = max(huffmantree[lNode].level, huffmantree[rNode].level);//huffmantree[i]左孩子右孩子的高度是一样的
		huffmantree[rNode].level = max(huffmantree[lNode].level, huffmantree[rNode].level);
		huffmantree[i].level = huffmantree[lNode].level + 1;//huffmantree[i]的高度是子节点高度+1
	}
}
int main()
{
	int n;
	cin >> n;
	int data[100], weight[100];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		weight[i] = data[i];
		sum += data[i];
	}
	Huffman hf;
	hf.Set(data, weight, n);
	hf.create();
	int max_level=-1;//找到最大的level
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (hf.huffmantree[i].level > max_level)
		{
			max_level = hf.huffmantree[i].level;
		}
	}
	/*for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << hf.huffmantree[i].data << " " << hf.huffmantree[i].weight << " " << hf.huffmantree[i].lchild << " " << hf.huffmantree[i].rchild << " " << hf.huffmantree[i].parent << " " << hf.huffmantree[i].level << endl;
	}*/
	double avg_length = 0;
	for (int i = 0; i < n; i++)
	{
		avg_length += (max_level - hf.huffmantree[i].level) * data[i];//深度*权值
	}
	avg_length /= sum;
	cout << avg_length;
	return 0;
}