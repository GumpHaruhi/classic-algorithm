快速排序，优雅无需多言

每一次排序，先把选中的pivot与序列左端left交换, 把pivot放在端点，对(left+1) to right的元素快排
最后再把pivot交换回应该它在的位置。这样做会更加直观，优雅

直接选取中间元素作为pivot是愚蠢的，有时还很危险，但毫无疑问，这很方便

随机选择pivot的随机快排才是最好的实现