# leetcode-cn


---
## 20190424
* 189.Rotate 旋转数组  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/189.Rotate/Description.jpg)

这道简单的题，看到要求使用空间复杂度为 O(1) 的原地算法。  
就规避了使用公共算法，额外的数组等。  
想着想着就感觉走上了歪路。  
不过幸好突破了最后的难关，让这条小路顺利抵达终点。  

思路和代码：  
我就想不管k是几，就让后面的数一口气先交换获得最终结果。  
然后剩下的被交换的乱七八糟的数字，再找规律。
万幸最后找到了规律，感觉还不错。  

``` C++
void rotate(vector<int>& nums, int k)	// 28ms
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}
		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}
``` 
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/189.Rotate/Solution.jpg)



另外分享一下看到的超简洁的思路
``` C++
void rotate(vector<int>& nums, int k)	// 12ms
{
	k = k >= nums.size() ? k - nums.size() : k;
	if (k)
	{
		reverse(nums.begin(), nums.end() - k);
		reverse(nums.end() - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
}
```

* 217.ContainsDuplicate 存在重复元素  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/217.ContainsDuplicate/Description.jpg)

这道题前两天面试官现场问我的，  
当时我说先排序，再判断相邻两个数字是否相同。  
面试官还问可不可以不排序，  
我就又说用map记录一下。  
结果测试速度最快的就是先排序那个方法。  

``` C++
bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}
```



---
## 20190423
* 122.MaxProfit 买卖股票的最佳时机 II  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/122.MaxProfit/Description.jpg)

``` C++
int maxProfit(vector<int>& prices)	// 12ms
{
	if (prices.size() < 2) return 0;

	int iLen = prices.size();
	int iMaxValue = 0;
	int high = prices[iLen - 1];
	int low = high;
	int j = iLen - 2;
	while (j >= 0)
	{
		if (high < prices[j])
		{
			if (low < high)
			{
				iMaxValue += high - low;
			}
			high = prices[j];
			low = high;
		}
		else
		{
			if (prices[j] < low)
			{
				low = prices[j];
			}
			else
			{
				iMaxValue += high - low;
				high = prices[j];
				low = high;
			}
		}
		j--;
	}
	if (low < high)
	{
		iMaxValue += high - low;
	}
	return iMaxValue;
}
```  

看了第一的算法，感觉智商被爆了。  
研究了两个小时，还画了草稿，总算有点感觉要明白了。  
想不通的原因，是虽然我的代码提交，结果对了，  
但是我并没有把题目的内在的规律摸清楚，  
有点连蒙带猜的感觉。  
仔细想了想，核心思路其实一样的，只是我每一步都交代的特别仔细。  
而大佬的算法可以将可能无用的东西先吃进去，  
然后在内部消化取舍。  
这样循环执行过程就非常的简洁，非常犀利。  

``` C++
int maxProfit(vector<int>& prices)	// 4ms
{
	if (prices.size() < 2)return 0;
	int hold = -prices[0], unhold = 0;
	for (int i = 1; i < prices.size(); ++i) {
		int tmp = hold;
		hold = max(hold, unhold - prices[i]);
		unhold = max(unhold, tmp + prices[i]);
	}
	return unhold;
}
```  

草稿分析了一下这个算法：  
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/122.MaxProfit/Solution.jpg)


* 50.MyPow  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/50.MyPow/Description.jpg)

``` C++
double myPow(double x, int n)	// 4ms
{
	switch (n)
	{
	case -1:
		return 1 / x;
	case 0:
		return 1.0;
	case 1:
		return x;
	case 2:
		return x * x;
	}

	return myPow(myPow(x, 2), n / 2) * myPow(x, n % 2);
}
```

* 88.Merge 合并两个有序数组  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/88.Merge/Description.jpg)

``` C++
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int k = m + n;

	while (k > 0)
	{
		k -= 1;
		if (m > 0 && n > 0)
		{
			if (nums1[m - 1] < nums2[n - 1])
			{
				nums1[k] = nums2[n - 1];
				n -= 1;
			}
			else
			{
				nums1[k] = nums1[m - 1];
				m -= 1;
			}
		}
		else if (m == 0 && n != 0)
		{
			nums1[k] = nums2[n - 1];
			n -= 1;
		}
		else if (m != 0 && n == 0)
		{
			break;
			//nums1[k] = nums1[m - 1];
			//m -= 1;
		}
	}
}
```

