#include "List.h"
using namespace std;


List::List()
{
    head.next = &head;
    head.back = &head;
}

List::List(const List &l_)
{
    head.next = &head;
    head.back = &head;
    ListNode *p = l_.head.next;
    while(p != &l_.head){
        ListNode *ln = new ListNode(p->e);
        ln->next = &head;
        ln->back = head.back;
        head.back->next = ln;
        head.back = ln;
        p = p->next;
    }
}

List::~List()
{
    ListNode *p = head.next, *q = nullptr;
    while(p != &head){
        q = p;
        p = p->next;
        delete q;
    }
    head.next = &head;
    head.back = &head;
}

void List::operator=(const List &l_)
{
    //this->~List();
    head.next = &head;
    head.back = &head;
    ListNode *p = l_.head.next;
    while(p != &l_.head){
        ListNode *ln = new ListNode(p->e);
        ln->next = &head;
        ln->back = head.back;
        head.back->next = ln;
        head.back = ln;
        p = p->next;
    }
}

bool List::push_front(const Element &e)
{
    ListNode *ln = new ListNode(e);
    ln->next = head.next;
    ln->back = &head;
    head.next->back = ln;
    head.next = ln;
    return true;
}

bool List::push_back(const Element &e)
{
    ListNode *ln = new ListNode(e);
    ln->next = &head;
    ln->back = head.back;
    head.back->next = ln;
    head.back = ln;
    return true;
}

bool List::pop_front()
{
    if(head.next == &head){
        return false;
    }
    ListNode *p = head.next;
    head.next = p->next;
    p->next->back = &head;
    delete p;
    return true;
}

bool List::pop_back()
{
    if(head.back == &head){
        return false;
    }
    ListNode *p = head.back;
    head.back = p->back;
    p->back->next = &head;
    delete p;
    return true;
}

bool List::remove(const Element &e)
{
    ListNode *p = head.next;
    int flag = 0;
    while(p != &head){
        if(p->e.num == e.num){
            erase(p);
            flag = 1;
        }
        p = p->next;
    }
    if(flag == 1)  return true;
    else   return false;
}

bool List::insert(const Element &e, ListNode *ln)
{
    ListNode *p = new ListNode(e);
    p->next = ln->next;
    ln->next->back = p;
    p->back = ln;
    ln->next = p;
    return true;
}

void List::erase(ListNode *ln)
{
    ListNode *pre = ln->back;
    ListNode *lat = ln->next;
    pre->next = lat;
    lat->back = pre;
    delete ln;
}

ListNode *List::operator[](size_t i)
{
    ListNode *p = head.next;
    size_t count = 0;
    while(p != &head){
        if(count == i){
            return p;
        }
        p = p->next;
        count++;
    }
    return nullptr;
}

void List::print()
{
    ListNode *p = head.next;
    while(p != &head){
        if(p == nullptr){
            cout << endl;
            continue;
        }
        cout << p->e.num << " ";
        p = p->next;
    }
    cout << endl;
}


int main()
{
    //这里放入样例
    List l;
    l.push_front({2});
    l.push_back({3});
    l.push_front({1});
    l.push_back({4});
    l.print();
}