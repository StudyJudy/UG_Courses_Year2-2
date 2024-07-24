#include<iostream>
using namespace std;
int Binary_search(int a[], int left, int right, int target) //折半查找
{
	if (left > right)
	{//输入错误，搜索失败
		return -1;
	}
	while (left <= right)
	{
		//中间元素下标
		int mid = (left + right) / 2;
		if (target > a[mid])//target在mid右侧
		{
			left = mid + 1;//右半侧寻找
		}
		else if (target < a[mid])//target在mid左侧
		{
			right = mid - 1;//左半侧寻找
		}
		else
		{
			return mid;//a[mid]==target，找到target的位置，返回target的位置为mid
		}
	}
	//没有找到
	return -1;
}
int main()
{
	//E02-05: 三个整数的和恰好为𝑇。
	cout << "E02-05,O(n^3)" << endl;
	int N2, T2;//n为数组大小,T为目标和
	cout << "请输入数组大小n= ";//输入数组大小
	cin >> N2;
	cout << "请输入目标和：";
	cin >> T2;
	int* array3 = new int[N2];//建立数组
	for (int i = 0; i < N2; i++)//输入数组数字（数组是有序的）
	{
		cin >> array3[i];
	}
	for (int i = 0; i < N2; i++)//0开始遍历
	{
		for (int j = i + 1; j < N2; j++)//i+1开始遍历
		{
			for (int k = j + 1; k < N2; k++)//j+1开始遍历
			{
				if (array3[i] + array3[j] + array3[k] == T2)//相加和为T2
				{
					cout << "(" << array3[i] << "," << array3[j] << "," << array3[k] << ")" << ":" << array3[i] << "+" << array3[j] << "+" << array3[k] << "=" << T2 << endl;//输出三个数字
				}
			}
		}
	}
	cout << endl;

	cout << "E02-05,O(n^2logn)" << endl;
	for (int i = 0; i < N2; i++)//0开始遍历
	{
		for (int j = i + 1; j < N2; j++)//i+1开始遍历
		{
			if (Binary_search(array3, j + 1, N2 - 1, T2 - array3[i] - array3[j]) != -1)//T-array[i]存在
			{
				cout << "(" << array3[i] << "," << array3[j] << "," << array3[Binary_search(array3, j + 1, N2 - 1, T2 - array3[i] - array3[j])] << ")" << ":" << array3[i] << "+" << array3[j] << "+" << array3[Binary_search(array3, j + 1, N2 - 1, T2 - array3[i] - array3[j])] << "=" << T2 << endl;//输出三个数字
			}
		}
	}
	cout << endl;

	cout << "E02-05, O(n^2)" << endl;
	for (int i = 0; i < N2 - 1; i++)
	{
		int start = i + 1, end = N2 - 1;//start从前向后遍历，end从后向前遍历
		while (start < end)//start<end的时候，进行遍历，当start>=end的时候，不应进行查找
		{
			if (array3[start] + array3[end] + array3[i] < T2)//三者相加值小于T,让小的数变大一点
			{
				start++;
			}
			else if (array3[start] + array3[end] + array3[i] > T2)//三者相加值大于T,让大的数变小一点
			{
				end--;
			}
			else if (array3[start] + array3[end] + array3[i] == T2)//找到一组
			{
				cout << "(" << array3[i] << "," << array3[start] << "," << array3[end] << ")" << ":" << array3[i] << "+" << array3[start] << "+" << array3[end] << "=" << T2 << endl;//输出三个数字
				start++;//继续寻找可能的下一组
			}
		}
	}
	cout << endl;
	return 0;
}