//
//  main.cpp
//  DSOJ1-2
//
//  Created by Jihong Tang on 2019/3/18.
//  Copyright © 2019 Jihong Tang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
    LinkNode(LinkNode *ptr = NULL){next = ptr;}
    LinkNode(const int& item, LinkNode *ptr = NULL){
        data = item; next = ptr;
    }
};

class List{
private:
    LinkNode *head;
public:
    List();
    List(const int& x);
    List(List& L);
    ~List();
    void makeEmpty();
    int LinkLength()const;
    void inputEnd();
    LinkNode *getHead()const{
        return head;
    };
    LinkNode *Locate(int i);
    bool getData(int i, int& x);
    bool insert(int i, int& data);
    void output();
    List& operator = (List& L);
    
};

List::List(){
    head = new LinkNode;
}

List::List(const int& x){
    head = new LinkNode;
    head -> data = x;
}

List::List(List& L){
    int value;
    LinkNode *srcptr = L.getHead();
    LinkNode *destptr = head = new LinkNode;
    while(srcptr -> next != NULL){
        value = srcptr -> next -> data;
        destptr -> next = new LinkNode;
        destptr -> next -> data = value;
        destptr = destptr -> next;
        srcptr = srcptr -> next;
    }
    destptr -> next = NULL;
}

List::~List(){
    makeEmpty();
}

void List::makeEmpty(){
    LinkNode *q;
    while(head -> next != NULL){
        q = head -> next;
        head -> next = q -> next;
        delete q;
    }
}

int List::LinkLength()const{
    LinkNode *p = head -> next;
    int count = 0;
    while(p != NULL){
        p = p-> next;
        count++;
    }
    return count;
}

void List::inputEnd(){
    LinkNode *newNode, *tail;
    makeEmpty();
    tail = head;
    int val;
//    cin >> val;
    while(cin >> val){
        newNode = new LinkNode;
        newNode -> data = val;
        newNode -> next = NULL;
        tail -> next = newNode;
        tail = newNode;
        char c = getchar();
        if (c == '\n') break;
//        cin >> val;
    }
}

LinkNode *List::Locate(int i){
    if (i < 0) return NULL;
    LinkNode *current = head;
    int k = 0;
    while(current != NULL && k < i){
        current = current -> next;
        k++;
    }
    return current;
}

bool List::getData(int i, int& x){
    if (i < 0) return false;
    LinkNode *current = Locate(i);
    if(current == NULL) return false;
    else {
        x = current -> data;
        return true;
    }
}

bool List::insert(int i, int& data){
    LinkNode *current = Locate(i);
    if(current == NULL) return false;
    LinkNode *newNode = new LinkNode;
    newNode -> data = data;
    newNode -> next = current -> next;
    current -> next = newNode;
    return true;
}

void List::output(){
    LinkNode *current = head -> next;
    while (current -> next != NULL){
        cout << current -> data << ' ';
        current = current -> next;
    }
    cout << current -> data;
}

List& List::operator=(List& L){
    int value;
    LinkNode *srcptr = L.getHead();
    LinkNode *destptr = head = new LinkNode;
    while(srcptr -> next != NULL){
        value = srcptr -> next -> data;
        destptr -> next = new LinkNode;
        destptr -> next -> data = value;
        destptr = destptr -> next;
        srcptr = srcptr -> next;
    }
    destptr -> next = NULL;
    return *this;
}

int main(){
    List input_list;
    List odd_list;
    List even_list;
    
    int odd_index = 0;
    int even_index = 0;
//    cout << "Please input the list"<< endl;
    input_list.inputEnd();
//    input_list.output();
    for (int i = 1; i <= input_list.LinkLength(); i++){
        int data = 0;
        input_list.getData(i, data);
        if (data % 2 == 1){
            odd_list.insert(odd_index, data);
            odd_index ++;
        }
        else{
            even_list.insert(even_index, data);
            even_index ++;
        }
    }


//    cout << odd_list.LinkLength();
    odd_list.output();
    cout << endl;
    even_list.output();
    cout << endl;
    
    input_list.output();
    cout << endl;
    return 0;
}
