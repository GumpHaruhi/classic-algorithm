#include <iostream>
#include <vector>

using namespace std;

void exchange(vector<int>& nums, int x, int y){
    int mid = nums[x];
    nums[x] = nums[y];
    nums[y] = mid;
    return;
}

void ShellSort(vector<int>& nums) {
    //write ur code here.
    int lenth = nums.size();
    int gap = lenth/2;
    while(gap >= 1){
        for(int i=0;i < lenth;i++){
            int temp = i;
            while(temp-gap >=0 && nums[temp] < nums[temp-gap]){
                exchange(nums, temp, temp-gap);
                temp = temp-gap;
            }
        }
        gap = gap/2;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.clear();
    cin.ignore();
    vector<int> nums(n);
    for(int i=0;i < n;i++){
        cin >> nums[i];
    }
    ShellSort(nums);
    for(int i=0;i < n;i++){
        cout << nums[i] << ' ';
    }
    cout <<endl;
}