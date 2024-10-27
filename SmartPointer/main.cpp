#include <iostream>
using namespace std;

class Node
{
  int id;

public:
  Node(int id)
  {
    this->id = id;
  }

  ~Node()
  {
    cout << id << " " <<endl;
  }

  int num(){
    return id;
  }
};

class SmartPointer
{
  Node *pointer;
  int *ref_cnt;

public:
  SmartPointer()
  {
    // 空指针
    pointer = nullptr;
    ref_cnt = nullptr;
  }
  SmartPointer(Node *p)
  {
    pointer = p;
    ref_cnt = new int(1);
  }
  int getref(){
    return *ref_cnt;
  }
  int getp(){
    return pointer->num();
  }

  // 需要完成的函数
  SmartPointer(const SmartPointer &sptr);
  void assign(const SmartPointer &sptr); // 指针赋值，将sptr赋值给本指针
  ~SmartPointer();                       // 析构函数，注意：为通过测试样例，需要保证析构函数可以被重复调用
};

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(sptr.pointer != nullptr){
        (*ref_cnt)++;
    }
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if(pointer != nullptr){
        (*ref_cnt)--;
        if(*ref_cnt == 0){
            pointer->~Node();
        }
    }
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(sptr.pointer != nullptr){
        (*ref_cnt)++;
    }
}

SmartPointer::~SmartPointer()
{
    if(pointer != nullptr && ref_cnt != nullptr){
        (*ref_cnt)--;
        if(*ref_cnt == 0){
            pointer->~Node();
        }
    }
    pointer= nullptr;
    ref_cnt = nullptr;
}


int main()
{
    SmartPointer sp1(new Node(18));
    SmartPointer sp2(sp1);
    SmartPointer sp3(new Node(88));
    sp3.assign(sp2);
    sp1.assign(sp2);
    sp2.~SmartPointer();
    //sp1.~SmartPointer();
    cout << sp3.getref() << " "<<sp3.getp()<<endl;
}