#include<iostream>
using namespace std;
int main()
{
	//E02-02: 合并两个排序的列表，并给出一些例子来测试它
	cout << "E02-02" << endl;
	int n1, n2;//n1为数组A的大小，n2为数组B的大小
	cout << "请输入数组A的大小: ";
	cin >> n1;
	cout << "请输入数组B的大小: ";
	cin >> n2;
	int* A = new int[n1];
	int* B = new int[n2];
	for (int i = 0; i < n1; i++)//输入数组A的数字（数组是从小到大有序的）
	{
		cin >> A[i];
	}
	for (int i = 0; i < n2; i++)//输入数组B数字（数组是从小到大有序的）
	{
		cin >> B[i];
	}
	int* C = new int[n1 + n2];//建立新数组C用来存储合并后的数组
	int p = 0, q = 0, r = 0;//p记录A动的下标，q记录B动的下标，r记录动的下标
	while (p < n1 && q < n2)//循环两两比较，小的存进C中
	{
		if (A[p] <= B[q])
		{
			C[r++] = A[p++];
		}
		else
		{
			C[r++] = B[q++];
		}
	}
	while (p < n1)//A没存完
	{
		C[r++] = A[p++];
	}
	while (q < n2)//B没存完
	{
		C[r++] = B[q++];
	}
	cout << "合并的结果是：" << endl;
	for (int i = 0; i < n1 + n2; i++)//输出C
	{
		cout << C[i] << " ";
	}
	cout << endl;
	cout << endl;
	return 0;
}