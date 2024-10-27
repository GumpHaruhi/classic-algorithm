#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const unsigned int buck_number = 30000;

void exchange(vector<int>&num, int x, int y){
    if(x==y)  return;
    int temp;
    temp = num[x];
    num[x] = num[y];
    num[y] = temp;
}

void _quick_sort(vector<int>&num, int left, int right) {
    if(left >= right){
        return;
    }
    else if(left == right-1){
        if(num[right] < num[left]){
            exchange(num, left, right);
        }
        return;
    }
    int flag = (left+right)/2;
    int value = num[flag], pl=left+1, pr=right;
    if(flag != left){
        exchange(num, left, flag);
    }
    for(int i=pl;i <= right;){
        if(i > pr){
            break;
        }
        else if(num[i] < value){
            exchange(num, pl, i);
            pl++;
            i++;
        }
        else if(value == num[i]){
            i++;
        }
        else if(num[i] > value){
            exchange(num, i, pr);
            pr--;
        }
    }
    pl--;
    exchange(num, left, pl);

    _quick_sort(num, left, pl-1);
    _quick_sort(num, pr, right);
}

class Buck{
private:
    vector<int> num;

    friend void exchange(vector<int>&num, int x, int y);

    friend void _quick_sort(vector<int>&num, int left, int right);
public:
    void set(int value){
        for(int i=0;i < num.size();i++){
            if(value == num[i]){
                return;
            }
        }
        num.push_back(value);
    }

    int size(){
        return (int)num.size();
    }

    void sort(){
        _quick_sort(num, 0, num.size()-1);
    }

    int get(int i){
        return num[i];
    }
};


int main()
{
    Buck buck[buck_number];
    const int capacity = 200;
    for(int i=1;i <= 2;i++){
        string filename = to_string(i) + ".txt";
        ifstream infile(filename);
        if(!infile.is_open()){
            cout << "fail open "<< i<<endl;
        }
        else{
            int n, m;
            while(!infile.eof()){
                infile >> n;
                if(n <= 5000000) {
                    m = (n - n % capacity) / capacity;
                    buck[(int) m].set(n);
                }
            }
            infile.close();
        }
    }

    int count = 0;
    for(int i=0;i < buck_number;i++){
        if(count < 100000 && count + buck[i].size() >= 100000){
            buck[i].sort();
            cout << buck[i].get(100000-count-1) << endl;
        }
        if(count < 200000 && count + buck[i].size() >= 200000){
            buck[i].sort();
            cout << buck[i].get(200000-count-1) << endl;
        }
        if(count < 300000 && count + buck[i].size() >= 300000){
            buck[i].sort();
            cout << buck[i].get(300000-count-1) << endl;
        }
        if(count < 400000 && count + buck[i].size() >= 400000){
            buck[i].sort();
            cout << buck[i].get(400000-count-1) << endl;
        }
        if(count < 500000 && count + buck[i].size() >= 500000){
            buck[i].sort();
            cout << buck[i].get(500000-count-1) << endl;
        }
        if(count < 600000 && count + buck[i].size() >= 600000){
            buck[i].sort();
            cout << buck[i].get(600000-count-1) << endl;
        }
        if(count < 700000 && count + buck[i].size() >= 700000){
            buck[i].sort();
            cout << buck[i].get(700000-count-1) << endl;
        }
        if(count < 800000 && count + buck[i].size() >= 800000){
            buck[i].sort();
            cout << buck[i].get(800000-count-1) << endl;
        }
        if(count < 900000 && count + buck[i].size() >= 900000){
            buck[i].sort();
            cout << buck[i].get(900000-count-1) << endl;
        }
        if(count < 1000000 && count + buck[i].size() >= 1000000){
            buck[i].sort();
            cout << buck[i].get(1000000-count-1) << endl;
            break;
        }

        count += buck[i].size();
    }
    return 0;
}
