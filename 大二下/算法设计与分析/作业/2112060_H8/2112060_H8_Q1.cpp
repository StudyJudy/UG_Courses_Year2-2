#include<iostream>
#include<cstring>
#include<string>
#include <chrono>
using namespace std;
int LCS(char* A, char* B, int m)
{
	int ans = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		for (int j = 0; j < (1 << m); j++)
		{
			string t1 = "", t2 = "";
			for (int k = 0; k < m; k++)
			{
				if (i & (1 << k))
				{
					t1 += A[k];
				}
			}
			for (int k = 0; k < m; k++)
			{
				if (j & (1 << k))
				{
					t2 += B[k];
				}
			}
			if (t1 == t2)
			{
				ans = max(ans, (int)t1.size());
			}
		}
	}
	return ans;
}
int main()
{
	int m;
	cin >> m;
	char* A = new char[m];
	char* B = new char[m];
	cin >> A;
	cin >> B;
	// 记录开始时间
	auto start = chrono::high_resolution_clock::now();

	int ans = LCS(A, B, m);

	// 记录结束时间
	auto end = chrono::high_resolution_clock::now();

	cout << ans << endl;
	cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
	return 0;
}