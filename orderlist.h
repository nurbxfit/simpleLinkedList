#ifndef _ORDER_H
#define _ORDER_H
#include "linklist.h"

template <class T>
class orderlist:public linklist<T>{
public:
  bool search(const T& carid);
  void insert(const T& carid);
  void insertFirst(const T& carid);
  void insertLast(const T& carid);
  void deleteItem(const T& carid);

};

//============================================================================
template<class T>
void orderlist<T>::insert(const T&car){
  if(search(car)||std::cin.fail())
  {
    std::cout << "Duplicate/Invalid ID's detected\n";
  }
  else
  {
  	box<T>*current;
  	box<T>*trailcurrent;
  	box<T>*newBox;
  	newBox=new box<T>;
  	bool found;
  	
  	newBox->carid= car;
  	newBox->next=NULL;
  	if(this->head==NULL)
  	{
  		this->head=newBox;
  		this->tails=newBox;
  		this->count++;
	}
	else
	{
		current=this->head;
		found=false;
		while(current!=NULL && !found)
		{
		
	
			if(current->carid.oTRprice >=car.oTRprice)
			{
				found = true;
			}
			else
			{
				trailcurrent=current;
				current=current->next;
				
			}
			
		}
			if(current==this->head)
			{
				newBox->next=this->head;
				this->head=newBox;
				this->count++;
			}
			else
			{
				trailcurrent->next = newBox;
				newBox->next=current;
				if(current==NULL)
				{
					//this->tails->next=newBox;
					this->tails=newBox;
					
				}
				this->count++;
			}
    	
	}
	std::cout << "Added Sucessfull\n";

  }
      
}
  


template<class T>
bool orderlist<T>::search(const T&carid)
{
  box<T>*current;
  bool found=false;
  current=this->head;
  while(current!=NULL && !found)
  {
    if(current->carid.id == carid.id)
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
void orderlist<T>::insertFirst(const T& carid){
  insert(carid);
}

template<class T>
void orderlist<T>::insertLast(const T& carid)
{
  insert(carid);
}

template<class T>
void orderlist<T>::deleteItem(const T& carid){
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
      std::cout<<"Item Deleted\n";
    }
    else
    {
      found=false;
      currentrail=this->head;
      current=this->head->next;
      while(current!=NULL &&!found)
      {
        if(current->carid.id!= carid.id)
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
        std::cout << "Item Deleted\n";
      }else{
        std::cout <<"Item not in the list\n";
      }

    }
  }
}


#endif

