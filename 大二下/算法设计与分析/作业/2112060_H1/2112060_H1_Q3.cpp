#include<iostream>
using namespace std;
int main()
{
	int n;//n是账户余额
	int n2;//n2是最大状态后的账户余额
	cin >> n;
	if (n >= 0)//非负数
	{
		cout << n;
	}
	else//负数，可减去一位数字
	{
		int n1 = 0 - n;//变成绝对值正数处理
		int m1 = n1 / 10;//删除最后一个数字后的绝对值

		int p1 = n1 % 10;//p1取最后一位
		int m2 = m1 / 10 * 10 + p1;//删除倒数第二个数字后的绝对值

		if (m1 <= m2)//如果m1<=m2，则-m1>=-m2
		{
			n2 = 0 - m1;
		}
		else//如果m1>m2，则-m1<-m2
		{
			n2 = 0 - m2;
		}
		cout << n2;
	}
	return 0;
}