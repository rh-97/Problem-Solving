// Single pass
// O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node *node = head;
        
        while (node) {
            
            if (node->child) {
                
                Node *temp = node->child;
                while (temp->next) temp = temp->next;
                
              // Connecting node->next and tail of the chld branch
                if (node->next) node->next->prev = temp;
                temp->next = node->next;
                
              // Connecting node and child
                node->child->prev = node;
                node->next = node->child;
                node->child = nullptr;
                
            }
            
            node = node->next;
            
        }
        
        return head;
    
    }
    
};


