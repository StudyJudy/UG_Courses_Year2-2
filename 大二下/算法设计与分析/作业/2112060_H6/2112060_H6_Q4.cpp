#include<iostream>
using namespace std;

long long Merge(int* arr, int* temp, int left, int mid, int right) {
    // 归并排序中的合并函数，将左右两个有序数组合并成一个有序数组，并计算逆序对的数量
    long long count = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i; // 如果右侧数组中的元素arr[j]小于左侧数组中的元素arr[i]，那么右侧数组中arr[j]之后的元素也必定大于arr[i]，因为左侧数组和右侧数组内部已经有序，所以可以直接计算逆序对数量
        }
    }
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;
}

long long MergeSort(int* arr, int* temp, int left, int right) {
    // 归并排序函数，使用递归实现
    long long count = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        count += MergeSort(arr, temp, left, mid); // 递归处理左半部分
        count += MergeSort(arr, temp, mid + 1, right); // 递归处理右半部分
        count += Merge(arr, temp, left, mid + 1, right); // 将左右两个有序数组合并，并计算逆序对的数量
    }
    return count;
}

long long CountInversions(int* arr, int n) {
    int* temp = new int[n];
    return MergeSort(arr, temp, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << CountInversions(arr, n) << endl;
    delete[] arr;
    return 0;
}
