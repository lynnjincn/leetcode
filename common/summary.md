# COMMON小结

## 题型整理
### 特殊技巧型
#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
#### [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)
- Kadane算法
*核心思想都是暂时保存住当前最优以及历史最优*

#### [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/submissions/)
#### [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)
- 计算面积的技巧
- 动态规划

### [363. 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)
- 动态规划
- 计算二维数组数值加和遍历技巧

### 通用算法型
#### 动态规划（dynamic program）

1.  单字符串内特殊条件遍历
- [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)
- [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
- [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)
- [132. 分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)
- [139. 单词拆分](https://leetcode-cn.com/problems/word-break/)

2.  两个字符串对比、查询
- [10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)
- [44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)
- [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
- [87. 扰乱字符串](https://leetcode-cn.com/problems/scramble-string/)
- [97. 交错字符串](https://leetcode-cn.com/problems/interleaving-string/)
- [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

3. 地图遍历（还有可能使用广度、深度优先遍历）
- [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)
- [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)
- [174. 地下城游戏](https://leetcode-cn.com/problems/dungeon-game/) ***逆序可能是解决方案哦***

4. 逐层剥离（与分治法思想内核相同，但是又不适用前面几种典型模式）
- [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
- [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) [`解题思路`](0121/0121.md)
- [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)
- [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)
- [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)
- [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/) ***逆序可能是解决方案哦***
- [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)
- [343. 整数拆分](https://leetcode-cn.com/problems/integer-break/)
- [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)
- [357. 计算各个位数不同的数字个数](https://leetcode-cn.com/problems/count-numbers-with-unique-digits/)

5. 遍历形式的动态规划
- [279. 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)
- [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

6. 其他
- [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)

>动态规划的小思考：
>- 逆序可能解决一些正序处理有困难的问题，可以作为动态规划**自顶向下**和**自底向上**的具体实现

#### hash链表
- [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/) [*代码实现参考链接*](0030/0030.c)

#### 字典排序
- [820. 单词的压缩编码](https://leetcode-cn.com/problems/short-encoding-of-words/)

#### 快慢指针
- [876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

#### 单调栈（出现扰乱单调性的元素准备入栈时，制定对应的处理策略。所有元素处理完成之后，针对留在栈中的元素制定对应的处理策略）
- [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

## 遗留事务
