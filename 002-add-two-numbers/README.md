# add two numbers

## 题目

```
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```

乍一看有点不明白，看例子，是243+564=708，原来是把每个数都放在链表的一个元素中，从高位放到低位，实际的链表是翻转的，例子中的`(2->4->3)`在输入时是`(3->4->2)`

## 思路

很简单，同时遍历两个链表，每一个元素相加，有进位就加到下一轮