# leetcode-cn 力扣

## Project Instruction 项目介绍

* 本解决方案是 [leetcode-cn](https://leetcode-cn.com/) 的 `C++` 做题助手
* 可以方便迅速的将其中的题目和测试用例转移到本地 `Visual Studio` 工程中编码和调试
  * 绝大部分题目，仅需拷贝入口函数，通过工具生成代码，即可本地运行
  * 包含常用的数据结构，以及相应的序列化反序列化功能
  * 使用相同的用例格式，直接复制用例字符串，即可本地批量运行
  * 可进行简单的判题和显示运行时间
* 在完成题目之后，可以较为方便的收集题目信息，记录答题思路，生成答题笔记
  * 生成题目目录，可按照题目编号查询
  * 记录比赛情况
  * 记录发布的题解

[查看详细](./Project_Instruction.md)

## Quick Start 快速开始

【简洁版】

这是一个可以快速将题目转移到`Windows`平台的`Visual Studio`调试的工具。

1. 填入题目链接（仅支持从题库进入的链接，不支持需要网页登录才能查看的题目）
   * 或者手动拷题目页面中的默认代码模板
2. 如需要判题或多用例测试，补全用例的答案和后续用例
3. 点击生成 cpp 文件，打开工程即可调试
   * 完美支持大多数题目
   * 支持多次调用的**序列操作模式**的题目（如[146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)，但有一些早期的题目需要自己构建正确的答案字符串）
   * 一些特殊数据结构，如 [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) ，需要定制启动，[查看详细](./Project_Instruction.md)

```
【下载地址】
链接：https://pan.baidu.com/s/1h91m1HLbM_WIdN4sOL3sEA 
提取码：qazb
```

[查看详细](./quickstart/README.md)

## Selected Solutions 精选题解

| #    | 名称    | 题解         |
| ---- | ------- | ----------- |
| 21 | [merge-two-sorted-lists](./problems/merge-two-sorted-lists) | [【合并两个有序链表】简单迭代，详细图解](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/merge-two-sorted-lists-by-ikaruga/) |
| 37 | [sudoku-solver](./problems/sudoku-solver) | [【解数独】回溯 + 状态压缩（使用 bitset）](https://leetcode-cn.com/problems/sudoku-solver/solution/37-by-ikaruga/) |
| 42 | [trapping-rain-water](./problems/trapping-rain-water) | [【接雨水】单调递减栈，简洁代码，动图模拟](https://leetcode-cn.com/problems/trapping-rain-water/solution/trapping-rain-water-by-ikaruga/) |
| 45 | [jump-game-ii](./problems/jump-game-ii) | [【跳跃游戏 II】别想那么多，就挨着跳吧 II](https://leetcode-cn.com/problems/jump-game-ii/solution/45-by-ikaruga/) |
| 55 | [jump-game](./problems/jump-game) | [【跳跃游戏】别想那么多，就挨着跳吧](https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/) |
| 68 | [text-justification](./problems/text-justification) | [【文本左右对齐】平均分布额外空格](https://leetcode-cn.com/problems/text-justification/solution/text-justification-by-ikaruga/) |
| 72 | [edit-distance](./problems/edit-distance) | [【编辑距离】入门动态规划，你定义的 dp 里到底存了啥](https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/) |
| 84 | [largest-rectangle-in-histogram](./problems/largest-rectangle-in-histogram) | [【柱状图中最大的矩形】单调栈入门，使用单调栈快速寻找边界](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/84-by-ikaruga/) |
| 88 | [merge-sorted-array](./problems/merge-sorted-array) | [【合并两个有序数组】从后面开始确定](https://leetcode-cn.com/problems/merge-sorted-array/solution/88-by-ikaruga/) |
| 124 | [binary-tree-maximum-path-sum](./problems/binary-tree-maximum-path-sum) | [【二叉树中的最大路径和】递归，条理清晰](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/) |
| 198 | [house-robber](./problems/house-robber) | [【打家劫舍】 代码简洁易懂](https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-ikaruga/) |
| 322 | [coin-change](./problems/coin-change) | [【零钱兑换】贪心 + dfs = 8ms](https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/) |
| 498 | [diagonal-traverse](./problems/diagonal-traverse) | [【对角线遍历】 分析题目-找准规律-代码清晰易读-不要让自己迷失在随意的ifelse中](https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/) |
| 696 | [count-binary-substrings](./problems/count-binary-substrings) | [【计数二进制子串】计数](https://leetcode-cn.com/problems/count-binary-substrings/solution/count-binary-substrings-by-ikaruga/) |
| 887 | [super-egg-drop](./problems/super-egg-drop) | [【鸡蛋掉落】5 行代码，从求扔几次变为求多少层楼 =附面试经历=](https://leetcode-cn.com/problems/super-egg-drop/solution/887-by-ikaruga/) |
| 1248 | [count-number-of-nice-subarrays](./problems/count-number-of-nice-subarrays) | [【统计「优美子数组」】滑动窗口一次遍历](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/1248-by-ikaruga/) |
| 1255 | [maximum-score-words-formed-by-letters](./problems/maximum-score-words-formed-by-letters) | [【得分最高的单词集合】位压缩](https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/solution/5258-by-ikaruga/) |
| 1263 | [minimum-moves-to-move-a-box-to-their-target-location](./problems/minimum-moves-to-move-a-box-to-their-target-location) | [【推箱子】BFS + 优先队列 的 详细讲解](https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/solution/1263-by-ikaruga/) |
| 1307 | [verbal-arithmetic-puzzle](./problems/verbal-arithmetic-puzzle) | [【口算难题】回溯并利用多个方程剪枝 52ms](https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/solution/5298-by-ikaruga/) |
| 1326 | [minimum-number-of-taps-to-open-to-water-a-garden](./problems/minimum-number-of-taps-to-open-to-water-a-garden) | [【灌溉花园的最少水龙头数目】贪心](https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/solution/5318-by-ikaruga/) |
| 1418 | [display-table-of-food-orders-in-a-restaurant](./problems/display-table-of-food-orders-in-a-restaurant) | [【点菜展示表】合理保存](https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/solution/display-table-of-food-orders-in-a-restaurant-by-ik/) |
| 1438 | [longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit](./problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit) | [【绝对差不超过限制的最长连续子数组】滑动窗口 + map / multiset](./problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/README.md) | [【绝对差不超过限制的最长连续子数组】滑动窗口 + map / multiset](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solution/longest-continuous-subarray-by-ikaruga/) |
| 1488 | [avoid-flood-in-the-city](./problems/avoid-flood-in-the-city) | [【避免洪水泛滥】贪心 + 二分](https://leetcode-cn.com/problems/avoid-flood-in-the-city/solution/avoid-flood-in-the-city-by-ikaruga/) |
| 1530 | [number-of-good-leaf-nodes-pairs](./problems/number-of-good-leaf-nodes-pairs) | [【好叶子节点对的数量】后序遍历](https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs/solution/good-leaf-nodes-pairs-by-ikaruga/) |
| 1616 | [split-two-strings-to-make-palindrome](./problems/split-two-strings-to-make-palindrome) | [【分割两个字符串得到回文串】中心扩展](https://leetcode-cn.com/problems/split-two-strings-to-make-palindrome/solution/split-two-strings-to-make-palindrome-by-ikaruga/) |

[查看全部](./Solutions.md)

## Problemset / All 题库
完成进度 （1157 / 1566）
[查看全部](./problemset/all/README.md)

## Season 赛季
[查看全部](./Season.md)

## Contest 竞赛
[查看全部](./Contest.md)

## Update 更新日志
[查看全部](./Update.md)
