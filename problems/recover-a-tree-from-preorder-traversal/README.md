# `（困难）` [1028.recover-a-tree-from-preorder-traversal 从先序遍历还原二叉树](https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/)

### 题目描述
<p>我们从二叉树的根节点 <code>root</code>&nbsp;开始进行深度优先搜索。</p>

<p>在遍历中的每个节点处，我们输出&nbsp;<code>D</code>&nbsp;条短划线（其中&nbsp;<code>D</code>&nbsp;是该节点的深度），然后输出该节点的值。（<em>如果节点的深度为 <code>D</code>，则其直接子节点的深度为 <code>D + 1</code>。根节点的深度为 <code>0</code>）。</em></p>

<p>如果节点只有一个子节点，那么保证该子节点为左子节点。</p>

<p>给出遍历输出&nbsp;<code>S</code>，还原树并返回其根节点&nbsp;<code>root</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 200px; width: 320px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/04/12/recover-a-tree-from-preorder-traversal.png" alt=""></strong></p>

<pre><strong>输入：</strong>"1-2--3--4-5--6--7"
<strong>输出：</strong>[1,2,5,3,4,6,7]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 250px; width: 256px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/04/12/screen-shot-2019-04-10-at-114101-pm.png" alt=""></strong></p>

<pre><strong>输入：</strong>"1-2--3---4-5--6---7"
<strong>输出：</strong>[1,2,5,3,null,6,null,4,null,7]
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="height: 250px; width: 276px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/04/12/screen-shot-2019-04-10-at-114955-pm.png" alt=""></p>

<pre><strong>输入：</strong>"1-401--349---90--88"
<strong>输出：</strong>[1,401,null,349,88,90]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>原始树中的节点数介于 <code>1</code> 和 <code>1000</code> 之间。</li>
	<li>每个节点的值介于 <code>1</code> 和 <code>10 ^ 9</code> 之间。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/solution/recover-a-tree-from-preorder-traversal-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int start = 0;
        return preOrder(S, start, 0);
    }

    TreeNode* preOrder(string& S, int& start, int lv) {
        int nextLv = getDepth(S, start);
        if (nextLv != lv) {
            return nullptr;
        }
        start += lv;
        int val = getVal(S, start);
        TreeNode* node = new TreeNode(val);
        node->left = preOrder(S, start, lv + 1);
        node->right = preOrder(S, start, lv + 1);
        return node;
    }

    int getDepth(string& S, int start) {
        int cnt = 0;
        while (start < S.size() && S[start + cnt] == '-') {
            cnt++;
        }
        return cnt;
    }

    int getVal(string& S, int& start) {
        int val = 0;
        while (start < S.size() && S[start] != '-') {
            val *= 10;
            val += (int)(S[start] - '0');
            start++;
        }
        return val;
    }
};
```




