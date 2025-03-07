#include <iostream>
#include <vector>

using namespace std;


int holdRain(vector<int>& height){
    int size = height.size();
    vector<int> leftMax(size, 0);
    vector<int> rightMax(size, 0);

    leftMax[0] = height[0];
    rightMax[size-1] = height[size-1];
    
    for(int i=1; i < size; i++){
        leftMax[i] = max(leftMax[i-1], height[i]);
        rightMax[size-i-1] = max(rightMax[size-i], height[size-i-1]);
    }

    int count = 0;
    for(int i=0; i < size; i++){
        count += min(leftMax[i], rightMax[i]) - height[i];
    }
    return count;
}

int main(){
	vector<int> height;
	int n;
	do{
		cin >> n;
		height.push_back(n);
	 } while(cin.get() != '\n');

	cout << holdRain(height) << endl;

	return 0;
}