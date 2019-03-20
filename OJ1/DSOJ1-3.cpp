//
//  main.cpp
//  DSOJ1-3
//
//  Created by Jihong Tang on 2019/3/20.
//  Copyright © 2019 Jihong Tang. All rights reserved.
//

#include <iostream>
using namespace std;

template <class Eletype>
struct DblLinkNode{
    Eletype data;
    int freq;
    DblLinkNode<Eletype>* next;
    DblLinkNode<Eletype>* prev;
    
    DblLinkNode(DblLinkNode<Eletype> *left = NULL, DblLinkNode<Eletype> *right = NULL)
    :prev(left), next(right) {}
    DblLinkNode(Eletype value, DblLinkNode<Eletype> *left = NULL, DblLinkNode<Eletype> *right = NULL)
    :data(value), prev(left), next(right){}
};

template <class Eletype>
class DblList{
public:
    DblList();
    DblList(DblList& L);
    ~DblList();
    void makeEmpty();
    int LinkLength()const;
    void inputEnd();
    DblLinkNode<Eletype> *getHead()const{
        return head;
    };
    bool LOCATE(Eletype x);
    DblLinkNode<Eletype> *Locate(int i);
    bool getData(int i, Eletype& x);
    void output();
private:
    DblLinkNode<Eletype> *head;
};

template <class Eletype>
DblList<Eletype>::DblList(){
    head = new DblLinkNode<Eletype>;
}

template <class Eletype>
DblList<Eletype>::DblList(DblList<Eletype>& L){
    Eletype value;
    int frequence;
    DblLinkNode<Eletype> *srcptr = L.getHead();
    DblLinkNode<Eletype> *destptr = head = new DblLinkNode<Eletype>;
    while(srcptr -> next != NULL){
        value = srcptr -> next -> data;
        frequence = srcptr -> next -> freq;
        destptr -> next = new DblLinkNode<Eletype>;
        destptr -> next -> data = value;
        destptr -> next -> freq = frequence;
        destptr -> next -> prev = destptr;
        destptr = destptr -> next;
        srcptr = srcptr -> next;
    }
    destptr -> next = NULL;
}

template <class Eletype>
DblList<Eletype>::~DblList(){
    makeEmpty();
}

template <class Eletype>
void DblList<Eletype>::makeEmpty(){
    DblLinkNode<Eletype> *current;
    while(head -> next != NULL){
        current = head -> next;
        head -> next = current -> next;
        delete current;
    }
}

template <class Eletype>
int DblList<Eletype>::LinkLength()const{
    DblLinkNode<Eletype> *p = head -> next;
    int count = 0;
    while(p != NULL){
        p = p-> next;
        count++;
    }
    return count;
}

template <class Eletype>
void DblList<Eletype>::inputEnd(){
    DblLinkNode<Eletype> *newNode, *tail;
    makeEmpty();
    tail = head;
    Eletype val;
    //    std::cin >> val;
    while(std::cin >> val){
        newNode = new DblLinkNode<Eletype>;
        newNode -> data = val;
        newNode -> freq = 0;
        newNode -> next = tail -> next;
        tail -> next = newNode;
        //        newNode -> next -> prev = newNode;
        newNode -> prev = tail;
        tail = newNode;
        char c = getchar();
        if (c == '\n') break;
        //        std::cin >> val;
    }
}

template <class Eletype>
bool DblList<Eletype>::LOCATE(Eletype x){
    DblLinkNode<Eletype> *n_move = head -> next;
    DblLinkNode<Eletype> *p_move;
    
    while(n_move != NULL && n_move -> data != x){
        n_move = n_move -> next;
    }
    if (n_move == NULL){
        return false;
    }
    else{
        n_move -> freq ++;
        p_move = n_move -> prev;
        while(p_move != head && p_move -> freq < n_move -> freq){
            p_move = p_move -> prev;
        }
        if (p_move -> next != n_move){
            if (n_move -> next == NULL){
                n_move -> prev -> next = NULL;
            }else{
                n_move -> next -> prev = n_move -> prev;
                n_move -> prev -> next = n_move -> next;
            }
            
            n_move -> prev = p_move;
            n_move -> next = p_move -> next;
            p_move -> next -> prev = n_move;
            p_move -> next = n_move;
            return true;
        }
        else{
            return false;
        }
    }
}

template <class Eletype>
DblLinkNode<Eletype> *DblList<Eletype>::Locate(int i){
    if (i < 0) return NULL;
    DblLinkNode<Eletype> *current = head;
    int k = 0;
    while(current != NULL && k < i){
        current = current -> next;
        k++;
    }
    return current;
}

template <class Eletype>
bool DblList<Eletype>::getData(int i, Eletype& x){
    if (i < 0) return false;
    DblLinkNode<Eletype> *current = Locate(i);
    if(current == NULL) return false;
    else {
        x = current -> data;
        return true;
    }
}

template <class Eletype>
void DblList<Eletype>::output(){
    DblLinkNode<Eletype> *current = head -> next;
    while (current != NULL){
        std::cout << current -> data << ' ';
        current = current -> next;
    }
}


int main() {
    
    DblList<int> origin_list;
    DblList<int> locate_list;
    
//    cout << "Please input the lists"<< endl;
    origin_list.inputEnd();
    locate_list.inputEnd();
    
    for (int i = 1; i <= locate_list.LinkLength(); i++){
        int data;
        locate_list.getData(i, data);
        origin_list.LOCATE(data);
    }
    origin_list.output();
    cout << endl;
    return 0;
}
