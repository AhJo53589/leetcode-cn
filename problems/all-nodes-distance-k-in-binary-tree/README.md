# `（中等）` [863.all-nodes-distance-k-in-binary-tree 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/)

### 题目描述
<p>给定一个二叉树（具有根结点&nbsp;<code>root</code>），&nbsp;一个目标结点&nbsp;<code>target</code>&nbsp;，和一个整数值 <code>K</code> 。</p>

<p>返回到目标结点 <code>target</code> 距离为 <code>K</code> 的所有结点的值的列表。 答案可以以任何顺序返回。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
<strong>输出：</strong>[7,4,1]
<strong>解释：</strong>
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1

<img style="height: 240px; width: 280px;" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png" alt="">

注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>给定的树是非空的。</li>
	<li>树上的每个结点都具有唯一的值&nbsp;<code>0 &lt;= node.val &lt;= 500</code>&nbsp;。</li>
	<li>目标结点&nbsp;<code>target</code>&nbsp;是树上的结点。</li>
	<li><code>0 &lt;= K &lt;= 1000</code>.</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/all-nodes-distance-k-in-binary-tree-by-i-kzn4/)

### 答题
``` C++
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->target = target;
        this->k = k;
        findTarget(root);
        return ans;
    }

    int findTarget(TreeNode* node) {
        if (node == nullptr) return -1;
        if (node == target) {
            checkDis(node, 0);
            return 1;
        }

        int dis = findTarget(node->left);
        if (dis != -1) {
            checkDis(node, dis, false, true);
            return dis + 1;
        }

        dis = findTarget(node->right);
        if (dis != -1) {
            checkDis(node, dis, true, false);
            return dis + 1;
        }
        return -1;
    }

    void checkDis(TreeNode* node, int dis, bool left = true, bool right = true) {
        if (node == nullptr) return;
        if (dis == k) {
            ans.push_back(node->val);
            return;
        }
        if (left) {
            checkDis(node->left, dis + 1);
        }
        if (right) {
            checkDis(node->right, dis + 1);
        }
    }

private:
    TreeNode* target;
    int k;
    vector<int> ans;
};
```




