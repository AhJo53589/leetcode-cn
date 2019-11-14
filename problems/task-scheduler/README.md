# `（中等）` [621.task-scheduler 任务调度器](https://leetcode-cn.com/problems/task-scheduler/)

### 题目描述
<p>给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。</p>

<p>然而，两个<strong>相同种类</strong>的任务之间必须有长度为<strong>&nbsp;n </strong>的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。</p>

<p>你需要计算完成所有任务所需要的<strong>最短时间</strong>。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> tasks = ["A","A","A","B","B","B"], n = 2
<strong>输出:</strong> 8
<strong>执行顺序:</strong> A -&gt; B -&gt; (待命) -&gt; A -&gt; B -&gt; (待命) -&gt; A -&gt; B.
</pre>

<p><strong>注：</strong></p>

<ol>
	<li>任务的总个数为&nbsp;[1, 10000]。</li>
	<li>n 的取值范围为 [0, 100]。</li>
</ol>


---
### 思路
```
我的方法虽然分析出了规律但是还是模拟在做
而别人的方法直接用数学计算规律
```

### 答题
``` C++
int leastInterval(vector<char>& tasks, int n)
{
	array<int, 26> task_count = {};
	vector<int> task_order;

	for (auto &c : tasks)
	{
		task_count[c - 'A']++;
	}
	for (int i = 0; i < task_count.size(); i++)
	{
		if (task_count[i] == 0) continue;
		task_order.push_back(task_count[i]);
	}
	sort(task_order.rbegin(), task_order.rend());

	int res = 0;
	while (!task_order.empty())
	{
		int count = 0;
		for (int i = 0; i < task_order.size(); i++)
		{
			task_order[i]--;
			count++;
			if (count == n + 1) break;
		}
		sort(task_order.rbegin(), task_order.rend());
		while (!task_order.empty() && task_order.back() == 0) task_order.pop_back();

		res += task_order.empty() ? count : n + 1;
	}

	return res;
}
```

### 其它
``` C++
int leastInterval(vector<char>& tasks, int n) {
	int nums[26] = { 0 };
	int len = tasks.size();
	int max = 0;
	for (int i = 0; i < len; i++) {
		nums[tasks[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (max < nums[i])
			max = nums[i];
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (max == nums[i])
			count++;
	}
	int res = (max - 1)*(n + 1) + count;
	return res < len ? len : res;
}
```

