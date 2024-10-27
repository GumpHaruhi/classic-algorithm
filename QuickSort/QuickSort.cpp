#include <iostream>
#include <vector>
using namespace std;

void exchange(vector<int>& nums, int x, int y){
    if(x==y)  return;
    int temp;
    temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

//选定一个pivot并将left到right之间的元素通过pivot划分成两部分，然后返回pivot的下标
int _partition(vector<int>& nums, int left, int right) {
    //write ur code here.
    int mid = (left + right)/2;
    if(left > right){
        if(right > mid)  return right;
        else if(mid > left)  return left;
        else  return mid;
    }
    else{
        if(left >mid)  return left;
        else if(mid > right)  return right;
        else  return mid;
    }
}

//将nums通过_partition划分成两部分，对每个部分调用_quick_sort
void _quick_sort(vector<int>& nums, int left, int right) {
    //write ur code here.
    if(left >= right){
        return;
    }
    else if(left == right-1){
        if(nums[right] < nums[left]){
            exchange(nums, left, right);
        }
        return;
    }
    int flag = _partition(nums, left, right);
    int value = nums[flag], pl=left+1, pr=right;
    if(flag != left){
        exchange(nums, left, flag);
    }
    for(int i=pl;i <= right;){
        if(i > pr){
            break;
        }
        else if(nums[i] < value){
            exchange(nums, pl, i);
            pl++;
            i++;
        }
        else if(value == nums[i]){
            i++;
        }
        else if(nums[i] > value){
            exchange(nums, i, pr);
            pr--;
        }
    }
    pl--;
    exchange(nums, left, pl);
    
    _quick_sort(nums, left, pl-1);
    _quick_sort(nums, pr, right);
}

void QuickSort(vector<int>& nums) {
    _quick_sort(nums, 0, nums.size()-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i < n;i++){
        cin >> nums[i];
    }
    QuickSort(nums);
    for(int i=0;i < n;i++){
        cout << nums[i] << ' ';
    }
    cout <<endl;
}


// 6 5 4 7 8 9 