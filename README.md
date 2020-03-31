# leetcode-cn

## Project Instruction

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

## Quick Start

【简洁版】

这是一个可以快速将题目转移到`Windows`平台的`Visual Studio`调试的工具。

1. 填入题目链接（仅支持从题库进入的链接，不支持需要网页登录才能查看的题目）
   * 或者手动拷题目页面中的默认代码模板
2. 如需要判题或多用例测试，补全用例的答案和后续用例
3. 点击生成 cpp 文件，打开工程即可调试
   * 完美支持大多数题目
   * 支持**序列操作模式**的题目，但有一些题目需要自己构建正确的答案字符串
   * 一些特殊数据结构，如 [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) ，需要定制启动，[查看详细](./Project_Instruction.md)

```
【下载地址】
链接：https://pan.baidu.com/s/1h91m1HLbM_WIdN4sOL3sEA 
提取码：qazb
```

[查看详细](./quickstart/README.md)

## Selected Solutions
|     | #   | 名称                 | 题目                  | 答题          | 题解 | 难度 |
| --- | --- | -------------------- | --------------------- | ------------- | ---- | ---- |
| ☆☆☆ | 55 | [jump-game](./problems/jump-game) | [跳跃游戏](./problems/jump-game/README.md) | [cpp](./problems/jump-game/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/) | 中等 |
| ☆☆☆ | 45 | [jump-game-ii](./problems/jump-game-ii) | [跳跃游戏 II](./problems/jump-game-ii/README.md) | [cpp](./problems/jump-game-ii/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/jump-game-ii/solution/45-by-ikaruga/) | 困难 |
| ☆☆☆ | 124 | [binary-tree-maximum-path-sum](./problems/binary-tree-maximum-path-sum) | [二叉树中的最大路径和](./problems/binary-tree-maximum-path-sum/README.md) | [cpp](./problems/binary-tree-maximum-path-sum/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/) | 困难 |
| ☆☆☆ | 198 | [house-robber](./problems/house-robber) | [打家劫舍](./problems/house-robber/README.md) | [cpp](./problems/house-robber/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-ikaruga/) | 简单 |
| ☆☆☆ | 322 | [coin-change](./problems/coin-change) | [零钱兑换](./problems/coin-change/README.md) | [cpp](./problems/coin-change/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/) | 中等 | 
| ☆☆☆ | 498 | [diagonal-traverse](./problems/diagonal-traverse) | [对角线遍历](./problems/diagonal-traverse/README.md) | [cpp](./problems/diagonal-traverse/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/) | 中等 |
| ☆☆ | 887 | [super-egg-drop](./problems/super-egg-drop) | [鸡蛋掉落](./problems/super-egg-drop/README.md) | [cpp](./problems/super-egg-drop/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/super-egg-drop/solution/887-by-ikaruga/) | 困难 |
| ☆☆☆ | 1255 | [maximum-score-words-formed-by-letters](./problems/maximum-score-words-formed-by-letters) | [得分最高的单词集合](./problems/maximum-score-words-formed-by-letters/README.md) | [cpp](./problems/maximum-score-words-formed-by-letters/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/solution/5258-by-ikaruga/)  | 困难 |
| ☆☆☆ | 1263 | [minimum-moves-to-move-a-box-to-their-target-location](./problems/minimum-moves-to-move-a-box-to-their-target-location) | [推箱子](./problems/minimum-moves-to-move-a-box-to-their-target-location/README.md) | [cpp](./problems/minimum-moves-to-move-a-box-to-their-target-location/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/solution/1263-by-ikaruga/) | 困难 |
| ☆☆☆ | 1307 | [verbal-arithmetic-puzzle](./problems/verbal-arithmetic-puzzle) | [口算难题](./problems/verbal-arithmetic-puzzle/README.md) | [cpp](./problems/verbal-arithmetic-puzzle/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/solution/5298-by-ikaruga/) | 困难 |
| ☆☆☆ | 1326 | [minimum-number-of-taps-to-open-to-water-a-garden](./problems/minimum-number-of-taps-to-open-to-water-a-garden) | [灌溉花园的最少水龙头数目](./problems/minimum-number-of-taps-to-open-to-water-a-garden/README.md) | [cpp](./problems/minimum-number-of-taps-to-open-to-water-a-garden/SOLUTION.cpp) | [查看](https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/solution/5318-by-ikaruga/)  | 困难 |

[查看全部](./Solutions.md)

## Problemset / All
完成进度 （523 / 1566）
[查看全部](./problemset/all/README.md)

## Season
| 日期      | 名称                                                        | 完成  | 排名       |
| --------- | ---------------------------------------------------------- | ----- | ---------- |
| 2019/9/24 | [2019 力扣杯全国秋季编程大赛](./season/2019-fall/README.md)  | 3 / 5 | 220 / 1541 |
| 2020/1/18 | [可能是己亥年最有趣的比赛](./contest/sf-2020/README.md)      | 2 / 8 | 94 / 1166  |

## Contest
[查看全部](./Contest.md)

## Update
[查看全部](./Update.md)
