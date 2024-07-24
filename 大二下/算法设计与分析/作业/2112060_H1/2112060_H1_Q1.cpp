#include<iostream>
using namespace std;
class Man
{
public:
	char name;//记录男生名字
	char rank[1000];//记录女生顺序
	bool visited[1000] = { false };//记录已经proposed但被rejected的女生
	bool propose;//记录是不是已有匹配
	char matched;//记录目前匹配的对象
};
class Woman 
{
public:
	char name;//记录女生名字
	char rank[1000];//记录男生顺序
	bool accept;//记录是不是已有匹配
	char matched;//记录目前匹配的对象
};
int main()
{
	int n;
	char temp1, temp2;
	cout << "n= ";
	cin >> n;
	Man* man = new Man[n];//男生
	Woman* woman = new Woman[n];//女生
	for (int i1 = 0; i1 < n; i1++)//男生信息
	{
		cin >> man[i1].name;//当前男生的名字
		man[i1].propose = false;//初始化未匹配
		cin >> temp1;//符号:
		for (int j = 0; j < n; j++)
		{
			cin >> man[i1].rank[j];//输入当前男生心仪的女生匹配顺序
			if (j != n - 1)//不是最后一名
			{
				cin >> temp2;//符号>
			}
		}
	}
	for (int i1 = 0; i1 < n; i1++)//女生信息
	{
		cin >> woman[i1].name;//当前女生的名字
		woman[i1].accept = false;//初始化未匹配
		cin >> temp1;//符号:
		for (int j = 0; j < n; j++)
		{
			cin >> woman[i1].rank[j];//输入当前女生心仪的男生匹配顺序
			if (j != n - 1)//不是最后一名
			{
				cin >> temp2;//符号>
			}
		}
	}
	for (int i = 0; i < n; i++)//男生选择权
	{
		int m, p;
		for ( m = 0; m < n; m++)//找到当前男生没找过的优先级最高的女生
		{
			if (man[i].visited[m] == false)
			{
				break;//找到了退出循环，该女生的名字是man[i].rank[m]
			}
		}
		for ( p = 0; p < n; p++)//找到该女生
		{
			if (woman[p].name == man[i].rank[m])
			{
				break;//找到了该女生，且女生信息存在woman[p]位置
			}
		}
		if (man[i].propose == false && woman[p].accept == false)//该男生没有成功的propose且该女生目前也没有accept的匹配
		{
			man[i].propose = true;//男生已匹配
			man[i].matched = woman[p].name;//男生匹配的对象的名字是woman[p].name
			woman[p].accept = true;//当前女生已匹配
			woman[p].matched = man[i].name;//当前女生匹配的对象的名字是man[i].name
		}
		else if (woman[p].accept == true)//女生已经有匹配的对象了，发生冲突，女生有拒绝权
		{
			int m1, m2, m3;//分别找到并记录这两个男生的优先级
			for ( m1 = 0; m1 < n; m1++)//m1记录当前新竞争对象的rank的位置
			{
				if (woman[p].rank[m1] == man[i].name)
				{
					break;//找到了当前新竞争者的位置是m1
				}
			}
			for ( m2 = 0; m2 < n; m2++)//m2记录当前已匹配对象的rank的位置
			{
				if (woman[p].rank[m2] == woman[p].matched)
				{
					break;//找到了当前已匹配对象的位置是m2
				}
			}
			if (m1 < m2)//女生woman[p]这里,m1<m2,新竞争者man[i]的优先级更高，则拒绝原有匹配
			{
				char temp3 = woman[p].matched;//temp3记录原匹配对象的名字
				man[i].propose = true;//man[i]已匹配
				man[i].matched = woman[p].name;//man[i]匹配对象的名字是woman[p].name
				woman[p].accept = true;//女生已匹配
				woman[p].matched = man[i].name;//woman[p]匹配的对象的名字更换成man[i].name
				for (int m3 = 0; m3 < n; m3++)//找到原匹配对象现被拒绝对象的信息
				{
					if (man[m3].name == temp3)//找到了，第m3个位置
					{
						man[m3].propose = false;//变成未匹配状态
						man[m3].matched = false;//没有匹配对象
						for (int m4 = 0; m4 < n; m4++)//找到原匹配女生的优先级位置
						{
							if (man[m3].rank[m4] == woman[p].name)
							{
								man[m3].visited[m4] = 1;//原女生的位置变成已访问过
								i = m3 - 1;//下一个需要匹配的男生变成man[m3]
							}
						}
					}
				}
			}
			else if (m1 > m2)//女生woman[p]这里,m1>m2,已匹配对象的优先级更高，则拒绝新竞争者
			{
				man[i].visited[m] = 1;//当前女生的位置已访问过
				i = i - 1;//下一个需要匹配的男生还是man[i]
			}
		}
	}
	//输出匹配后的结果
	for (int a = 0; a < n; a++)
	{
		cout << "(" << man[a].name << "," << man[a].matched << ")" << endl;
	}
	return 0;
}