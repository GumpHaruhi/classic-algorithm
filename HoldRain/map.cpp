#include <iostream>
#include <vector>

using namespace std;


int holdRain(vector<int>& arr){
	if(arr.size() < 3){
		return 0;
	}
	int top = arr[0], ground = arr[0];
	for(auto iter = arr.begin(); iter != arr.end(); iter++){
		if(*iter > top){
			top = *iter;
		}
		if(*iter < ground){
			ground = *iter;
		}
	}
	int lenth = arr.size();
	vector< vector<int> > map(top-ground, vector<int>(lenth, 0));

	// init map
	for(int index = 0; index < lenth; index++){
		for(int high = 0; high < arr[index]-ground; high++){
			map[high][index] = 2;
		}
	}

	// iteration & update
	for(int i = 0; i < top-ground; i++){
		int flag = -1;
		for(int j=0; j < lenth; j++){
			if(map[i][j] == 2){
				if(flag != -1 && map[i][j-1] != 2){
					// rollback;
					for(int pos = flag+1; pos < j; pos++){
						map[i][pos] = 1;
					}
				}
				flag = j;
			}
		}
	}

	// count numbers
	int count = 0;
	for(int i=0; i < top-ground; i++){
		for(int j=0; j < lenth; j++){
			if(map[i][j] == 1){
				count ++;
				// cout << "(" << i << ", " << j << ")" << endl;
			}
		}
	}
	return count;
}

int main(){
	vector<int> arr;
	int n;
	do{
		cin >> n;
		arr.push_back(n);
	 } while(cin.get() != '\n');

	cout << holdRain(arr) << endl;

	return 0;
}

