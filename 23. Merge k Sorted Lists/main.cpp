#include <iostream>
#include <vector>
#include <queue>

using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     explicit ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 *
 * };
 */


struct ListNode {
    int val;
    ListNode *next;     // pointer to the next node in the list
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};
class Solution {
public:
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next) pq.push(smallest->next);
        }

        return dummy.next;
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    if (!head) {
        cout << "[]"; // Empty list
        return;
    }

    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    // Create input
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));


    ListNode* l4 = nullptr; // empty list
    vector<ListNode*> lists = {l4};

    ListNode* mergedList = Solution::mergeKLists(lists);

    cout << "Merged list: ";
    printLinkedList(mergedList);

    return 0;
}