#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;//n个工作
	int* start = new int[n];//存工作的开始时间
	int* finish = new int[n];//存工作的结束时间
	int end = 0;//记录最晚的结束时间
	for (int i = 0; i < n; i++)
	{
		cin >> start[i] >> finish[i];//输入开始时间和结束时间
		if (finish[i] > end)
		{
			end = finish[i];
		}
	}
	//按结束时间排序数组
	for (int i = 0; i < n; i++)//冒泡排序
	{
		for (int j = i + 1; j < n; j++)
		{
			if (finish[j-1] > finish[j])//交换顺序
			{
				int temp1 = finish[j-1];
				finish[j-1] = finish[j];
				finish[j] = temp1;
				int temp2 = start[j-1];
				start[j-1] = start[j];
				start[j] = temp2;
			}
		}
	}
	//for (int i = 0; i < n; i++)//检验下排序结果
	//{
	//	cout << start[i] << " " << finish[i] << endl;
	//}
	bool* work = new bool[end];//建立一个数组，用于记录每个时间段是不是已有工作
	int type = 0;//记录最大的可兼容工作数目
	for (int i = 0; i < end; i++)
	{
		work[i] = false;//	全部初始化为没有工作
	}
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = start[i]; j < finish[i]; j++)//判断第i份工作的安排的时间段，是不是可以兼容这份工作，[ )
		{
			if (work[j] == true)//该段时间有部分时间有工作安排
			{
				flag = 0;//flag为0，标志不可兼容
				break;//不可兼容这份工作
			}
		}
		if (flag == 1)//标志可兼容
		{
			type++;//可兼容工作的数量+1
			for (int j = start[i]; j < finish[i]; j++)//把这份工作安排的时间段置为true
			{
				work[j] = true;
			}
		}
	}
	cout << type;
	return 0;
}