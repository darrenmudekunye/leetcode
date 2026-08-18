#include <iostream>
/*
 * This implementation converts each linked list into an integer first
 * then proceeds to add them.
 *
 * It's weakness is adding number that exceed the data type size (thanks for the 1x10^26 integer, leetcode)
 * 
 * */
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {} };

int add(ListNode*);
int addTwoNumbers(ListNode* l1, ListNode* l2) {
	return add(l1) + add(l2);  
	}

int add(ListNode* ll1){
    int sum = 0;
    double power = 1;
    ListNode *currentNode = ll1;
    while (currentNode != nullptr){
        sum += (currentNode -> val) * power;
        currentNode = currentNode -> next;
        power *= 10;
    }
    return sum;
}

int main(){

      struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {} };
      
      ListNode n1 = ListNode(2);
      n1.next = new ListNode(4);
      n1.next->next = new ListNode(3);

      cout << n1.val << "   "<< n1.next->val << endl;
      

}

