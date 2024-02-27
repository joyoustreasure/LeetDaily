


struct Node {
    int val;
    struct Node *next;
};

typedef struct MyLinkedList{
    struct Node *head;

} MyLinkedList;

//helper function to create nodes
struct Node *createNode(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->val = val;
    return newNode;
}

//create list "object"
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    struct Node *current = obj->head;
    if(index == 0 && current)
        return current->val;
    else if(index == 0 && !current)
        return -1;
    else
    {
        for(int i = 0; i<index; i++)
        {
            if(current->next)
                current = current->next;
            else
                return -1;
        }
        return current->val;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj->head == NULL)
        obj->head = createNode(val);
    else
    {
        struct Node *temp = obj->head;
        obj->head = createNode(val);
        obj->head->next = temp;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct Node *current;

    //in case MyLinkedList is empty, add to head instead
    if(!obj->head)
        myLinkedListAddAtHead(obj,val);
    else
    {
        current = obj->head;
        //get to the last node
        while(current->next != NULL)
        {
            current = current->next;
        }
        //create node
        current->next = createNode(val);
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct Node *current = obj->head;
    struct Node *temp;
    //in case user adds to head
    if(index == 0)
        myLinkedListAddAtHead(obj,val);

    //get to given index
    else if(index > 0 && current)
    {
        for(int i = 1;i<index;i++)
        {
            if(current->next)
                current = current->next;
            else
                return;
        }
        //hold next node's address in temp
        temp = current->next;
        //set current node's next to new node
        current->next = createNode(val);
        //step into new node
        current = current->next;
        //set new node's next pointer to the displaced node's address
        current->next = temp;
    }
    else
        return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct Node *current = obj->head;
    struct Node *deleteNode;

    //handling the case that index points to head
   if(index == 0 && current->next)
    {
        obj->head = current->next;
        free(current);
    }
    else if(index == 0 && !current->next)
    {
        obj->head = NULL;
    }

    else if(current->next)
    {
        //get to given index
        for(int i = 1;i < index; i++)
        {
            //set current's address to the node right before
            // the node to be deleted
            //unless index doesn't exist
            if(current->next->next)
                current = current->next;
            else
                return;
        }
        //hold the address of the node to be deleted in deleteNode
        deleteNode = current->next;
        //remove the to-be-deleted node from the linked list chain
        current->next = deleteNode->next;
        //free the deleted node from the heap's memory
        free(deleteNode);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node *temp = obj->head;
    struct Node *next;
    //if there's more than just a head node
    if(temp && temp->next)
    {
        next = temp->next;
        //freeing head
        free(temp);
        while(next->next)
        {
            //set temp's pointer to next node in line
            temp = next;
            //iterate next
            next = next->next;
            //delete node
            free(temp);
        }
        //finally free tail from heap
        free(next);
    }
    else if(temp)
    {
        free(temp);
    }
    else
        return;
}


void display(MyLinkedList* obj)
{
    struct Node * current = obj->head;
    printf("Data in all linked list: ");
    if(obj->head == NULL)
    {
        printf("NULL\n");

    }
    while(current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/