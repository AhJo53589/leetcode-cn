# `（困难）` [968.binary-tree-cameras 监控二叉树](https://leetcode-cn.com/problems/binary-tree-cameras/)

### 题目描述
<p>给定一个二叉树，我们在树的节点上安装摄像头。</p>

<p>节点上的每个摄影头都可以监视<strong>其父对象、自身及其直接子对象。</strong></p>

<p>计算监控树的所有节点所需的最小摄像头数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 163px; width: 138px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_01.png" alt=""></p>

<pre><strong>输入：</strong>[0,0,null,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>如图所示，一台摄像头足以监控所有节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 312px; width: 139px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_02.png" alt=""></p>

<pre><strong>输入：</strong>[0,0,null,0,null,0,null,null,0]
<strong>输出：</strong>2
<strong>解释：</strong>需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
</pre>

<p><br>
<strong>提示：</strong></p>

<ol>
	<li>给定树的节点数的范围是&nbsp;<code>[1, 1000]</code>。</li>
	<li>每个节点的值都是 0。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-cameras/solution/binary-tree-cameras-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        ans += postOrder(root) == 2;
        return ans;
    }

    // 返回值表示与摄像头的距离
    int postOrder(TreeNode* root) {
        if (root == nullptr) return 1;

        int l = postOrder(root->left);
        int r = postOrder(root->right);

        int ret = min(l, r) + 1;
        if (max(l, r) == 2) {
            ret = 0;
            ans++;
        }
        return ret;
    }

private:
    int ans = 0;
};
```




