#ifndef _UNORDER_H
#define _UNORDER_H

#include"linklist.h"

template<class T>
class unorderlist:public linklist<T>{
public:
  bool search(const T& carid);
  void insertFirst(const T& carid);
  void insertLast(const T& carid);
  void deleteItem(const T& carid);

};
//========================================================================================

template<class T>
bool unorderlist<T>::search(const T& carid)
{
  box<T>*current;
  bool found=false;
  current=this->head;
  while(current!=NULL && !found)
  {
    if(current->carid.id== carid.id)
    {
      found=true;
    }
    else{
      current=current->next;
    }
  }
  return found;
}
template<class T>
void unorderlist<T>::insertFirst(const T& carid){
  if(search(carid)||std::cin.fail())
  {
    std::cout << "Duplicate/Invalid ID's detected\n";
  }
  else{
    box<T>*newBox;
    newBox=new box<T>;
    newBox->carid=carid;
    newBox->next=this->head;
    this->head=newBox;
    this->count++;
    if(this->tails==NULL){
      this->tails=newBox;
      this->count++;
    }
    std::cout << "Sucessfully added\n";
  }
}

template<class T>
void unorderlist<T>::insertLast(const T& carid)
{
  if(search(carid)||std::cin.fail())
  {
    std::cout << "Invalid/Duplicate ID's detected\n";
  }
  else{
    box<T>*newBox;
    newBox=new box<T>;
    newBox->carid=carid;
    newBox->next=NULL;
    if(this->head==NULL)
    {
      this->head=newBox;
      this->tails=newBox;
      this->count++;
    }
    else{
        this->tails->next=newBox;
        this->tails=newBox;
        this->count++;
    }
    std::cout << "Sucessfully added\n";
  }

}

template<class T>
void unorderlist<T>::deleteItem(const T& carid){
  box<T>*current;
  box<T>*currentrail;
  bool found;
  if(this->head==NULL){
    std::cout << "cannot delete empty file\n";
  }
  else{
    if(this->head->carid.id==carid.id)
    {
      current=this->head;
      this->head=this->head->next;
      this->count--;

      if(this->head==NULL){
        this->tails=NULL;
      }
      delete current;
    }
    else
    {
      found=false;
      currentrail=this->head;
      current=this->head->next;
      while(current!=NULL &&!found)
      {
        if(current->carid.id != carid.id)
        {
          currentrail=current;
          current=current->next;
        }
        else{
          found = true;
        }
      }
      if(found){
        currentrail->next=current->next;
        this->count--;
        if(this->tails==NULL){
          this->tails=currentrail;
        }
        delete current;
      }else{
        std::cout <<"Item not in the list\n";
      }

    }
  }
}

#endif

