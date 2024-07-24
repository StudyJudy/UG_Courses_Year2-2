#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 平面上的一个点
struct Point 
{
    double x;
    double y;
    bool operator<(const Point& other) const 
    {
        return x < other.x;
    }
};
// 求两个点的欧几里得距离平方
double distance(const Point& p1, const Point& p2) 
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}
// 暴力计算最近点对
/*pair<double, pair<Point, Point>> bruteForce(const vector<Point>& points, int l, int r)
{
    double minDist = numeric_limits<double>::max();
    pair<Point, Point> closestPoints;
    for (int i = l; i <= r; i++) 
    {
        for (int j = i + 1; j <= r; j++) 
        {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) 
            {
                minDist = dist;
                closestPoints = { points[i], points[j] };
            }
        }
    }
    return { minDist, closestPoints };
}*/
// 在两个有序区间中查找最近点对
    pair<double, pair<Point, Point>> closestPairRec(const vector<Point>& points, int l, int r) 
    {
    if (l == r) 
    {
        // 只有一个点，距离为正无穷
        return { numeric_limits<double>::max(), {points[l], points[l]} };
    }
    else if (r - l == 1) 
    {
        // 有两个点，直接计算距离
        return { distance(points[l], points[r]), {points[l], points[r]} };
    }
    // 分别递归处理左右两个区域
    int mid = (l + r) / 2;
    auto leftClosest = closestPairRec(points, l, mid);
    auto rightClosest = closestPairRec(points, mid + 1, r);
    // 取两个区域中距离最小的一对点
    double minDist;
    pair<Point, Point> closestPoints;
    if (leftClosest.first < rightClosest.first) 
    {
        minDist = leftClosest.first;
        closestPoints = leftClosest.second;
    }
    else 
    {
        minDist = rightClosest.first;
        closestPoints = rightClosest.second;
    }
    // 在边界区域中查找距离最近的点对
    vector<Point> strip;
    for (int i = l; i <= r; i++) 
    {
        if (abs(points[i].x - points[mid].x) < minDist) 
        {
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](const Point& p1, const Point& p2) {return p1.y < p2.y; });
    for (int i = 0; i < strip.size(); i++) 
    {
        for (int j = i + 1; j < strip.size() && j <= i + 7; j++) 
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                closestPoints = { strip[i], strip[j] };
            }
        }
    }
    return { minDist, closestPoints };
    }

    // 找到最近点对
    pair<double, pair<Point, Point>> closestPair(const vector<Point>& points) 
    {
        // 先按照x坐标排序
        vector<Point> sortedPoints = points;
        sort(sortedPoints.begin(), sortedPoints.end());
        // 使用递归算法找到最近点对
        return closestPairRec(sortedPoints, 0, sortedPoints.size() - 1);
    }
    int main() 
    {
        // 输入点的个数
        int n;
        cin >> n;
        // 输入所有点的坐标
        vector<Point> points(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> points[i].x >> points[i].y;
        }
        // 找到最近点对并输出结果
        auto closest = closestPair(points);
        cout << closest.first << endl;
        /*cout << closest.second.first.x << " " << closest.second.first.y << endl;
        cout << closest.second.second.x << " " << closest.second.second.y << endl;*/
        return 0;
    }