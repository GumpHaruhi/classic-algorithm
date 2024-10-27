#include <iostream>
#include <vector>
using namespace std;

class MyHeap {
public:
    MyHeap() {}
    void push(int val) {
        //write ur code here.
        _arr.push_back(val);
        size_t temp, i;
        i = this->size();
        int mid;
        while(i != 0){
            if(i%2){
                temp = i/2;
            }
            else temp = i/2-1;
            if(_arr[temp] <= _arr[i]){
                break;
            }
            else{
                mid = _arr[temp];
                _arr[temp] = _arr[i];
                _arr[i] = mid;
                i = temp;
            }
        }
    }

    void pop() {
        //write ur code here.
        int _size = this->size();
        int mid = _arr[0];
        _arr[0] = _arr[_size-1];
        _arr[_size-1] = mid;
        _arr.pop_back();
        _size--;
        size_t i = 0;
        while(i*2+1 <= _size-1){
            if(i*2+2 <= _size-1){
                int less = _arr[i*2+1] < _arr[i*2+2] ? (i*2+1): (i*2+2);
                if(_arr[i] > _arr[less]){
                    mid = _arr[i];
                    _arr[i] = _arr[less];
                    _arr[less] = mid;
                    i = less;
                }
                else break;
            }
            else if(_arr[i] > _arr[i*2+1]){
                mid = _arr[i];
                _arr[i] = _arr[i*2+1];
                _arr[i*2+1] = mid;
                i = i*2+1;
            }
            else break;
        }
    }

    int top() {
        //write ur code here.
        return _arr.front();
    }

    size_t size() {
        //write ur code here
        return _arr.size();
    }

private:
    vector<int> _arr;
};


int main()
{
    MyHeap sex = MyHeap();
    sex.push(6);
    cout << sex.top()<< endl;//6
    sex.push(3);
    cout << sex.top()<< endl;//3
    sex.push(1);
    cout << sex.top()<< endl;//1
    sex.push(7);
    cout << sex.top()<< endl;//1
    sex.push(18);
    cout << sex.top()<< endl;//1
    sex.pop();
    cout << sex.top()<< endl;//6 != 3
    sex.push(2);
    cout << sex.top()<< endl;//2
    sex.pop();
    cout << sex.top()<< endl;//6
    sex.pop();
    cout << sex.top() << endl;//7
}
