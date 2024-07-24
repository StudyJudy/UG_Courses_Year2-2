#include<iostream>
using namespace std;
void display(bool* pre,int *num, int n, int time)//表示当前排列已经访问的次数
{
	if (time == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << num[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)//遍历1到n中尚未被使用的数字，将其添加到当前排列中，标记为已使用
		{
			if (pre[i] == 0)
			{
				pre[i] = 1;
				num[time] = i;
				display(pre, num, n, time + 1);
				pre[i] = 0;//回溯到上一层，将当前数字标记为未使用，继续遍历下一个数字
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	bool* pre = new bool[n + 1];//数组用于标记数字是否已经被使用
	int* num = new int[n];//用于存储当前排列
	for (int i = 0; i <= n; i++)
	{
		pre[i] = 0;
	}
	display(pre, num, n, 0);
	delete[] pre;
	return 0;
}