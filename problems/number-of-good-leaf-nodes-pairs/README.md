# `（中等）` [5474.number-of-good-leaf-nodes-pairs 好叶子节点对的数量](https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs/)

[contest](https://leetcode-cn.com/contest/weekly-contest-199/problems/number-of-good-leaf-nodes-pairs/)

### 题目描述
<p>给你二叉树的根节点 <code>root</code> 和一个整数 <code>distance</code> 。</p>

<p>如果二叉树中两个 <strong>叶</strong> 节点之间的 <strong>最短路径长度</strong> 小于或者等于 <code>distance</code> ，那它们就可以构成一组 <strong>好叶子节点对</strong> 。</p>

<p>返回树中 <strong>好叶子节点对的数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p>&nbsp;</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/26/e1.jpg" style="height: 321px; width: 321px;"></p>

<pre><strong>输入：</strong>root = [1,2,3,null,4], distance = 3
<strong>输出：</strong>1
<strong>解释：</strong>树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/26/e2.jpg" style="height: 321px; width: 441px;"></p>

<pre><strong>输入：</strong>root = [1,2,3,4,5,6,7], distance = 3
<strong>输出：</strong>2
<strong>解释：</strong>好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
<strong>输出：</strong>1
<strong>解释：</strong>唯一的好叶子节点对是 [2,5] 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [100], distance = 1
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>root = [1,1,1], distance = 2
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>tree</code> 的节点数在 <code>[1, 2^10]</code> 范围内。</li>
	<li>每个节点的值都在 <code>[1, 100]</code> 之间。</li>
	<li><code>1 &lt;= distance &lt;= 10</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if (root == nullptr) return 0;
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance, int& ans) {
        if (root->left == nullptr && root->right == nullptr) return { 0 };

        vector<int> ret;
        vector<vector<int>> leaf(2, vector<int>());
        for (int i = 0; i < 2; i++) {
            TreeNode* child = (i == 0) ? root->left : root->right;
            if (child == nullptr) continue;

            leaf[i] = dfs(child, distance, ans);
            for (int j = 0; j < leaf[i].size(); j++) {
                if (++leaf[i][j] > distance) continue;
                ret.push_back(leaf[i][j]);
            }
        }

        for (int i = 0; i < leaf[0].size(); i++) {
            for (int j = 0; j < leaf[1].size(); j++) {
                int dis = leaf[0][i] + leaf[1][j];
                ans += (dis <= distance);
            }
        }

        return ret;
    }
};
```




