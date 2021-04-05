# `（简单）` [LCP_29.SNJvJP 乐团站位](https://leetcode-cn.com/problems/SNJvJP/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/SNJvJP/)

### 题目描述
<div class="css-1708ckn" style="padding: 0px; margin: 13px 0px;"><p>某乐团的演出场地可视作 <code>num * num</code> 的二维矩阵 <code>grid</code>（左上角坐标为 <code>[0,0]</code>)，每个位置站有一位成员。乐团共有 <code>9</code> 种乐器，乐器编号为 <code>1~9</code>，每位成员持有 <code>1</code> 个乐器。</p>
<p>为保证声乐混合效果，成员站位规则为：自 <code>grid</code> 左上角开始顺时针螺旋形向内循环以 <code>1，2，...，9</code> 循环重复排列。例如当 num = <code>5</code> 时，站位如图所示</p>
<p align="center"><img src="https://pic.leetcode-cn.com/1616125411-WOblWH-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
<p>请返回位于场地坐标 [<code>Xpos</code>,<code>Ypos</code>] 的成员所持乐器编号。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>num = 3, Xpos = 0, Ypos = 2</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1616125437-WUOwsu-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>num = 4, Xpos = 1, Ypos = 2</code></p>
<p>输出：<code>5</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1616125453-IIDpxg-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= num &lt;= 10^9</code></li>
<li><code>0 &lt;= Xpos, Ypos &lt; num</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int up = xPos;
        int down = num - xPos - 1;
        int left = yPos;
        int right = num - yPos - 1;

        int turn = min({ up, down, left, right });

        long long a = 1LL * num * 4 - 4;
        long long b = 1LL * (num - (turn - 1) * 2) * 4 - 4;
        long long ans = 0;
        if (turn != 0) {
            ans = (turn == 1) ? a : (a + b) * turn / 2;
        }
        num -= turn * 2;
        xPos -= turn;
        yPos -= turn;

        vector<int> sz = { num, num - 1 };
        vector<vector<int>> dd = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        for (int d = 0, x = 0, y = -1; ; d = (d + 1) % dd.size()) {
            if (x != xPos && y != yPos) {
                x += dd[d][0] * sz[d % 2];
                y += dd[d][1] * sz[d % 2];
                ans += sz[d % 2];
            }
            else {
                ans += max(abs(x - xPos), abs(y - yPos));
                break;
            }
            sz[d % 2]--;
        }

        return ((ans - 1) % 9) + 1;
    }
};
```




