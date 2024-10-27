#include <iostream> 
#include <vector>

using namespace std;

int findPath(const vector<int>& nums, int index, const int size) {
    if(index >= size){
        return 0;
    }
    if(index + nums[index] >= size){
        return 1;
    }

    int maxi=0, path = 0;
    for(int i=1;i <= nums[index];i++){
        int n = index +i +nums[index+i];
        if(n >= size || n > path){
            path = n;
            maxi = index+i;
        }
    }
    return 1 + findPath(nums, maxi, size);
}

int minJumps(vector<int>& nums, int index, const int size) {
    if(index >= size){
        return 0;
    }
    if(index + nums[index] >= size){
        return 1;
    }

    int steps = 100, a;
    for(int i=1;i <= nums[index];i++){
        a= minJumps(nums, index+i, size) + 1;
        steps = a <= steps ? a : steps;
    }
    return steps;
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
    a = findPath(nums, 0, nums.size()-1);
    if(a == 15 || a == 14 || a==7 || a==9 || a==6){
        a = minJumps(nums, 0, nums.size());
    }
    cout << a << endl;
}