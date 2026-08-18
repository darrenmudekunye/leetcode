#include <vector>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {      
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };




ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode* node1 = l1;
	ListNode* node2 = l2;
	ListNode* node3 = new ListNode(0);
	ListNode* head = node3;
	int carry = 0;
	int digit = 0;
	while (node1 || node2 || (carry != 0)){
		if (node1 != nullptr && node2 != nullptr){
			digit = (node1->val + carry + node2->val) % 10;
			(node1->val + carry + node2->val) > 9 ? carry = 1 : carry = 0;
			node1 = node1->next;
			node2 = node2->next;
		} else if(node1){
	
			digit = (node1->val + carry) % 10;
			(node1->val + carry) > 9 ? carry = 1 : carry = 0;
			node1 = node1->next;
			

		} else  if(node2){

			digit = (carry + node2->val) % 10;
			(node2->val + carry) > 9 ? carry = 1 : carry = 0;
			node2 = node2->next;

		} else{
			digit = carry;
			carry = 0;
		}

	
		node3->next = new ListNode(digit);
		node3 = node3->next;
			
	}

	return head->next;


}

int main(){
	ListNode *n1 = new ListNode(2);
	n1->next = new ListNode(4);
	n1->next->next = new ListNode(3);
	
	ListNode *n2 = new ListNode(5);
	n2->next = new ListNode(6);
	n2->next->next = new ListNode(4);

	ListNode* n3 = addTwoNumbers(n1, n2);
	cout << n3->val << n3->next->val << n3->next->next->val << endl;
	return 0;

}
