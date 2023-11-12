/* MPLABX 2.45
 * XC32 v2.50
 * DFP 1.3.231
 * 
 * Denny Hopp
*/

#include <xc.h>
#include <stdio.h>
#include <stddef.h>

// Create the node structure for each element in the linked list
struct Node
{
    int val;
    struct Node* nextNode;
};

// Create two pointers that will be used to search the linked list and add or delete nodes
struct Node* currNode;
struct Node* prevNode;

// Create a variable that will be used as a flag to denote that the search found a node that 
// we were looking for
uint8_t nodeFound;

void main(void) 
{
    // Create structure pointer to four instanced of nodes in the linked list.  The only required 
    // nodes to be created are "headNode" to signify the first node in the linked list and "newNode" 
    // that will be used to manipulate the items in the list.  The "secondNode" and "thirdNode" 
    // are created just for demonstration purposes to allow for some initial created nodes and make 
    // it easier to understand the linked list concept.    
     
    // Allocate 4 nodes in the heap 
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* secondNode = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* thirdNode = (struct Node*)malloc(sizeof(struct Node));   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if the heap allocation failed. Otherwise it makes no sense to process further
    if ( (NULL == headNode) || (NULL == secondNode) || (NULL == thirdNode) || (NULL == newNode) ) {
        return;
    }
    
    // Initialize all nodes and setup the list
    headNode->val = 2;
    headNode->nextNode = secondNode;

    secondNode->val = 3;
    secondNode->nextNode = thirdNode;

    thirdNode->val = 5;
    thirdNode->nextNode = NULL;

    // At this point, we have a list!
    // The 'newNode' isn't placed in it yet.
    newNode->val = 4;

    // Initialize the node iterators. They both point to the beginning of the list.
    currNode = headNode;
    prevNode = headNode;
    nodeFound = 0;

    // Add the 'new node' in numerical order in the linked list.
    // Step through the linked list and search for the position to place the newNode value of 4 
    // so that the list stays in numerical order.

    // The algorithm looks at the value in the location of the 'currNode' and compares it to the
    // value in newNode. If it is less than the value, the iteration of this search stops.  
    // 'prevNode' is set equal to 'currNode' and 'currNode' is set equal to the location pointed
    // to by the 'nextNode' value in that location. So this algorithm just steps through the list.
    // If the 'currNode' value is greater than the 'newNode' value, then the 'newNode' value will
    // be placed before the 'currNode'. Since prevNode points to the location before the 'currNode',
    // the 'nextNode' value of the 'prevNode' is set equal to the 'newNode' pointer. The 'newNode'\
    // pointer is set to point to the currNode location.

    // For each iteration of the loop, the 'prevNode' is set equal to the 'currNode' and the 'currNode'
    // is incremented.  So there are pointers to the current node and previous node at all times!

    // If the value to be placed is less than the first location in the list, the 'newNode' pointer 
    // is set to be the headNode. If the value to be placed is greater than the last location, this
    // search will fall through without placing the node in the list. 'nodeFound' is used to signify
    // that a node was placed. If this value is 0, then the prevNode is set to point to the 'newNode'
    // and the 'newNode' pointer is set to NULL.
    
    // Insert a new node in ascending order
    while( NULL != prevNode->nextNode )
    {
        if( (newNode->val) < (currNode->val) )
        {
            nodeFound = 1;
            newNode->nextNode = currNode;
            
            if( currNode != headNode ) {
                prevNode->nextNode = newNode;
            }
            else {
                headNode = newNode;
            }
            
            break;
        }

        prevNode = currNode;        
        currNode = currNode->nextNode;
    } 

    // Check if a node was found. If not, put the value at the end of the list    
    if( !nodeFound )
    {
        prevNode->nextNode = newNode;
        newNode->nextNode = NULL;        
        nodeFound = 0;
    }
     
    // Delete the node with a value of 3.
    // This search is very similar to the previous search. When the node value is found, the 
    // 'prevNode' is set to point to the value pointed by 'currNode'. Then the free() function call
    // is used to deallocate the memory that currNode was pointing to. If the node to be deleted is
    // the head node, then the 'headNode' is set equal to the location pointed to by the current
    // head node. If the location is pointing to NULL, then it must be the last node, so the 'prevNode'
    // is set to point to NULL since it will now be the last node.
    currNode = headNode;
    prevNode = headNode;
    
    while( NULL != prevNode->nextNode )
    {
        if( 3 == currNode->val )
        {
            if( currNode == headNode ) {
                headNode = currNode->nextNode;
            }
            else if( NULL == currNode->nextNode ) {
                prevNode->nextNode = NULL;
            }
            else {
                prevNode->nextNode = currNode->nextNode;
            }
            
            free(currNode);
            break;
        }

        prevNode = currNode;        
        currNode = currNode->nextNode;
    }
}
