# 堆排

堆是美妙的数据结构，可以将数据按照大小排序且空间紧凑(树有可能是不平衡的，堆不会)，时间复杂度保持在 log(n)

这里通过数组实现一个小顶堆，小的元素在上面。链表也可以实现堆，但数组的空间是最紧凑的

因为默认一个堆节点有两个子节点，因此堆的查找在一维数组中有一下性质：

- 堆顶是数组的第一个元素
- 插入元素时，新的元素直接插入到数组尾部，之后按照大小从堆底向堆顶移动
- 只能删除堆顶元素。将堆顶元素 (arr[0]) 与堆底最后一个元素 (arr[_size-1]) 交换，把堆低排出，堆顶按照大小向下移动
- 一个堆节点向下移动时，面对两个都比自己小的子节点(如果有两个子节点)，优先与更小的那一个交换位置
- 如果一个节点在数组中的下标是 i，它的左子节点是 [i*2+1], 右子节点是 [i*2+2], 如果存在的话
- 如果一个节点的下标是 i, 它的父节点是 (i%2) ? [i/2]: [i/2-1]

空间的紧凑与时间的保证，代价是添加元素与删除元素的麻烦