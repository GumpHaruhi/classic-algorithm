#include <iostream>
#include <vector>
using namespace std;

//将起始下标为left~mid的子数组与下标为mid~right的子数组合并（升序
void _merge(vector<int>& nums, int left, int mid, int right) {
    //write ur code here.
    int trans;
    for(int i = mid+1;i <= right;i++){
        int j = i;
        while(j-1>=left && nums[j] < nums[j-1]){
            trans = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = trans;
            j--;
        }
    }
}

//将nums拆分成两部分分别处理后再调用_merge()合并
void _merge_sort(vector<int>& nums, int left, int right) {
    //write ur code here.
    if(right - left >= 1){
        int mid;
        if((right-left)%2 == 1){
            mid = left + (right-left-1)/2;
        }
        else  mid = left + (right-left)/2;

        _merge_sort(nums, left, mid);
        _merge_sort(nums, mid+1, right);
        _merge(nums, left, mid, right);
    }
}

vector<int> MergeSort(vector<int>& nums) {
    _merge_sort(nums, 0, nums.size()-1);
    return nums;
}

int main()
{
    int n,m;
    cin >> n;
    vector<int> numb;
    for(int i=0;i < n;i++){
        cin >> m;
        numb.push_back(m);
    }

    numb = MergeSort(numb);

    for(int it = 0;it < numb.size();it++){
        cout << numb[it] << " ";
    }
    cout << endl;
    return 0;
}

// 6
// 5 1 1 2 0 0