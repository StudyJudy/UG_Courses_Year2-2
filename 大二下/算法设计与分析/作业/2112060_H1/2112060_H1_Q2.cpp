#include<iostream>
using namespace std;
int main()
{
	int n, m, a, b;//n表示Ann总共要坐几次地铁；m联程票可坐几次；a表示单程票票价；b表示联程票票价
	cin >> n >> m >> a >> b;
	int sum = 10000000;//记录最小总价
	int temp = 0;//当前计算价格
	for (int i = 0; i <= n / m + 1; i++)//i是几次联程票
	{
		int j = 0;//j是几次单程票
		if (m * i >= n)
		{
			j = 0;
		}
		else
		{
			j = n - m * i;
		}
		temp = b * i + j * a;
		if (temp < sum)
		{
			sum = temp;
		}
	}
	cout << sum;
	return 0;
}
