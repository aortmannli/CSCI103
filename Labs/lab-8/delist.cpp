#include "delist.h"

DEList::DEList(){
  head = NULL;
  tail = NULL;
  len = 0;
}

// Destructor to clean-up memory of current list
DEList::~DEList(){
  while (len != 0) {
    pop_back();
  }
}

// returns a Boolean 'true' if the list is empty
bool DEList::empty(){
  return len == 0;
}

// returns number of items in the list
int DEList::size(){
  return len;
}

// returns front item or -1 if empty list
int DEList::front(){
  if (len > 0){
    return head->val;
  }
  return -1;
}

// returns back item or -1 if empty list
int DEList::back(){
  if (len > 0){
    return tail->val;
  }
  return -1;
}

// Adds a new integer to the front of the list
void DEList::push_front(int new_val){
  DEItem * newItem = new DEItem;
  
  newItem->val = new_val;
  newItem->prev = NULL;
  
  if (len == 0){
    head = newItem;
    tail = newItem;
    newItem->next = NULL;
  }else{
    newItem->next = head;
    head->prev = newItem;
    head = newItem;
  }
  
  len++;
}

// Adds a new integer to the back of the list
void DEList::push_back(int new_val){
  DEItem * newItem = new DEItem;
  
  newItem->val = new_val;
  newItem->next = NULL;
  
  if (len == 0){
    head = newItem;
    tail = newItem;
    newItem->prev = NULL;
  }else{
    newItem->prev = tail;
    tail->next = newItem;
    tail = newItem;
  }
  
  len++;
}

// Removes the front item of the list (if it exists)
void DEList::pop_front(){
  if (len == 0){
    return;
  }if (len > 1){
    DEItem * temp = head->next;
    temp->prev = NULL;
    delete head;
    head = temp;
  }else{
    delete head;
    head = NULL;
    tail = NULL;
  }
  
  len--;
}

// Removes the back item of the list (if it exists)
void DEList::pop_back(){
  if (len == 0){
    return;
  }else if (len > 1){
    DEItem * temp = tail->prev;
    temp->next = NULL;
    delete tail;
    tail = temp;
  }else{
    delete tail;
    head = NULL;
    tail = NULL;
  }
  
  len--;
}