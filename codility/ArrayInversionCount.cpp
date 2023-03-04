// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int merge(vector<int>& arr, vector<int>& temp, int low, int mid, int high){
    int idx = low;
    int i = low;
    int j = mid + 1;
    
    int inv = 0;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[idx++] = arr[i++];
        }else{
            inv += (mid -i +1);
            temp[idx++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[idx++] = arr[i++];
    }

    while (j <= high) {
        temp[idx++] = arr[j++];
    }

    for (int k = low; k <= high; k++) {
        arr[k] = temp[k];
    }

    return inv;
}


int mergeSort(vector<int>& arr, vector<int>& temp, int low, int high){
    int inv = 0;

    if(low<high){
        int mid = (low+high)>>1;
        inv += mergeSort(arr, temp, low, mid);
        inv += mergeSort(arr, temp, mid+1, high);
        inv += merge(arr, temp, low, mid, high);
    }

    if(inv > 1000000000)
        return -1;
    return inv;
}




int solution(vector<int> &A) {
    // Implement your solution here
    int len = A.size();
    vector<int> temp(len);
    return mergeSort(A, temp, 0, len-1);
}
