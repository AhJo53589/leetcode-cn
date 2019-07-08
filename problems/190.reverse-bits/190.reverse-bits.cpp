// 190.reverse-bits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <bitset>

uint32_t reverseBits(uint32_t n)
{
	int i = 32;
	uint32_t res = 0;
	while (i--)
	{
		res <<= 1;//向左移一位 
		res += n & 1;
		n >>= 1;//向右移一位 
	}
	return res;
}

//uint32_t reverseBits(uint32_t n)
//{
//	bitset<32> b = n;
//	for (int i = 0; i < 16; i++)
//	{
//		if (b[i] != b[31 - i])
//		{
//			b[i] = !b[i];
//			b[31 - i] = !b[31 - i];
//		}
//	}
//	return b.to_ulong();//将bitset转换成unsigned long类型 
//}

int main()
{
    std::cout << "Hello World!\n"; 
}
