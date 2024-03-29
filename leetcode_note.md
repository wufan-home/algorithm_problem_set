# Leetcode Notes

1830: 排序，从左往右算，如果加入一个不同于左侧的值，就从新计算增加量（所有直到左端的值全部增加，增加的值是新值 - 左侧值，因为我们默认已经增加完毕。记录之前消耗掉的k）如果超过k，就移动左侧，否则更新ans，并继续移动。如果增加的不是新值，就更新ans 贪心+双指针。

1792: 贪心的util function：通过率增加最大的班。要点：贪心法设计util function时要直接。

1786: dijsktra + 记录in-degree + 反向dfs + dp求路径数目 （重点题）Lazy deletion

1775: 贪心：难点在于两个数组都可以改变。排序！！！！序列1从小到大排序，序列2从大到小排序。需要定出条件判定哪个数组要改变。因为是贪心法，所以是，那个数组变化（v->6 或者 v->1）改变更大，就选择谁变化。注意，如果最后一个变化时差小于改变值，算法结束。(难题)

1770 （难题） dp 两端取值型dp （重写）- can I win, predict winner, stone game

1760 （重点）bs + 拆分某个值，重新组合。（重写）- koto banana, k closest elements, k minimum subtractions, median of two sorted array.

1727 (难题，做) - 85 (重做)

1696 Jump game VI (系列) (难题) dp, 单调栈 不能贪心  dp 很直观 O(n * k). 单调栈（如果是递增子序列，就继续push）

1690 Stone game VII (系列)  做

1674 (难题 做) prefix sum + sweep line - 731

1642 (重点) 贪心 - 巧妙。假设所有先进入的使用梯子。二分 - 

1631 (重点) (难题) dij - 

1621 （重点）(做)

数学方法： 加入k 虚拟点。当某个区间share端点了，就把其中一个换成虚拟点。所以最后的选法是 (n + k - 1, 2k). 

5种dp

1616 (贪心) 很trivial的一道题。要求是在同一个index切割，所以先找最大的prefix和suffix match，再判断剩下的是不是paling。

1508 (难题) 有两个方法：

1 - 用min heap按照和大小来构造subarray。用subarray和key，用起止index做data。每次更新结束的index以及sum，这样更大的key就会沉下去。(注：这个方法要求所有元素必须为非负，否则更新后的元素可能“沉”不下去。)

2 - (非常难) 用binary search + sliding window 计算在某个值以前和的个数。注意去重

1475 （重点）单调栈。单调栈只有两种选择：或者递增，或者是递减。顶部元素是离当前元素最近的那个元素。

1024 (重点) **此题非常典型的计算最小一维覆盖的例子**.

1 - 贪心。排序，取有overlap并最后结束的clips。

2 - dp
排序 + dp：对每一个覆盖区间内的点，最小覆盖数 = min（当前覆盖值，此区间起点覆盖值 + 1）。(**不要计算区间起始点的覆盖数，这个数不需要更新???**)
dp：对时间点递归：每个时间点的最小覆盖数 = min（子结构有效覆盖数 + 1）。

662 二叉树

383 3 sum: hash table （把两个元素组合成一个key，e1 * bound + e2）

300  LIC（重点，两种方法 - 重点时第二种）





