struct Element
{
    int num;
    // 可以添加任何你需要的数据类型,但与本关测评无关
    bool operator==(const Element e) const;
};
class ListNode
{
    Element e;
    ListNode *back = nullptr;
    ListNode *next = nullptr;
    ListNode();
    ListNode(const Element &e_);
    friend class List; // 为便于测评，这里设置为友元
};