# `（中等）` [427.construct-quad-tree 建立四叉树](https://leetcode.cn/problems/construct-quad-tree/)

### 题目描述
<p>给你一个 <code>n * n</code> 矩阵 <code>grid</code> ，矩阵由若干 <code>0</code> 和 <code>1</code> 组成。请你用四叉树表示该矩阵 <code>grid</code> 。</p>

<p>你需要返回能表示矩阵的 四叉树 的根结点。</p>

<p>注意，当 <code>isLeaf</code> 为 <strong>False </strong>时，你可以把 <strong>True</strong> 或者 <strong>False</strong> 赋值给节点，两种值都会被判题机制 <strong>接受</strong> 。</p>

<p>四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：</p>

<ul>
	<li><code>val</code>：储存叶子结点所代表的区域的值。1 对应 <strong>True</strong>，0 对应 <strong>False</strong>；</li>
	<li><code>isLeaf</code>: 当这个节点是一个叶子结点时为 <strong>True</strong>，如果它有 4 个子节点则为 <strong>False</strong> 。</li>
</ul>

<pre>class Node {
    public boolean val;
&nbsp; &nbsp; public boolean isLeaf;
&nbsp; &nbsp; public Node topLeft;
&nbsp; &nbsp; public Node topRight;
&nbsp; &nbsp; public Node bottomLeft;
&nbsp; &nbsp; public Node bottomRight;
}</pre>

<p>我们可以按以下步骤为二维区域构建四叉树：</p>

<ol>
	<li>如果当前网格的值相同（即，全为 <code>0</code> 或者全为 <code>1</code>），将 <code>isLeaf</code> 设为 True ，将 <code>val</code> 设为网格相应的值，并将四个子节点都设为 Null 然后停止。</li>
	<li>如果当前网格的值不同，将 <code>isLeaf</code> 设为 False， 将 <code>val</code> 设为任意值，然后如下图所示，将当前网格划分为四个子网格。</li>
	<li>使用适当的子网格递归每个子节点。</li>
</ol>

<p><img style="height: 181px; width: 777px;" src="https://assets.leetcode.com/uploads/2020/02/11/new_top.png" alt=""></p>

<p>如果你想了解更多关于四叉树的内容，可以参考 <a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a> 。</p>

<p><strong>四叉树格式：</strong></p>

<p>输出为使用层序遍历后四叉树的序列化形式，其中 <code>null</code> 表示路径终止符，其下面不存在节点。</p>

<p>它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 <code>[isLeaf, val]</code> 。</p>

<p>如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 True ，则表示它在列表&nbsp;<code>[isLeaf, val]</code> 中的值为 <strong>1</strong> ；如果 <code>isLeaf</code> 或者 <code>val</code> 的值为 False ，则表示值为 <strong>0 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 99px; width: 777px;" src="https://assets.leetcode.com/uploads/2020/02/11/grid1.png" alt=""></p>

<pre><strong>输入：</strong>grid = [[0,1],[1,0]]
<strong>输出：</strong>[[0,1],[1,0],[1,1],[1,1],[1,0]]
<strong>解释：</strong>此示例的解释如下：
请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
<img style="height: 186px; width: 777px;" src="https://assets.leetcode.com/uploads/2020/02/12/e1tree.png" alt="">
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 343px; width: 777px;" src="https://assets.leetcode.com/uploads/2020/02/12/e2mat.png" alt=""></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
<strong>输出：</strong>[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>解释：</strong>网格中的所有值都不相同。我们将网格划分为四个子网格。
topLeft，bottomLeft 和 bottomRight 均具有相同的值。
topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
解释如下图所示：
<img style="height: 328px; width: 777px;" src="https://assets.leetcode.com/uploads/2020/02/12/e2tree.png" alt="">
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1],[1,1]]
<strong>输出：</strong>[[1,1]]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[0]]
<strong>输出：</strong>[[1,0]]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
<strong>输出：</strong>[[0,1],[1,1],[1,0],[1,0],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>n == 2^x</code> 其中 <code>0 &lt;= x &lt;= 6</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        int check = grid[x][y];
        for (int i = x; i < x + len && check != -1; i++) {
            for (int j = y; j < y + len && check != -1; j++) {
                check = (check != grid[i][j]) ? -1 : grid[i][j];
            }
        }

        if (check == -1) {
            len /= 2;
            Node* _topLeft = build(grid, x, y, len);
            Node* _topRight = build(grid, x, y + len, len);
            Node* _bottomLeft = build(grid, x + len, y, len);
            Node* _bottomRight = build(grid, x + len, y + len, len);
            return new Node(true, false, _topLeft, _topRight, _bottomLeft, _bottomRight);
        }

        return new Node(check == 1, true);
    }
};
```




