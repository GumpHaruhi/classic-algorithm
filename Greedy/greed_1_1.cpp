#include <iostream> 
#include <vector>

using namespace std;

int findPath(const vector<int>& nums, const int flag) {
    if(flag == 0){
        return 0;
    }

    int index = flag-1;
    for(int i=flag-1;i >= 0;--i){
        if(nums[i] >= flag-i){
            index = i;
        }
    }
    return findPath(nums, index) + 1;
}

int main()
{
    int a;
    vector<int> nums;
    while(1){
        cin >> a;
        if(a == -1){break;}
        nums.push_back(a);
    }

    a = findPath(nums, nums.size()-1);
    cout << a << endl;
}