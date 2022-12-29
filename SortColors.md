## 라이브러리를 사용하지 않고 정렬하기

라이브러리를 사용하지 않고 정렬해야 한다. 옛날에 QuickSort 했던게 떠올라서 그걸로 구현해봄.

```c++
class Solution {
public:

    int partition(vector<int>& nums, int low, int high){
        if(nums.empty()||low<0)
            return -1;
        int i = low - 1;
        int pivot = nums[high];

        for(int j=low;j<high;j++){
            if(nums[j]<pivot){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[high]);
        return i;
    }

    void quickSort(vector<int>&nums, int low, int high){
        if(low<high){
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot-1);
            quickSort(nums, pivot+1, high);
        }
    }

    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        quickSort(nums, low, high-1);
    }
};
```
