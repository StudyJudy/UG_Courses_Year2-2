#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
// 物品的结构体，包括重量和价值
struct Item 
{
    int weight;
    int value;
};

// 动态规划法函数
int knapsack(vector<Item>& items, int n, int capacity)
{
    // 创建二维数组来存储子问题的最优解
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // 填充数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++) 
        {
            // 不选择当前物品的最优解
            int bestWithoutCurrent = dp[i - 1][j];

            // 选择当前物品的最优解
            int bestWithCurrent = 0;
            if (j >= items[i - 1].weight) 
            {
                bestWithCurrent = dp[i - 1][j - items[i - 1].weight] + items[i - 1].value;
            }

            // 取两个子问题的较大值
            dp[i][j] = max(bestWithoutCurrent, bestWithCurrent);
        }
    }
    // 返回最终问题的最优解
    return dp[n][capacity];
}

int main() 
{

    int capacity, n;
    cin >> capacity >> n;
    //vector<Item> items = { {2,12}, {1,10}, {3,20}, {2,15} };
    //int capacity = 5;
    vector<Item> items;
    int* w = new int[n];
    int* v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; i++)//根据重量排序
    {
        for (int j = i + 1; j < n; j++)
        {
            if (w[j] < w[j - 1])
            {
                int temp = w[j];
                w[j] = w[j - 1];
                w[j - 1] = temp;

                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        Item it;
        it.weight = w[i];
        it.value = v[i];
        items.push_back(it);
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << items[i].weight <<items[i].value<< endl;
    //}
    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    // 调用动态规划法函数
    int maxvalue = knapsack(items, n, capacity);

    // 记录结束时间
    auto end = chrono::high_resolution_clock::now();

    // 输出结果和程序运行时间
    cout << "The maximum value is " << maxvalue << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    return 0;
}
