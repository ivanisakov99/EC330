#include <algorithm>
#include "LSorter.h"
using namespace std;

int SizeOfLinkedList(struct LNode* current){ 
    int count = 0; 
    while (current != NULL) { 
        current = current->next; 
        count++; 
    } 
    return count; 
} 
  

void Merge(struct LNode** head1, struct LNode** tail1, struct LNode** head2, struct LNode** tail2){ 

    struct LNode* temp = NULL; 
    if ((*head1)->val > (*head2)->val) { 
        swap(*head1, *head2); 

        swap(*tail1, *tail2); 
    } 

    struct LNode* headA = *head1, *tailA = *tail1; 
    struct LNode* headB = *head2, *tailB = *tail2; 
    struct LNode* tailB_next = (*tail2)->next; 
    while (headA != tailA && headB != tailB_next){ 

        if (headA->next->val > headB->val) { 
            temp = headB->next; 

            headB->next = headA->next; 

            headA->next = headB; 
            
            headB = temp; 
        } 
        headA = headA->next; 
    } 
    if (headA == tailA){
        headA->next = headB; 
    }else{
        *tail2 = *tail1; 
    }
} 
  

void MergeSort(struct LNode** head){ 
    if (*head == NULL){
        return; 
    }else{
        struct LNode* head1 = NULL, *tail1 = NULL; 
        struct LNode* head2 = NULL, *tail2 = NULL; 
        struct LNode* p = NULL; 
        int length = SizeOfLinkedList(*head); 
  
        for (int i = 1; i < length; i = i*2){ 
            head1 = *head; 
            while (head1){ 
  
                bool first_iteration = 0; 
                
                if (head1 == *head){
                    first_iteration = 1; 
                }
  
                int counter = i; 
                tail1 = head1; 
                while (--counter && tail1->next){
                    tail1 = tail1->next; 
                }

                head2 = tail1->next; 
                if (!head2){
                    break; 
                }
                counter = i; 
                tail2 = head2; 
                while (--counter && tail2->next){
                    tail2 = tail2->next; 
                }
  
                LNode *temp = tail2->next; 

                Merge(&head1, &tail1, &head2, &tail2); 

                if (first_iteration){
                    *head = head1; 
                }else{
                    p->next = head1; 
                }
  
                p = tail2; 
                head1 = temp; 
            } 
            p->next = head1; 
        } 
    }
} 
LNode* LSorter::sortList(LNode* head){
        MergeSort(&head);
        LNode* ans = head;
        return ans;
    
}
/*
#include "LSorter.h"
#include "LNode.h"
#include <iostream>

LNode* LSorter::sortList(LNode* head)
{
    int size=1;//size of list
    int count = 0;//number of mergeSorts executed
    int first_size;//size of first half
    int second_size;//size of second half

    LNode *end;
    LNode *left;
    LNode *right;
    LNode *next;

    if (head == NULL || head->next == NULL){    //if the list has 0 or 1 elements, return the list
        return head;
    }

    while (count == 0 || count > 2){    //if program doesn't enter second loop-- list sorted
        count=1;
        left=head;
        end=0;
        head=0;

        while (left != NULL){   //loop through array until end
            right=left;
            second_size=size;
            first_size=0;
            count++;//keep track of number of Merge Sorts

            while (right != NULL && first_size < size){ //change right LNode and size of first half of list to split list
                first_size++;
                right=right->next;
            }

           
            while ((second_size > 0 && right != NULL) || first_size > 0){    //move through both first list and second list, changing next LNode based on sorting conditions
                if (first_size == 0){   //if first half empty, use next right value
                    next=right;
                    right=right->next;
                    second_size--;
                }
                else if (second_size == 0 || right == NULL){     //if second half empty, use next left value
                    next=left;
                    left=left->next;
                    first_size--;
                }

                

                else if (right->val > left->val){   //compare actual values of the LNodes
                    next=left;
                    left=left->next;
                    first_size--;
                }
                else{   //move through
                    next=right;
                    right=right->next;
                    second_size--;
                }

                if (end != NULL){   //update class variables of end
                    end->next=next;
                }
                else{
                    head=next;
                }

                //keep track of end of list by setting to next value
                end=next;
            }

            //set values for next iteration of mergesort
            left=right;

        }

        //when finished,set pointer to next value to NULL and update size of list
        end->next=0;
        size = size * 2;

    }

    return head;

}
*/