#include <stdio.h>

int lengthOfLongestSubstring(char* str)
{
	int len = 0;
    char *pointer = str, *temp;
	char *map[128] = {NULL}; // 声明一个`字符指针`的数组，存放指针(内存地址的值), 下标作为ASCII的0~127号码
	while(*pointer){ // 遍历字符串的字符
        //printf("pointer is %p\n", pointer); // C语言程序内存分配，局部变量在内存的栈区从低地址向高地址分配
		temp = map[*pointer]; // 获取某字符上一次出现的内存地址, 赋值temp， 若字符没出现过，temp为nil
        //printf("temp is %p\n", temp);
		map[*pointer] = pointer; // 映射表记录某字符这一次出现的内存地址, `字符`-`最后一次出现的地址`的映射
		if(temp >= str){ // 当前字符串(字符的地址数组)含有`temp地址`
            len = pointer - str > len ? pointer - str : len; // 记录不重复字母数的字节的最大长度
            str = temp + 1; // 裁剪输入的字符串, 移除`发现重复的字符`(去除地址)
		} 
        pointer++;
	}
	len = pointer - str > len ? pointer - str : len;
	return len;
}

int 
main()
{
    printf("abcabcbb, result is %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("abcdefg, result is %d\n", lengthOfLongestSubstring("abcdefg"));
}