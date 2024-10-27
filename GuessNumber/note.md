使用二分法

需要注意的是，每次进行判断的中间值mid，不能进入到下一层二分
即下一层二分应该是 (left, mid-1) to (mid+1, right), not contain mid

对于恶意的非常大的数据，不要使用直接求mid : mid = (left + right) /2 因为left+right可能会爆
使用 mid = left + (right-left)/2