# `（简单）` [LCP 44.sZ59z6 开幕式焰火](https://leetcode-cn.com/problems/sZ59z6/)

[contest](https://leetcode-cn.com/contest/season/2021-fall/problems/sZ59z6/)

### 题目描述
<p>「力扣挑战赛」开幕式开始了，空中绽放了一颗二叉树形的巨型焰火。<br>
给定一棵二叉树 <code>root</code> 代表焰火，节点值表示巨型焰火这一位置的颜色种类。请帮小扣计算巨型焰火有多少种不同的颜色。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>root = [1,3,2,1,null,2]</code></p>
<p>输出：<code>3</code></p>
<p>解释：焰火中有 3 个不同的颜色，值分别为 1、2、3</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>root = [3,3,3]</code></p>
<p>输出：<code>1</code></p>
<p>解释：焰火中仅出现 1 个颜色，值为 3</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= 节点个数 &lt;= 1000</code></li>
<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numColor(TreeNode* root) {
        if (root == nullptr) return ans.size();
        ans.insert(root->val);
        numColor(root->left);
        numColor(root->right);
        return ans.size();
    }

private:
    unordered_set<int> ans;
};
```




