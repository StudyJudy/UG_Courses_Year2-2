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
	cout << "E02-01" << endl;
	//E02-01: 实现了二分查找，并给出了实例进行了验证。
	int n;//n为数组大小
	cout << "请输入数组大小n= ";//输入数组大小
	cin >> n;
	int* array = new int[n];//建立数组
	for (int i = 0; i < n; i++)//输入数组数字（数组是有序的）
	{
		cin >> array[i];
	}
	int x;//x是待查找的数字
	cout << "请输入待查找的数字x= ";
	cin >> x;
	if (Binary_search(array, 0, n - 1, x) == -1)//没找到x或者输入错误
	{
		cout << "未找到该数字，请检查输入！" << endl;
	}
	else
	{
		cout << x << "在数组中的下标为: " << Binary_search(array, 0, n - 1, x) << endl;
	}
	cout << endl;
	return 0;
}