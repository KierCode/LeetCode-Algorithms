/*
- 23) Merge k Sorted Lists
    
    You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.
    
    *Merge all the linked-lists into one sorted linked-list and return it.*
    
    **Example 1:**
    
    ```
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6
    
    ```
    
    **Example 2:**
    
    ```
    Input: lists = []
    Output: []
    
    ```
    
    **Example 3:**
    
    ```
    Input: lists = [[]]
    Output: []
    
    ```
    
    **Constraints:**
    
    - `k == lists.length`
    - `0 <= k <= 104`
    - `0 <= lists[i].length <= 500`
    - `104 <= lists[i][j] <= 104`
    - `lists[i]` is sorted in **ascending order**.
    - The sum of `lists[i].length` will not exceed `104`.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int n = lists.size();
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                lists[i] = merge(lists[i], lists[n - 1 - i]);
            }
            n = (n + 1) / 2;
        }
        
        return lists[0];
    }
};