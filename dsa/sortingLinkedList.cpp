#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x){
        this->val = x;
        this->next = nullptr;
    }
};

class Solution {
public:
    ListNode* insertIntoSortedList(ListNode* sortedHead, ListNode* newNode) {
        if (sortedHead == nullptr || sortedHead->val >= newNode->val) {
            newNode->next = sortedHead;
            return newNode;
        }
        ListNode* current = sortedHead;
        while (current->next != nullptr && current->next->val < newNode->val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return sortedHead;
    }
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* sortedHead = head;
        ListNode* unsortedHead = head->next;
        sortedHead->next = nullptr;
        while (unsortedHead != nullptr) {
            ListNode* nextNode = unsortedHead->next;
            unsortedHead->next = nullptr;
            sortedHead = insertIntoSortedList(sortedHead, unsortedHead);
            unsortedHead = nextNode;
        }
        return sortedHead;
    }
    void printList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
    ListNode* createList(int arr[], int n) {
        if (n == 0) return nullptr;
        
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        
        for (int i = 1; i < n; i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        
        return head;
    }
};

int main() {
    Solution solution;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = solution.createList(arr, n);
    std::cout << "Original List: ";
    solution.printList(head);
    head = solution.insertionSortList(head);
    std::cout << "Sorted List:   ";
    solution.printList(head);
    return 0;
}