---
## 20190422
* 26.RemoveDuplicates 删除排序数组中的重复项  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/26.RemoveDuplicates/Description.jpg)

别人写的这个代码，感觉比较精简。
``` C++
int removeDuplicates(vector<int>& nums)		// 20ms
{
	if (nums.size() == 0) return 0;
	auto i = 0;
	auto j = 0;
	while (j < nums.size()) 
	{
		if (nums[i] == nums[j]) j++;
		else nums[++i] = nums[j];
	}
	return i + 1;
}
```

* 136.SingleNumber 只出现一次的数字  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/136.SingleNumber/Description.jpg)

来LeetCode做的第一道题，打开了新世界的大门。  
重新学了一遍异或。
``` C++
int singleNumber(vector<int>& nums)
{
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}
```

* 169.MajorityElement 求众数  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/169.MajorityElement/Description.jpg)

感觉思路和上面那道题有点像。  
有意思的地方是，当计数回到0的时候，就可以放弃他，换一个新数了。  
这只有众数的特点才能这么写的算法。  

``` C++
int majorityElement(vector<int>& nums)
{
	int res = 0, cnt = 0;
	for (int num : nums) 
	{
		if (cnt == 0) 
		{ 
			res = num;
			++cnt; 
		}
		else
		{
			(num == res) ? ++cnt : --cnt;
		}
	}
	return res;
}
```

* 206.ReverseList 反转链表  
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/206.ReverseList/Description.jpg)

这道题之前就做过。  

``` C++
ListNode* ReverseIteratively(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		// get the next node, and save it at pNext
		ListNode* pNext = pNode->m_pNext;
		// reverse the linkage between nodes
		pNode->m_pNext = pPrev;

		// move forward on the the list
		pPrev = pNode;
		pNode = pNext;
	}
	pReversedHead = pPrev;
	return pReversedHead;
}
```

> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/206.ReverseList/Solution.jpg)


* 240.SearchMatrix 搜索二维矩阵 II 
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/240.SearchMatrix/Description.jpg)

这道题做了好久。  
结果还是因为没有搞清楚矩阵的数学特点。  
下面的代码写的很符合特点。  

``` C++
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int r = matrix.size();
	if (r == 0) return false;

	int c = matrix[0].size();
	for (int i = 0, j = c - 1; i<r && j>-1;)
	{
		if (target < matrix[i][j])
		{
			j--;
		}
		else if (target > matrix[i][j])
		{
			i++;
		}
		else
		{
			return true;
		}
	}
	return false;
}
```

---
## 20190419

这两天开始做leetcode，随便选了一个2018算法的习题集，然后有5道热身题，做完真是大开眼界，同时也被虐的很惨。

前面几道题都很打击我，不过还好脆脆来开导我，保住了信心。  

前几道就光在题目上思考，结果最后看别人答案都是从数学角度出发。  
然后今天做最后一道题，终于也朝着数学的方向思考，估计想了2个多小时。  
没想到修正了几次思路之后，就找到钥匙啦。
做完之后显示击败了99.35%的用户，开心啊。  

* 887.SuperEggDrop 鸡蛋掉落
> Description.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Description.jpg)

解题思路，从【已知N层楼，K个蛋，求最小必要行动次数T】  
变成【已知K个蛋，求T次行动可以判断的楼层数>N】


``` C++
int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动iTime次，计算能判断多少层

	// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (iTime == 1) return 2;	

	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出iTime + 1层	
	if (K == 1) return iTime + 1;	

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层
	// + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1)
	 + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int iTime = 0;
	int iMaxCoverage = 0;
	do
	{
		++iTime;
		iMaxCoverage = calcMaximumCoverage(iTime, K);
	} while (iMaxCoverage < N + 1);
	return iTime;
}
```

草稿：  
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Solution.jpg)
> Solution2.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/887.SuperEggDrop/Solution2.jpg)