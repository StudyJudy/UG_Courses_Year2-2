#include <iostream>
#include <vector>
using namespace std;
// 将两个有序序列合并为一个有序序列
void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1); // 临时数组用于存放合并后的有序序列
    int i = left, j = mid + 1, k = 0; // i、j为左右两个有序序列的起始下标，k为临时数组的下标
    while (i <= mid && j <= right) { // 将左右两个有序序列中的元素逐个比较，将较小的元素放入临时数组中
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        }
        else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) { // 将剩余的左侧有序序列中的元素全部放入临时数组中
        temp[k++] = nums[i++];
    }
    while (j <= right) { // 将剩余的右侧有序序列中的元素全部放入临时数组中
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < k; p++) { // 将合并后的有序序列复制回原数组中
        nums[left + p] = temp[p];
    }
}

// 归并排序主函数
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return; // 递归终止条件：序列中只剩一个元素
    int mid = (left + right) / 2; // 将序列分为左右两个子序列
    mergeSort(nums, left, mid); // 对左子序列进行归并排序
    mergeSort(nums, mid + 1, right); // 对右子序列进行归并排序
    merge(nums, left, mid, right); // 将左右两个有序子序列合并为一个有序序列
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    mergeSort(nums, 0, n - 1); // 对整个序列进行归并排序
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
