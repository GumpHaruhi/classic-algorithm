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
    cout << id << ' ';
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
    if(this == &sptr){
      return;
    }
    if(pointer != nullptr){
        (*ref_cnt)--;
        if(*ref_cnt == 0){
            delete pointer;
            delete ref_cnt;
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
            delete pointer;
            delete ref_cnt;
        }
    }
    pointer= nullptr;
    ref_cnt = nullptr;
}

int main()
{
    //放入测试样例
    SmartPointer sp1(new Node(123));
    sp1.~SmartPointer();
    sp1.assign(SmartPointer());//测试空指针赋值
    sp1.assign(*(new SmartPointer(new Node(456))));
}