#include <iostream>
using namespace std;
int main()
{
	//E02-04: 实现最短距离算法，并给出算例测试
	cout << "E02-04" << endl;
	int n3;//n3是坐标对数
	cout << "输入点的对数" << endl;
	cin >> n3;
	int* X = new int[n3];//x坐标
	int* Y = new int[n3];//y坐标
	char temp;
	int minlength = 10000000000;//储存最短距离的平方
	cout << "输入点对" << endl;
	for (int i = 0; i < n3; i++)
	{
		cin >> temp >> X[i] >> temp >> Y[i] >> temp;
	}
	//暴力求解找到最短距离
	for (int i = 0; i < n3; i++)//点（X[i],Y[i]）
	{
		for (int j = i + 1; j < n3; j++)//点（X[j],Y[j]）,
		{
			if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) < minlength)//比当前最短距离小
			{
				minlength = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
			}
		}
	}
	cout << "最短距离的平方为：" << minlength << endl;
	//遍历找到最小距离的两个点
	for (int i = 0; i < n3; i++)//点（X[i],Y[i]）
	{
		for (int j = i + 1; j < n3; j++)//点（X[j],Y[j]）,j不能等于i
		{
			if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) == minlength)//比当前最短距离小
			{
				cout << "(" << X[i] << "," << Y[i] << ")" << "," << "(" << X[j] << "," << Y[j] << ")" << endl;
			}
		}
	}
	cout << endl;

	return 0;
}