

typedef struct stacknode{
    int val;
    struct stacknode* next;
}MinStackNode;

typedef struct {
    MinStackNode* head; //top element
    MinStackNode* min; //min element
} MinStack;


MinStack* minStackCreate() {
    MinStack* p;
    p = (MinStack*) malloc(sizeof(MinStack));
    p->head = NULL;
    p->min = NULL;

    return p;
}

void minStackPush(MinStack* obj, int val) {
    MinStackNode* ptr;
    ptr = (MinStackNode*) malloc(sizeof(MinStackNode));

    ptr->val = val;
    ptr->next = obj->head;

    if(obj->min == NULL){
        obj->min = ptr;
    }
    else if(obj->min->val > ptr->val){
        obj->min = ptr;
    }

    obj->head = ptr;

}

void minStackPop(MinStack* obj) {
    MinStackNode* trav;
    trav = obj->head;
    if(obj->head != NULL){
        obj->head = trav->next;
    }
    if(trav == obj->min && trav != NULL){ 
        MinStackNode* trav2 = trav->next;
        obj->min = trav2;
        while(trav2 != NULL){
            if(trav2->val < obj->min->val){
                obj->min = trav2;
            }
            trav2 = trav2->next;
        }
    }

    free(trav);
}

int minStackTop(MinStack* obj) {
        return obj->head->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->min->val;
}

void minStackFree(MinStack* obj) {
    MinStackNode* curr;
    curr = obj->head;
    while(curr != NULL){
        MinStackNode* trav;
        trav = curr;
        curr = trav->next;
        free(trav);
    }

    obj->head = NULL;
    obj->min = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * MinStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/