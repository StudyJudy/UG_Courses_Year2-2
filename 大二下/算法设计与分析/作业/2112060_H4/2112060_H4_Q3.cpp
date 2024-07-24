#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;//n个任务
	int* process = new int[n];//存任务处理的需要花费的时间
	int* deadline = new int[n];//存任务的deadline
	int sum_time = 0;//记录完成所有任务需要花费的最长的时间(累加)
	for (int i = 0; i < n; i++)
	{
		cin >> process[i] >> deadline[i];//输入处理时间和ddl时间
		sum_time += process[i];
	}
	//按ddl时间排序数组
	for (int i = 0; i < n; i++)//冒泡排序
	{
		for (int j = i + 1; j < n; j++)
		{
			if (deadline[j-1] > deadline[j])//交换顺序
			{
				int temp1 = deadline[j-1];
				deadline[j-1] = deadline[j];
				deadline[j] = temp1;
				int temp2 = process[j-1];
				process[j-1] = process[j];
				process[j] = temp2;
			}
		}
	}
	//for (int i = 0; i < n; i++)//检验下排序结果
	//{
	//	cout << process[i] << " " << deadline[i] << endl;
	//}
	bool* time = new bool[sum_time];//建立一个时间块的数组
	for (int i = 0; i < sum_time; i++)
	{
		time[i] = false;//初始化为false
	}
	int arranged = 0;//记录下一个任务该从此时间开始安排
	int lateness = 0;//记录总延迟时间
	for (int i = 0; i < n; i++)//第i个任务
	{
		for (int j = arranged; j < arranged + process[i]; j++)
		{
			time[j] = true;
		}
		arranged = arranged + process[i];
		if (deadline[i] < arranged)//有延迟了
		{
			lateness += arranged - deadline[i];
		}
	}
	cout << lateness;
	return 0;
}