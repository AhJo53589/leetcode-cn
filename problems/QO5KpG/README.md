# `（中等）` [LCP 52.QO5KpG 二叉搜索树染色](https://leetcode-cn.com/problems/QO5KpG/)

### 题目描述
<p>欢迎各位勇者来到力扣城，本次试炼主题为「二叉搜索树染色」。</p>
<p>每位勇士面前设有一个<strong>二叉搜索树</strong>的模型，模型的根节点为 <code>root</code>，树上的各个节点值均不重复。初始时，所有节点均为蓝色。现在按顺序对这棵二叉树进行若干次操作， <code>ops[i] = [type, x, y]</code> 表示第 <code>i</code> 次操作为：</p>
<ul>
<li><code>type</code> 等于 0 时，将节点值范围在 <code>[x, y]</code> 的节点均染蓝</li>
<li><code>type</code> 等于 1 时，将节点值范围在 <code>[x, y]</code> 的节点均染红</li>
</ul>
<p>请返回完成所有染色后，该二叉树中红色节点的数量。</p>
<p><strong>注意：</strong></p>
<ul>
<li>题目保证对于每个操作的 <code>x</code>、<code>y</code> 值定出现在二叉搜索树节点中</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>root = [1,null,2,null,3,null,4,null,5], ops = [[1,2,4],[1,1,3],[0,3,5]]</code></p>
<p>输出：<code>2</code></p>
<p>解释：<br>
第 0 次操作，将值为 2、3、4 的节点染红；<br>
第 1 次操作，将值为 1、2、3 的节点染红；<br>
第 2 次操作，将值为 3、4、5 的节点染蓝；<br>
因此，最终值为 1、2 的节点为红色节点，返回数量 2<br>
<img src="https://pic.leetcode-cn.com/1649833948-arSlXd-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " width="230px"></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>root = [4,2,7,1,null,5,null,null,null,null,6]</code><br>
<code>ops = [[0,2,2],[1,1,5],[0,4,5],[1,5,7]]</code></p>
<p>输出：<code>5</code></p>
<p>解释：<br>
第 0 次操作，将值为 2 的节点染蓝；<br>
第 1 次操作，将值为 1、2、4、5 的节点染红；<br>
第 2 次操作，将值为 4、5 的节点染蓝；<br>
第 3 次操作，将值为 5、6、7 的节点染红；<br>
因此，最终值为 1、2、5、6、7 的节点为红色节点，返回数量 5<br>
<img src="https://pic.leetcode-cn.com/1649833763-BljEbP-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " width="230px"></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= 二叉树节点数量 &lt;= 10^5</code></li>
<li><code>1 &lt;= ops.length &lt;= 10^5</code></li>
<li><code>ops[i].length == 3</code></li>
<li><code>ops[i][0]</code> 仅为 <code>0</code> or <code>1</code></li>
<li><code>0 &lt;= ops[i][1] &lt;= ops[i][2] &lt;= 10^9</code></li>
<li><code>0 &lt;= 节点值 &lt;= 10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
    set<int> st;

    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        st.insert(node->val);  //将节点放入st中
        dfs(node->left);
        dfs(node->right);
    }

public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int ans = 0;
        for (int i = (int) ops.size() - 1; i >= 0; i--) {
            while (true) {
                auto it = st.lower_bound(ops[i][1]);  //寻找所有在该区间内的节点
                if (it == st.end() || (*it) > ops[i][2]) break;  //已经超出区间了
                st.erase(it);  //删除对应节点
                if (ops[i][0]) ans++;  //如果染成的是红色，ans+1
            }
        }
        return ans;
    }
};
```




