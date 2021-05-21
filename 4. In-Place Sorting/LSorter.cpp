#include <algorithm>
#include <iostream>
#include "LSorter.h"

using namespace std;

LNode* LSorter::sortList(LNode* head){
    // Size of list
    int total_size = 1; 
    
    // Number of mergeSorts executed
    int count = 0;

    // Size of first half
    int first_size;
    
    // Size of second half
    int second_size;

    LNode *end;
    LNode *left;
    LNode *right;
    LNode *next;

    // If the list has 0 or 1 elements, return the list
    if(head == NULL || head->next == NULL){
        return head;
    }

    while(count == 0 || count > 2){    //if program doesn't enter second loop-- list sorted
        count = 1;
        left = head;
        end = NULL;
        head = NULL;

        while(left != NULL){   //loop through array until end
            right = left;
            second_size = total_size;
            first_size = 0;
            count++;    //keep track of number of Merge Sorts

            // Change right LNode and size of first half of list to split list
            while(right != NULL && first_size < total_size){ 
                first_size++;
                right = right->next;
            }

            // Move through both first list and second list, changing next LNode based on sorting conditions
            while((second_size > 0 && right != NULL) || first_size > 0){    
                
                // If first half empty, use next right value
                if(first_size == 0){   
                    next = right;
                    right = right->next;
                    second_size--;
                }
                // If second half empty, use next left value
                else if(second_size == 0 || right == NULL){     
                    next = left;
                    left = left->next;
                    first_size--;
                }
                // Compare actual values of the LNodes
                else if(right->val > left->val){   
                    next = left;
                    left = left->next;
                    first_size--;
                }
                // Move through
                else{   
                    next = right;
                    right = right->next;
                    second_size--;
                }

                // Update class variables of end
                if(end != NULL){   
                    end->next = next;
                }
                else{
                    head = next;
                }

                // Keep track of end of list by setting to next value
                end = next;
            }

            // Set values for next iteration of mergesort
            left = right;

        }

        // When finished, set pointer to next value to NULL and update size of list
        end->next = NULL;
        total_size = total_size * 2;

    }

    return head;
}
