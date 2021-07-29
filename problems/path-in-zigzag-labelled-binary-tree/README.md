# `（中等）` [1104.path-in-zigzag-labelled-binary-tree 二叉树寻路](https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/)

### 题目描述
<p>在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 <strong>逐行</strong> 依次按&nbsp;“之” 字形进行标记。</p>

<p>如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；</p>

<p>而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。</p>

<p><img style="height: 138px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/28/tree.png" alt=""></p>

<p>给你树上某一个节点的标号 <code>label</code>，请你返回从根节点到该标号为 <code>label</code> 节点的路径，该路径是由途经的节点标号所组成的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>label = 14
<strong>输出：</strong>[1,3,4,14]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>label = 26
<strong>输出：</strong>[1,2,6,10,26]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= label &lt;= 10^6</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
   vector<int> pathInZigZagTree(int label) {
        int row = 1, rowStart = 1;
        while (rowStart * 2 <= label) {
            row++;
            rowStart *= 2;
        }
        if (row % 2 == 0) {
            label = getReverse(label, row);
        }
        vector<int> path;
        while (row > 0) {
            if (row % 2 == 0) {
                path.push_back(getReverse(label, row));
            } else {
                path.push_back(label);
            }
            row--;
            label >>= 1;
        }
        reverse(path.begin(), path.end());
        return path;
    }
    
    int getReverse(int label, int row) {
        return (1 << row - 1) + (1 << row) - 1 - label;
    }
 };
```




