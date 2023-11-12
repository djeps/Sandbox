#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Create the node structure for each element in the linked list
struct Node
{
    int val;
    struct Node* nextNode;
};

int main(void)
{
    // Create two pointers that will be used to search the linked list and add or delete nodes
    struct Node* currNode;
    struct Node* prevNode;

    // Create a variable that will be used as a flag to denote that the search found a node that 
    // we were looking for
    uint8_t nodeFound;

    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if the heap allocation failed. Otherwise it makes no sense to process further
    if ( (NULL == headNode) || (NULL == node2) || (NULL == node3) || (NULL == node4) || (NULL == newNode) ) {
        printf("ERR: Could NOT allocate memory on the heap for the list's node elements!\n");
        return -1;
    }
    
    // Initialize all nodes and setup the list
    headNode->val = 1;
    headNode->nextNode = node2;

    node2->val = 2;
    node2->nextNode = node3;

    node3->val = 3;
    node3->nextNode = node4;

    node4->val = 5;
    node4->nextNode = NULL;

    // At this point, we have a list!
    // The 'newNode' isn't placed in it yet.
    newNode->val = 4;

    // Initialize the node iterators. They both point to the beginning of the list.
    currNode = headNode;
    prevNode = headNode;
    nodeFound = 0;

    while( NULL != prevNode->nextNode )
    {
        if ( newNode->val <= currNode->val )
        {
            nodeFound = 1;
            newNode->nextNode = currNode;

            if ( currNode != headNode ) {
                prevNode->nextNode = newNode;
            }
            else {
                struct Node* tmpNode = headNode;
                headNode = newNode;
                newNode = tmpNode;
            }

            break;
        }

        prevNode = currNode;
        currNode = currNode->nextNode;
    }

    if ( !nodeFound ) {
        prevNode->nextNode = newNode;
        newNode->nextNode = NULL;
    }

    (void)free(headNode);
    (void)free(node2);
    (void)free(node3);
    (void)free(node4);
    (void)free(newNode);

    return 0;
}