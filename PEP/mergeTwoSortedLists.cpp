#include<iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x){
		val = x;
		next = nullptr;
	} 
	ListNode(int x, ListNode *next){
		val = x;
		next = next
	}
};

	void print(ListNode *head){
		while(head != NULL){
			cout<<head->data<<" ";
			head = head->next;
		}
	}

	void insertAtHead(ListNode* &head, int data){
		ListNode *nodeToInsert = new ListNode(data);
		nodeToInsert->next = head;
		head = nodeToInsert;
	}

	void deleteList(ListNode* &head) {
	    while (head != nullptr) {
	        ListNode* nextNode = head->next;
	        delete head;
	        head = nextNode;
	    }
	}

class Solution {
public:
	void merge(ListNode *list1, ListNode *list2){

	}

	ListNode mergeTwoSortedLists(ListNode *list1, ListNode *list2){
		if(list1 == nulptr){
			return list2;
		}
		if(list2 == nullptr){
			return list1;
		}

		if(list1->val < list2->val){
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		} else {
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
};

int main(){
	ListNode list1();
	ListNode list2();

	insertAtHead(list1, 19);
	insertAtHead(list1, 21);
	insertAtHead(list1, 9);
	insertAtHead(list1, 23);
	insertAtHead(list1, 3);

	insertAtHead(list2, 6);
	insertAtHead(list2, 1);
	insertAtHead(list2, 97);
	insertAtHead(list2, 53);
	insertAtHead(list2, 31);

	Solution s;
	s.mergeTwoSortedLists(list1, list2);

	deleteList(list1);
	deleteList(list2);
	return 0;
}