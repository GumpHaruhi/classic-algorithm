#include <iostream>
#include <stack>
using namespace std;

class MonotonicStack
{
private:
    stack<int> s;
public:
    int size();
    void pop();
    int top();
    int push(int element);
    int function(const int* arr,int n);
};

int MonotonicStack::size(){
    //TODO
    return s.size();
}

void MonotonicStack::pop(){
    //TODO
    if(s.size() > 0){
        s.pop();
    }
}

int MonotonicStack::top(){
    //TODO
    if(s.size() > 0) {return s.top();}
}

int MonotonicStack::push(int element){
    //TODO
    while(s.size() != 0 && element > s.top()){
        s.pop();
    }
    s.push(element);
    return 0;
}

int MonotonicStack::function(const int* arr,int n){
    //TODO
    for(int i = 0;i < n;i++){
        if(i == n-1){
            s.push(arr[i]);
            break;
        }
        for(int j = i+1;j <= n;j++){
            if(j == n){
                s.push(arr[i]);
                break;
            }
            else if(arr[j] < arr[i]){
                s.push(arr[i] - arr[j]);
                break;
            }
        }
    }

    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += s.top();
        s.pop();
    }
    return sum;
}

int main() {
    MonotonicStack* ms=new MonotonicStack;
    ms->push(8);
    ms->push(4);
    ms->push(6);
    ms->push(2);
    ms->push(3);
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->size()<<endl;
    delete ms;
}