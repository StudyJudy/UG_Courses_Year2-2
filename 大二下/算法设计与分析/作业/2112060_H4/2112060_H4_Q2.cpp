#include<iostream>
using namespace std;
int main()
{
	int n;//课程数量
	cout << "n= ";
	cin >> n;
	int* start = new int[n];//存课程的开始时间
	int* finish = new int[n];//存课程的结束时间
	int end = 0;//记录最晚的结束时间
	for (int i = 0; i < n; i++)
	{
		cin >> start[i] >> finish[i];//输入课程开始时间和结束时间
		if (finish[i] > end)
		{
			end = finish[i];
		}
	}
	int min_room = 0;//记录最少要用几间教室
	for (int i = 0; i < end; i++)//时间线
	{
		int need_room = 0;//记录当前时间至少需要几个教室（一个教室不能同时上两门课），也就是当前时间有几门课程同时开
		for (int j = 0; j < n; j++)//课程
		{
			if (i >= start[j] && i < finish[j])//在课程时间段内，课程时间为[ ),i在这个区间内，就是需要一个教室
			{
				need_room++;//当前时间段需要教室最少数量+1
			}
		}
		if (min_room < need_room)//如果已经记录的需要的最少教室数量小于当前时间段需要的最少教室数量
		{
			min_room = need_room;//记录的需要的最少教室数量变成当前时间段需要的最少教室数量
		}
	}
	cout << min_room;
	return 0;
}