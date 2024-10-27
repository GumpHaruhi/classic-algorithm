MonotonicStack:
要求实现的一个 **单调递增栈**，如果新push的元素比栈顶元素小，就把栈内壁新元大的元素全pop出来，直到能够把新元push进去

function 函数：
这一部分要求大家需要实现function函数（它是类MonotonicStack的一个成员函数），它接收两个参数：int数组arr和它的大小n。

对数组中的任意元素arr[i]，我们定义它的价值为v[i]=arr[i]-arr[j]，其中，j是满足j>i且arr[j]<arr[i]的最小下标，
如果不存在这样的j，那么规定v[i]=arr[i]。

function返回每个元素的价值之和。