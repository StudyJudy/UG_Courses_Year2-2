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
	//E02-03-1:O(n^2)实现两个数的目标和算法
	cout << "E02-03, O(n^2)" << endl;
	int N, T;//n为数组大小,T为目标和
	cout << "请输入数组大小n= ";//输入数组大小
	cin >> N;
	cout << "请输入目标和：";
	cin >> T;
	int* array2 = new int[N];//建立数组
	for (int i = 0; i < N; i++)//输入数组数字（数组是有序的）
	{
		cin >> array2[i];
	}
	for (int i = 0; i < N; i++)//0开始遍历
	{
		for (int j = i + 1; j < N; j++)//i+1开始遍历
		{
			if (array2[i] + array2[j] == T)//相加和为T
			{
				cout << "(" << array2[i] << "," << array2[j] << ")" << ":" << array2[i] << "+" << array2[j] << "=" << T << endl;//输出两个数字
			}
		}
	}
	cout << endl;

	//E02-03-2:O(nlogn)实现两个数的目标和算法
	cout << "E02-03, O(nlogn)" << endl;
	for (int i = 0; i < N; i++)
	{
		if (Binary_search(array2, i + 1, N - 1, T - array2[i]) != -1)//T-array[i]存在
		{
			cout << "(" << array2[i] << "," << array2[Binary_search(array2, i + 1, N - 1, T - array2[i])] << ")" << ":" << array2[i] << "+" << array2[Binary_search(array2, i + 1, N - 1, T - array2[i])] << "=" << T << endl;//输出两个数字
		}
	}
	cout << endl;

	//E02-03-3:O(n)实现两个数的目标和算法
	cout << "E02-03, O(n)" << endl;
	int start = 0, end = N - 1;//start从前向后遍历，end从后向前遍历
	while (start < end)//start<end的时候，进行遍历，当start>=end的时候，不应进行查找
	{
		if (array2[start] + array2[end] < T)//二者相加值小于T,让小的数变大一点
		{
			start++;
		}
		else if (array2[start] + array2[end] > T)//二者相加值大于T,让大的数变小一点
		{
			end--;
		}
		else if (array2[start] + array2[end] == T)//找到一组
		{
			cout << "(" << array2[start] << "," << array2[end] << ")" << ":" << array2[start] << "+" << array2[end] << "=" << T << endl;//输出两个数字
			start++;//继续寻找可能的下一组
		}
	}
	cout << endl;
	return 0;
}