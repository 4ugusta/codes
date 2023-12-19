#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

//Middle of the Linked List
//(brute force) TC -> O(3n/2)
ListNode* findMiddle1(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i<cnt/2;i++){
            temp = temp->next;
        }
        return temp;
    }
//(Optimal Solution) TC -> O(n/2)
ListNode* findMiddle2(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
//Reverse a LinkedList [Iterative]
ListNode* reverseList1(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while(curr!=nullptr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
//Reverse a LL [Recursive]
ListNode* reverseList2(ListNode* head) {
       if(head==nullptr || head->next==nullptr){
        return head;
       }
       ListNode* newhead = reverseList2(head->next);
       ListNode* nexthead = head->next;
       nexthead->next = head;
       head->next = nullptr;
       return newhead;
    }
//Linked List Cycle 
//(brute force) TC -> O(n) SC -> O(n)
bool hasCycle1(ListNode *head) {
    unordered_set<ListNode*> visited;

    while (head != nullptr) {
        // If the current node is already in the set, there is a cycle
        if (visited.count(head) > 0) {
            return true;
        }

        // Otherwise, add the current node to the set and move to the next node
        visited.insert(head);
        head = head->next;
    }

    // If the loop completes, there is no cycle
    return false;

    }
//(Optimal Solution) TC -> O(n) SC -> O(1)
bool hasCycle2(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
    }
//Find the starting point in LL
//(brute force) TC -> O(n) SC -> O(n)
ListNode *detectCycle1(ListNode *head) {
    unordered_set<ListNode*> visited;

    while (head != nullptr) {
        // If the current node is already in the set, there is a cycle
        if (visited.count(head) > 0) {
            return head;
        }

        // Otherwise, add the current node to the set and move to the next node
        visited.insert(head);
        head = head->next;
    }

    // If the loop completes, there is no cycle
    return nullptr;
    }
//(Optimal Solution) TC -> O(n) SC -> O(1)
ListNode *detectCycle2(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* entry = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(slow!=entry){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
    }
//Find length of Loop
int lengthOfLoop(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            slow = slow->next;
            while(slow!=fast){
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }
    return 0;
}
//Check if LL is palindrome or not TC -> O(3n/2) SC -> O(1)
ListNode *reverseList(ListNode* head){
        ListNode *prev = nullptr, *next = nullptr;
        while(head!=nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse the second half of the list
        slow->next = reverseList(slow->next);
        slow = slow->next;

        // Compare values of the first half and the reversed second half
        while (slow != nullptr) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }

        return true;
    
    }
//Segrregate odd and even nodes in LL
ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = even;
        while(odd->next != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        if(odd->next == nullptr){
            even->next = nullptr;
        }
        return head;
    }
//Remove Nth Node From End of List
//(brute force) TC -> O(2n) SC -> O(1)
ListNode* removeNthFromEnd1(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return head;
        }

        // First pass: Count the total number of nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // If n is greater than the length of the list, do nothing
        if (n > count) {
            return head;
        }

        // Calculate the position of the node to be removed
        int position = count - n;

        // Second pass: Traverse the list to find the node before the one to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < position; ++i) {
            prev = prev->next;
        }

        // Remove the nth node from the end
        ListNode* toRemove = prev->next;
        prev->next = toRemove->next;
        delete toRemove;

        // Get the new head
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
//(Optimal Solution) TC -> O(n) SC -> O(1)
ListNode* removeNthFromEnd2(ListNode* head, int n) {
     ListNode *start = new ListNode(0);
     start->next = head;
     ListNode *slow = start;
     ListNode *fast = start;

     for(int i=1;i<=n;i++){
         fast = fast->next;
     }

     while(fast->next != nullptr){
         fast = fast->next;
         slow = slow->next;
     }
     
     slow->next = slow->next->next;

     return start->next;
    }
//Delete the middle node of LL
ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;

        return head;
    }
//Sort List
//(brute force) TC -> O(2n + nlogn) SC -> O(n)
ListNode* sortList0(ListNode* head) {
        vector<int> data;
        ListNode* temp = head;
        while(temp!=nullptr){
            data.push_back(temp->val);
            temp = temp->next;
        }
        sort(data.begin(),data.end());

        temp = head;
        for(int i=0;i<data.size();i++){
            temp->val = data[i];
            temp = temp->next;
        }

        return head;
    }
//MergeSort Function O(n*logn)
ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
    }
//Intersection of Two Linked Lists
//(brute force) TC -> O(n+m) SC -> O(n)
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
       unordered_set<ListNode*> st;
       ListNode *currA = headA;
       while(currA != nullptr){
           st.insert(currA);
           currA = currA -> next;
       } 
       ListNode *currB = headB;
       while(currB != nullptr){
           if(st.find(currB) != st.end()){
               return currB;
           }
           currB = currB->next;
       }
       return nullptr;
    }
//(Optimal Solution) TC -> O(2n) SC -> O(1)
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
       if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = a == nullptr ? headB:a->next;
            b = b == nullptr ? headA:b->next;
        }

        return a;
    }
//Add one to a number represented as Linked List
ListNode *reverse(ListNode *head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *addOne(ListNode *head)
{
    head = reverse(head);

    ListNode *curr = head;
    ListNode *prev = head;
    int sum = curr->val + 1;
    curr->val = sum%10;
    int carry = sum/10;

    curr = curr->next;

    while(curr!=NULL){
        sum = curr->val + carry;
        curr->val = sum%10;
        carry = sum/10;
        prev = curr;
        curr = curr->next;
    }

    if(carry != 0){
        prev->next = new ListNode(carry);
    }
    
    head = reverse(head);

    return head;
}
//Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        int carry = 0;
        while(l1 != nullptr || l2 || nullptr || carry){
            int sum = 0;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
//Reverse Nodes in k-Group
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy, *nex = dummy, *pre = dummy;

        int cnt = 0;
        while(curr->next != nullptr){
            curr = curr->next;
            cnt++;
        }

        while(cnt >= k){
            curr = pre->next;
            nex = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            cnt -= k;
        }
        return dummy->next;
    }
//Rotate List
ListNode* rotateRight(ListNode* &head, int k) {
      if(!head || !head->next || k==0) return head;
      ListNode *curr = head, *prev = head;
      int len = 1;
      while(curr->next != nullptr){
          curr = curr->next;
          len++;
      }
      curr->next = head;
      k = k%len;
      k = len-k;
      while(k--) curr = curr->next;
      head = curr->next;
      curr->next = nullptr;

      return head;
    }
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    std::cout << "Original List: ";
    printList(head);

    head = reverseList2(head);

    std::cout << "Reversed List: ";
    printList(head);

    oddEvenList(head);

    std::cout << "OddEven List: ";
    printList(head);

    removeNthFromEnd2(head, 3);

    std::cout << "List after removing 3rd from last: ";
    printList(head);

    ListNode* middleNode = findMiddle2(head);
    std::cout << "Middle Node: " << middleNode->val << "\n";

    deleteMiddle(head);

    std::cout << "After deleting middle node: ";
    printList(head);

    head = sortList(head);

    std::cout << "Sorted List: ";
    printList(head);

    addOne(head);

    std::cout << "After adding one: ";
    printList(head);

    head = reverseKGroup(head,3);

    std::cout << "After reversing in group of 3: ";
    printList(head);

    rotateRight(head,3);

    std::cout << "After rotating by 3: ";
    printList(head);

    cout<<hasCycle2(head);

    return 0;
}