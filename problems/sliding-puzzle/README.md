# `（困难）` [773.sliding-puzzle 滑动谜题](https://leetcode-cn.com/problems/sliding-puzzle/)

### 题目描述
<p>在一个 2 x 3 的板上（<code>board</code>）有 5 块砖瓦，用数字 <code>1~5</code> 来表示, 以及一块空缺用&nbsp;<code>0</code>&nbsp;来表示.</p>

<p>一次移动定义为选择&nbsp;<code>0</code>&nbsp;与一个相邻的数字（上下左右）进行交换.</p>

<p>最终当板&nbsp;<code>board</code>&nbsp;的结果是&nbsp;<code>[[1,2,3],[4,5,0]]</code>&nbsp;谜板被解开。</p>

<p>给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>board = [[1,2,3],[4,0,5]]
<strong>输出：</strong>1
<strong>解释：</strong>交换 0 和 5 ，1 步完成
</pre>

<pre><strong>输入：</strong>board = [[1,2,3],[5,4,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>没有办法完成谜板
</pre>

<pre><strong>输入：</strong>board = [[4,1,2],[5,0,3]]
<strong>输出：</strong>5
<strong>解释：</strong>
最少完成谜板的最少移动次数是 5 ，
一种移动路径:
尚未移动: [[4,1,2],[5,0,3]]
移动 1 次: [[4,1,2],[0,5,3]]
移动 2 次: [[0,1,2],[4,5,3]]
移动 3 次: [[1,0,2],[4,5,3]]
移动 4 次: [[1,2,0],[4,5,3]]
移动 5 次: [[1,2,3],[4,5,0]]
</pre>

<pre><strong>输入：</strong>board = [[3,2,4],[1,5,0]]
<strong>输出：</strong>14
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>board</code>&nbsp;是一个如上所述的 2 x 3 的数组.</li>
	<li><code>board[i][j]</code>&nbsp;是一个&nbsp;<code>[0, 1, 2, 3, 4, 5]</code>&nbsp;的排列.</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sliding-puzzle/solution/sliding-puzzle-by-ikaruga-s7b6/)

### 答题
``` C++
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dd = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
        bitset<1000000> vi;
        int target = 54321;

        int start = 0;
        for (int i = board.size() - 1; ~i; i--) {
            for (int j = board[i].size() - 1; ~j; j--) {
                start *= 10;
                start += board[i][j];
            }
        }
        if (start == target) return 0;

        int ans = 0;
        queue<int> que;
        que.push(start);
        vi[start] = 1;

        while (!que.empty()) {
            for (int step = que.size() - 1; ~step; step--) {
                auto q = que.front();
                que.pop();

                int i = findZero(q);
                for (auto j : dd[i]) {
                    int next = swapDigit(q, i, j);
                    if (next == target) return ans + 1;
                    if (vi[next]) continue;
                    vi[next] = 1;
                    que.push(next);
                }
            }
            ans++;
        }

        return -1;
    }

    int findZero(int num) {
        for (int i = 0; i < 6; i++) {
            if (num % 10 == 0) return i;
            num /= 10;
        }
        return 6;
    }

    int swapDigit(int num, int i, int j) {
        int a = (num / (int)pow(10, i)) % 10;
        int b = (num / (int)pow(10, j)) % 10;
        return num + a * pow(10, j) + b * pow(10, i) - a * pow(10, i) - b * pow(10, j);
    }

    //void test() {
    //    int a = 54321;
    //    for (int i = 0; i < 6; i++) {
    //        for (int j = i + 1; j < 6; j++) {
    //            int b = swapDigit(a, i, j);
    //            cout << "[" << i << ", " << j << "] = " << setw(6) << setfill('0') << b << endl;
    //            cout << findZero(b) << endl;
    //        }
    //    }
    //}
};
```




