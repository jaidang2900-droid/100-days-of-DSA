struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int stack1[1000], stack2[1000];
    int top1 = -1, top2 = -1;
    
    while (l1) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    while (l2) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* result = NULL;
    
    while (top1 >= 0 || top2 >= 0 || carry) {
        
        int sum = carry;
        
        if (top1 >= 0) sum += stack1[top1--];
        if (top2 >= 0) sum += stack2[top2--];
        
        carry = sum / 10;
        
        struct ListNode* newNode = 
            (struct ListNode*)malloc(sizeof(struct ListNode));
        
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}