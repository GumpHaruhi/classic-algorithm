#include <iostream>
#include <fstream>
#include <cassert>
#include <malloc.h>
#include <vector>

using namespace std;

class Bitmap{
private:
    int n;
    const int shift;
    const int mask;
    vector<unsigned int> num;
public:
    Bitmap(int a):n(a), shift(5), mask(0x1F), num(1+32/n, 0){}

    void set(int i){
        num[i >> shift] |= (unsigned int)(1 << (i & mask));
    }

    int get(int i){
        return num[i >> shift] & (unsigned int)(1 << (i & mask));
    }
};

int main()
{
    Bitmap bitmap(3126000);
    unsigned int n;
    ifstream file_1(R"(D:\MyCode\C++\hw09\1.txt)");
    if(!file_1){
        cout << "fail" << endl;
        return 0;
    }
    else{
        while(!file_1.eof()){
            file_1 >> n;
            bitmap.set(n);
        }
    }
    file_1.close();
    for(int i=0;i <= 10000;i++){
        bool res = bitmap.get(i);
        cout << res << ":" << i << "  ";
    }
}
