//Very simple code, it's a merge sort implementation


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* out = new ListNode(0);
        ListNode* head = out;
        while (l1 && l2){
            if (l1->val <= l2->val){
                out->next = new ListNode(l1->val);
                out = out->next;
                l1 = l1->next;
            }else{
                out->next = new ListNode(l2->val);
                l2 = l2->next;
                out = out->next;
            }
        }

        while (l1){
            out->next = new ListNode(l1->val);
            out = out->next;
            l1 = l1->next;
        }

        while (l2){
            out->next = new ListNode(l2->val);
            out = out->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

int main(){
	return 0;
}
