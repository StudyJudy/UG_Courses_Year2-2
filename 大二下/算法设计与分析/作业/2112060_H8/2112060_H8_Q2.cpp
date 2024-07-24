#include<iostream>
#include <chrono>
using namespace std;
int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
		return b;
}
int LCS(char* A, char* B, char* ch, int m)
{
	int dp[200][200];
	int len = 0;
	for (int i = 0; i < m + 1; i++)//第一行第一列全初始化为0
	{
		dp[0][i] = 0;
	}
	for (int i = 0; i < m + 1; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i < m + 1; i++)//A
	{
		for (int j = 1; j < m + 1; j++)//B
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[m][m];
}
int main()
{
	int m;
	cin >> m;
	char* A = new char[m];
	char* B = new char[m];
	char* ch = new char[m];
	cin >> A;
	cin >> B;
	// 记录开始时间
	auto start = chrono::high_resolution_clock::now();

	int ans = LCS(A, B, ch, m);

	// 记录结束时间
	auto end = chrono::high_resolution_clock::now();
	cout <<"Length: "<< ans << endl;
	cout << ch << endl;
	cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
	return 0;
}