# `（简单）` [100267.collect-beads 理琥珀珠](https://leetcode-cn.com/problems/collect-beads/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/collect-beads/)

### 题目描述
<p>xm 小时候很喜欢和小伙伴一起玩玻璃球，不过现在没有伙伴一起玩玻璃球了😭。xm 看着自己收藏了多年的玻璃球，突然发现其中有一颗琥珀珠，便想出一道自己一个人可以用这些玻璃球玩的游戏：(整)理琥珀珠。</p>
<p>有 n 个并排立在地上底部可开关的管道，每个管道中都有一个珠子，珠子的直径略小于管道的直径，其中有一个管道中是琥珀珠子，其余的都是玻璃珠子。琥珀珠子易碎，会被玻璃珠子压坏。</p>
<p>你可以进行如下操作：每次选择一个管道，若其中有 x 个珠子，则可以将其底部打开，把其中的珠子依次装入该管道左边或右边第 x 个管道中。</p>
<p>请你返回能够完好收集所有珠子到一个管道中的操作列表。</p>
<p><strong>输入：</strong></p>
<ol>
	<li>
	<p>n : 总共有 n 个管道&nbsp; （ 2 &lt;= n &lt;= 1000&nbsp;）</p>
	</li>
	<li>
	<p>amberIndex : 玻璃珠子所在管道的下标 （ 0 &lt;= glassIndex &lt;&nbsp;n ）</p>
	</li>
</ol>

<p><strong>输出：</strong></p>
<p>返回一个长度为 n - 1 的数组 operations，数组的每个元素是一个长度为 2 的数组 operation。operation[0] 表示的管道的下标， operation[1] 表示目标管道在选择的管道的左边还是右边，有两种值：0 表示左边，1 表示右边。例如： operation = [1, 0] 表示选择下标为 1 的管道，将其中的所有珠子装入其左边对应的管道中。</p>
<p>&nbsp;</p>
<p><strong>示例 1&nbsp;：</strong></p>
<pre><strong>输入：</strong>n = 2, amberIndex = 0

<strong>输出：</strong>operations = [[0, 1]]

<strong>解释：
</strong>将第一个管道中的 1 个珠子装入第二个管道中，
所有的珠子完好收集在第二个管道中。
</pre>

<p>&nbsp;</p>
<p><strong>示例 2 ：</strong></p>
<pre><strong>输入：</strong>n = 4, amberIndex = 0

<strong>输出：</strong>operations = [[0, 1], [2, 1], [1, 1]]

<strong>解释：
</strong>将第一个管道中的 1 个珠子装入第二个管道中，
再将第三个管道中的 1 个珠子装入第四个管道中，
最后将第二个管道中的 2 个珠子装入第四个管道中，
所有的珠子完好收集在第四个管道中。

<img alt="" src="./e2965a310ec153adbca39cb372e866160ca840bfe9ab86b78c092f9b5d00e7b6-%E7%A4%BA%E4%BE%8B.png">
</pre>

​            

---
### 思路
```

```



### 答题
``` C++
class Solution {
public:
	int s;
	vector<vector<int>> ret;
	int solve(int L, int R, int target) {
		// trace(L, R, target);
		if (target != -1 && !(target >= L && target < R)) cout << "..." << endl;
		if (L + 1 == R) return L;
		int mid = (L + R) / 2;
		if (target == -1) {
			if (s >= mid && R - mid > mid - L) ++mid;
			// trace(L, R, mid, s);
			if (s >= mid) {
				int pos = solve(mid, R, -1);
				solve(L, mid, pos - (R - mid));
				ret.push_back({ pos, 0 });
				return pos - (R - mid);
			}
			else {
				int pos = solve(L, mid, -1);
				solve(mid, R, pos + (mid - L));
				ret.push_back({ pos, 1 });
				return pos + (mid - L);
			}
		}
		else {
			if (target >= mid && R - mid > mid - L) ++mid;
			if (target >= mid) {
				int pos = solve(L, mid, target - (mid - L));
				solve(mid, R, target);
				ret.push_back({ pos, 1 });
			}
			else {
				solve(L, mid, target);
				int pos = solve(mid, R, target + (R - mid));
				ret.push_back({ pos, 0 });
			}
			return target;
		}
		return -1;
	}
	vector<vector<int>> collectBeads(int n, int s) {
		this->s = s;
		ret.clear();
		solve(0, n, -1);
		return ret;
	}
};
```




