#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; //进位
        ListNode preHead(0), *p = &preHead;
        while(l1||l2||carry){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        return preHead.next;
    }
};

int
main()
{
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution st;
    ListNode *result = st.addTwoNumbers(l1, l2);
    while(result){
        cout << result->val << endl;
        result = result->next;
    }

}