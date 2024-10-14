/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//题目：24.两两交换链表中的节点 时间：2024.9.19

struct ListNode* swapPairs(struct ListNode* head) {
    //创建一个哑节点
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* temp = &dummyHead;

    //现在从第一个节点开始排序
    while(temp->next != NULL && temp->next->next != NULL)
    {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;//位移到下一个位置
    }
    //返回哑节点
    return dummyHead.next;
}