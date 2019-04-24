# leetcode-cn


---
## 20190424
217.ContainsDuplicate 存在重复元素  
这道题前两天面试官现场问我的，  
当时我说先排序，再判断相邻两个数字是否相同。  
面试官还问可不可以不排序，  
我就又说用map记录一下。  
结果测试速度最快的就是先排序那个方法。  


189.Rotate 旋转数组  

这道简单的题，看到要求使用空间复杂度为 O(1) 的原地算法。  
就规避了使用公共算法，额外的数组等。  
想着想着就感觉走上了歪路。  
不过幸好突破了最后的难关，让这条小路顺利抵达终点。  
详细思路查看草稿Rotate.xlsx  
我就想不管k是几，就让后面的数一口气先交换获得最终结果。  
然后剩下的被交换的乱七八糟的数字，再找规律。
万幸最后找到了规律，感觉还不错。


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

---
## 20190423
122.MaxProfit 买卖股票的最佳时机 II  
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

---
## 20190422
整理了这个库，leetcode都放这里好了。

26.RemoveDuplicates 删除排序数组中的重复项，简单。
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

---
## 20190419

这两天开始做leetcode，随便选了一个2018算法的习题集，然后有5道热身题，做完真是大开眼界，同时也被虐的很惨。

前面几道题都很打击我，不过还好脆脆来开导我，保住了信心。  

前几道就光在题目上思考，结果最后看别人答案都是从数学角度出发。  
然后今天做最后一道题，终于也朝着数学的方向思考，估计想了2个多小时。  
没想到修正了几次思路之后，就找到钥匙啦。
做完之后显示击败了99.35%的用户，开心啊。  

* 鸡蛋掉落 Super Egg Drop  

解题思路，从【已知N层楼，K个蛋，求最小必要行动次数T】  
变成【已知K个蛋，求T次行动可以判断的楼层数>N】