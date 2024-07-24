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

// 递归函数，计算最优解
int knapsackHelper(vector<Item>& items, int capacity, int currentWeight, int currentValue, int currentIndex) {
    // 如果超出重量限制，直接返回价值为0
    if (currentWeight > capacity) 
    {
        return 0;
    }

    // 如果已经考虑完了所有的物品，返回当前价值
    if (currentIndex == items.size()) 
    {
        return currentValue;
    }

    // 不选择当前物品的最优解
    int bestWithoutCurrent = knapsackHelper(items, capacity, currentWeight, currentValue, currentIndex + 1);

    // 选择当前物品的最优解
    int bestWithCurrent = knapsackHelper(items, capacity, currentWeight + items[currentIndex].weight,
        currentValue + items[currentIndex].value, currentIndex + 1);

    // 返回两个子问题中的较大值
    return max(bestWithoutCurrent, bestWithCurrent);
}

// 穷举法函数
int knapsack(vector<Item>& items, int capacity)
{
    // 调用递归函数，从第一个物品开始考虑
    return knapsackHelper(items, capacity, 0, 0, 0);
}

int main() {
    int capacity, n;
    cin >> capacity >> n;
    //vector<Item> items = { {2,12}, {1,10}, {3,20}, {2,15} };
    //int capacity = 5;
    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        Item it;
        it.weight = w;
        it.value = v;
        items.push_back(it);
    }
    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    // 调用穷举法函数
    int maxvalue = knapsack(items, capacity);

    // 记录结束时间
    auto end = chrono::high_resolution_clock::now();

    // 输出结果和程序运行时间
    cout << "The maximum value is " << maxvalue << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    return 0;
}
