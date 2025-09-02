struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }

    // Step 1: Find length and last node
    int count = 1;
    struct ListNode *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
        count++;
    }

    // Step 2: Make it circular
    curr->next = head;

    // Step 3: Adjust k
    k = k % count;
    k = count - k;

    // Step 4: Move to new head
    for(int i=0; i<k; i++){
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;  // break circle

    return head;
}
