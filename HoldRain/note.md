# 接雨水

给定一组非负整数，组成横向柱状图，计算所能承接的雨水

## map.cpp:

暴力解法：根据信息构建二维数组作为地图，在能够承接雨水的位置标记，再计算求和

## dp.cpp

动态规划解法：

- leftMax[i]: 结点 i 及其左边的最大高度
- rightMax[i]: 结点 i 及其右边的最大高度
- 结点 i 所能容纳的雨水数量： min(leftMax[i], rightMax[i]) - height[i]

```
input:
0 1 0 2 1 0 1 3 2 1 2 1
output:
6

input:
4 2 0 3 2 5
output:
9
```