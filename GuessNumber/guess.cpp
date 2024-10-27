#include<iostream>

using namespace std;
int targe = 2147483647;

int check(int num){
    if(num>targe){
        return 1;
    }
    else if(num < targe){
        return -1;
    }
    else  return 0;
}

int guessNumber(){
    int left = INT_MIN, right = INT_MAX;
    int mid = -1;
    while(check(mid) != 0){
        if(check(mid)==1){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
        mid = left + (right-left)/2;
    }
    return mid;
}

int main()
{
    cout << guessNumber() << endl;
    return 0;
}