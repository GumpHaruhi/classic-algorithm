#include <iostream>
#include <vector>

using namespace std;

int lenth;

int findEdge(const vector<int>& lines, vector<bool>& path, int currlen, int count){
    if(count == 3){
        return 1;
    }
    for(size_t i=0;i < lines.size();i++){
        if(!path[i]){
            path[i] = true;
            if(currlen + lines[i] < lenth){
                if(findEdge(lines, path, currlen+lines[i], count+1) == 1){
                    return 1;
                }
            }
            else if(currlen + lines[i] == lenth){
                if(findEdge(lines, path, 0, count+1) == 1){
                    return 1;
                }
            }
            path[i] = false;
        }
    }
    return 0;
}

int main()
{
    vector<int> lines;
    int a, sum = 0;
    while(1){
        cin >> a;
        lines.push_back(a);
        sum += a;
        if(cin.get() == '\n'){
            break;
        }
    }

    if(lines.size() < 4){
        cout << 0 << endl;
        return 0;
    }
    else if(sum%4 != 0){
        cout << 0 << endl;
        return 0;
    }
    lenth = sum>>2;
    for(size_t i=0;i < lines.size();i++){
        if(lines[i] > lenth){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<bool> path(lines.size(), false);
    cout << findEdge(lines, path, 0, 0) << endl;
}
