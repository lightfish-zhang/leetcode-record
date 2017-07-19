
# Longest Substring Without Repeating Characters

```
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## 思路

- 问题简而言之，输入字符串，返回该字符串的不含重复字母的最长子节的长度
- 细化问题：
    + 如何查找不含重复字母的最长子节： `两个相同字符的最短间距`，这间距中的字符串就是不重复的子节
    + 判断字母是否重复，需要有保存字母出现的位置的存储结构用作判断
    + 在寻找过程中，淘汰，只保存找到的最大长度的值

- 建一个`字符 - 计数`映射关系的线性表，参考常用的字符表的长度，

    + `int[26]` for Letters 'a' - 'z' or 'A' - 'Z'
    + `int[128]` for ASCII
    + `int[256]` for Extended ASCII
