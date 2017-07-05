// You are given two non-empty linked lists representing non-negative integers
// The digits are stored in reverse order and each of their nodes contain
// a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself
// Input 2->4->3 + 5->6->4 
// Ouput 7->0->8

/**
 * Defination for singly-linked list
 * Struct listNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x): val(x), next(null) {}
 * };
 */


#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
};

// 构建一个链表
ListNode * createList(vector<int> v)
{
    ListNode *root = 0, *newNode = 0, *tailNode = 0;
    for (int i = 0; i < v.size(); ++i) {
        newNode = new ListNode;
        newNode->val = v[i];
        newNode->next = 0; 
        if (i == 0) {
            tailNode = newNode;
            root = newNode;
        }
        else {
            tailNode->next = newNode;
            tailNode = newNode;          
        }
    }
    return root;
}

void printList(ListNode *l) 
{
    ListNode *p = l;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *p1Pre = 0;
        int tmp = 0, one = 0;
        while (p1 && p2) {
            tmp = p1->val + p2->val + one;
            one = tmp / 10;
            p1->val = tmp % 10; 
            p1Pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2) {
            p1Pre->next = p2;
            p1 = p2;
        }
        while (p1) {
            tmp = p1->val + one;
            one = tmp / 10;
            p1->val = tmp % 10;
            p1Pre = p1;
            p1 = p1->next; 
        }
        if (one) {
            ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->val = one;
            newNode->next = 0;
            p1Pre->next = newNode;
        }
        return l1;
    }
};

int main()
{
    //int test1[] = {1};
    int test1[] = {2, 4, 3};
    vector<int> v1(test1, test1 + sizeof(test1) / sizeof(test1[0]));
    ListNode *list1 = createList(v1);
    cout << "List1:  ";
    printList(list1);

    //int test2[] = {9, 9};
    int test2[] = {5, 6, 4};
    vector<int> v2(test2, test2 + sizeof(test2) / sizeof(test2[0]));
    ListNode *list2 = createList(v2);
    cout << "List2: ";
    printList(list2);

    Solution s;
    ListNode *result = s.addTwoNumbers(list1, list2);
    printList(result);
    return 0;
}
