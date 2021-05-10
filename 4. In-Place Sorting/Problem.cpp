#include <iostream>
#include "LNode.h"
#include "LSorter.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "---------------TEST 0-------------" << endl;
    cout << "Input: 5 1 7 13 2 9" << endl;
    LNode LNode01(5);
    LNode LNode02(1);
    LNode LNode03(7);
    LNode LNode04(13);
    LNode LNode05(2);
    LNode LNode06(9);
    
    LNode01.next = &LNode02;
    LNode02.next = &LNode03;
    LNode03.next = &LNode04;
    LNode04.next = &LNode05;
    LNode05.next = &LNode06;
    
    LSorter solution0;
    LNode* head0 = solution0.sortList(&LNode01);
    
    LNode* currnode = head0;
    cout << "Output: ";
    while (currnode != nullptr){
        cout << currnode->val << " ";
        currnode = currnode->next;
    }		
    cout << endl;

    cout << "\n\n---------------TEST 1-------------" << endl;
    cout << "Input: 5 1 7 13 2 9 9 9 9 13" << endl;
    LNode LNode11(5);
    LNode LNode12(1);
    LNode LNode13(7);
    LNode LNode14(13);
    LNode LNode15(2);
    LNode LNode16(9);
    LNode LNode17(9);
    LNode LNode18(9);
    LNode LNode19(9);
    
    LNode11.next = &LNode12;
    LNode12.next = &LNode13;
    LNode13.next = &LNode14;
    LNode14.next = &LNode15;
    LNode15.next = &LNode16;
    LNode16.next = &LNode17;
    LNode17.next = &LNode18;
    LNode18.next = &LNode19;
    
    LSorter solution1;
    LNode* head1 = solution1.sortList(&LNode11);
    
    currnode = head1;
    cout << "Output: ";
    while (currnode != nullptr){
        cout << currnode->val << " ";
        currnode = currnode->next;
    }		
    cout << endl;

    cout << "\n\n---------------TEST 2-------------" << endl;
    cout << "Input: 0" << endl;
    LNode LNode21(0);
    
    LNode21.next = NULL;
    
    LSorter solution2;
    LNode* head2 = solution2.sortList(&LNode21);
    
    currnode = head2;
    cout << "Output: ";
    while (currnode != nullptr){
        cout << currnode->val << " ";
        currnode = currnode->next;
    }		
    cout << endl;

    cout << "\n\n---------------TEST 3-------------" << endl;
    cout << "Input: -5 1 -7 13 -22 9" << endl;
    LNode LNode31(-5);
    LNode LNode32(1);
    LNode LNode33(-7);
    LNode LNode34(13);
    LNode LNode35(-22);
    LNode LNode36(9);
    
    LNode31.next = &LNode32;
    LNode32.next = &LNode33;
    LNode33.next = &LNode34;
    LNode34.next = &LNode35;
    LNode35.next = &LNode36;
    
    LSorter solution3;
    LNode* head3 = solution3.sortList(&LNode31);
    
    currnode = head3;
    cout << "Output: ";
    while (currnode != nullptr){
        cout << currnode->val << " ";
        currnode = currnode->next;
    }		
    cout << endl;

    return 0;
}