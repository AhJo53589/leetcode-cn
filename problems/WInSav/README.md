# `（困难）` [LCP 60.WInSav 力扣泡泡龙](https://leetcode-cn.com/problems/WInSav/)

### 题目描述
<p>欢迎各位勇者来到力扣城，本次试炼主题为「力扣泡泡龙」。</p>
<p>游戏初始状态的泡泡形如二叉树 <code>root</code>，每个节点值对应了该泡泡的分值。勇者最多可以击破一个节点泡泡，要求满足：</p>
<ul>
<li>被击破的节点泡泡 <strong>至多</strong> 只有一个子节点泡泡</li>
<li>当被击破的节点泡泡有子节点泡泡时，则子节点泡泡将取代被击破泡泡的位置
<blockquote>
<p>注：即整棵子树泡泡上移</p>
</blockquote>
</li>
</ul>
<p>请问在击破一个节点泡泡操作或无击破操作后，二叉泡泡树的最大「层和」是多少。</p>
<p><strong>注意：</strong></p>
<ul>
<li>「层和」为同一高度的所有节点的分值之和</li>
</ul>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>root = [6,0,3,null,8]</code></p>
<p>输出：<code>11</code></p>
<p>解释：勇者的最佳方案如图所示<br>
<img src="https://pic.leetcode-cn.com/1648180809-XSWPLu-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="100px"></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>root = [5,6,2,4,null,null,1,3,5]</code></p>
<p>输出：<code>9</code></p>
<p>解释：勇者击破 6 节点，此时「层和」最大为 3+5+1 = 9<br>
<img src="https://pic.leetcode-cn.com/1648180769-TLpYop-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="200px"></p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>root = [-5,1,7]</code></p>
<p>输出：<code>8</code></p>
<p>解释：勇者不击破节点，「层和」最大为 1+7 = 8</p>
</blockquote>
<p><strong>提示</strong>：</p>
<ul>
<li><code>2 &lt;= 树中节点个数 &lt;= 10^5</code></li>
<li><code>-10000 &lt;= 树中节点的值 &lt;= 10000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMaxLayerSum(TreeNode* root) {

    }
};
```




