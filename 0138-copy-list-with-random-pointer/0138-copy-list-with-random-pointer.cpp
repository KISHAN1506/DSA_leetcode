/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // 1. insert the copy nodes in between 
    // 2. Connect the random pointers
    // 3. Connect the next pointers
    // 4. make all the 2 linked list free from each other
    Node* copyRandomList(Node* head) {
        // 1. insert the copy nodes in between 
        Node* temp = head;
        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next ? temp->next : NULL;
            temp->next = newNode;

            temp = temp->next->next;
        }

        // 2. Connect the random pointers
        // idhar random pointers connect hogya
        temp = head;

        while(temp != nullptr){
            Node* copyNode = temp->next;
            copyNode->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        // 3. Connect the next pointers -> next baadme hi connect hoga while removing connections
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        temp = head;

        while(temp != NULL){
            res->next = temp->next;

            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};