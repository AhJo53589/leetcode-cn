# `（中等）` [LCP_34.er-cha-shu-ran-se-UGC 二叉树染色](https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/er-cha-shu-ran-se-UGC/)

### 题目描述
<p>小扣有一个根结点为 <code>root</code> 的二叉树模型，初始所有结点均为白色，可以用蓝色染料给模型结点染色，模型的每个结点有一个 <code>val</code> 价值。小扣出于美观考虑，希望最后二叉树上每个蓝色相连部分的结点个数不能超过 <code>k</code> 个，求所有染成蓝色的结点价值总和最大是多少？</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>root = [5,2,3,4], k = 2</code></p>
<p>输出：<code>12</code></p>
<p>解释：<code>结点 5、3、4 染成蓝色，获得最大的价值 5+3+4=12</code><br>
<img src="https://pic.leetcode-cn.com/1616126267-BqaCRj-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>root = [4,1,3,9,null,null,2], k = 2</code></p>
<p>输出：<code>16</code></p>
<p>解释：结点 4、3、9 染成蓝色，获得最大的价值 4+3+9=16<br>
<img src="https://pic.leetcode-cn.com/1616126301-gJbhba-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= k &lt;= 10</code></li>
<li><code>1 &lt;= val &lt;= 10000</code></li>
<li><code>1 &lt;= 结点数量 &lt;= 10000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxValue(TreeNode* root, int k) {
        return dfs(root, k, k);
    }

    int dfs(TreeNode* root, int k, int t) {
        if (root == nullptr) return 0;
        if (um.find(root) != um.end()) {
            if (um[root][t] > -1) return um[root][t];
        }

        int ans = dfs(root->left, k, k) + dfs(root->right, k, k);
        if (t > 0) {
            for (int i = 0; i < t; i++) {
                int a = dfs(root->left, k, i);
                int b = dfs(root->right, k, t - 1 - i);
                ans = max(ans, a + b + root->val);
            }
        }

        if (um.find(root) == um.end()) {
            um[root] = vector<int>(k + 1, -1);
        }
        um[root][t] = ans;
        return ans;
    }

private:
    unordered_map<TreeNode*, vector<int>> um;
};
```




