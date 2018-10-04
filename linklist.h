#ifndef _LINK_H
#define _LINK_H


#include<fstream>
#include<cstdlib>
#include<iostream>

template <class T>
struct box{
  T carid;
  box<T>*next;
};

template<class T>
class linklist{
protected:
  box<T> *head;
  box<T> *tails;
  int count;

public:
  void initialize();
  void print();
  void printID();
  int  lenght()const;
  bool search(const T& searchItem);
  void showspecific(const T& searchItem);
  void showsummarise();
  linklist();
};

template<class T>
linklist<T>::linklist(){
  head = NULL;
  tails= NULL;
  count = 0;
}

template<class T>
void linklist<T>::initialize(){
  box<T>*temporary;
  while(head!=NULL){
    temporary=head;
    head=head->next;
    delete temporary;
  }

  tails = NULL;
  count = 0;
}

template<class T>
void linklist<T>::print(){
  box<T>*tracker;
  tracker = head;
  //system("cls");
  while(tracker!=NULL)
  {
    std::cout <<"========================================================\n" 
			  <<"Engine ID  = " << tracker->carid.id << std::endl
              << "Model      = " << tracker->carid.models << std::endl
              << "Color      = " << tracker->carid.color << std::endl
              << "Speed      = " << tracker->carid.speed << std::endl
              << "______________________________________________\n"
              << "Price:" << std::endl
              << "Selling    = " << tracker->carid.sellprice << std::endl
              << "Retail     = " << tracker->carid.retailprice << std::endl
              << "On The Road= " << tracker->carid.oTRprice << std::endl
              << "Sales      = " << tracker->carid.totalSales << std::endl
              <<"========================================================\n"; 
              
    tracker=tracker->next;
  }
}

template<class T>
void linklist<T>::printID()
{
  int index=1;
  box<T>*tracker;
  tracker = head;
  std::cout<< "+++++++++++++++Car Engine ID++++++++++++++++++++\n";
  while(tracker!=NULL)
  {
    std::cout << index<<". " << tracker->carid.id <<"\t"<< tracker->carid.models <<std::endl;
    tracker=tracker->next;
    index++;
  }
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  std::cout<< "total car: " << lenght() << std::endl;
}

template<class T>
int linklist<T>::lenght()const{
  return count;
}


template<class T>
bool linklist<T>::search(const T& searchItem){
  box<T>*tracker;
  tracker=head;
  bool found = false;
  while(tracker != NULL && !found)
  {
    if(tracker->carid == searchItem)
    {
      found = true;
    }
    else{
      tracker=tracker->next;
    }
  }
  return found;
}

template <class T>
void linklist<T>::showspecific(const T& searchItem){
  box<T>*tracker;
  tracker=head;
  bool found = false;
  while(tracker != NULL && !found)
  {
    if(tracker->carid.id == searchItem.id)
    {
      found = true;
      std::cout <<"========================================================\n" 
			  <<"Engine ID  = " << tracker->carid.id << std::endl
              << "Model      = " << tracker->carid.models << std::endl
              << "Color      = " << tracker->carid.color << std::endl
              << "Speed      = " << tracker->carid.speed << std::endl
              << "______________________________________________\n"
              << "Price:" << std::endl
              << "Selling    = " << tracker->carid.sellprice << std::endl
              << "Retail     = " << tracker->carid.retailprice << std::endl
              << "On The Road= " << tracker->carid.oTRprice << std::endl
              << "Sales      = " << tracker->carid.totalSales << std::endl
              <<"========================================================\n";
    }
    else{
      tracker=tracker->next;
    }
  }
  if( !found)
  {
  	std::cout << "Item not in the list\n";
  	//system("pause");
  }
	
}

template <class T>
void linklist<T>::showsummarise(){
	box<T>*current;
	int cc1=0,cc2=0,cc3=0;
	current= this->head;
	while(current!=NULL)
	{
		if(current->carid.speed < 1500)
		{
			cc1++;
		}
		else if(current->carid.speed >=1500 && current->carid.speed <= 1799)
		{
			cc2++;
		}
		else if(current->carid.speed >=1800)
		{
			cc3++;
		}
		current=current->next;
	}
	std::cout << "Car Information\n"
			  <<"**************************************\n"
			  <<"Displacement(cc)       Number of Cars \n"
			  <<"Below 1500           " << cc1 << std::endl
			  <<"1500 -> 1799         " << cc2 << std::endl
			  <<"Above 1800           " << cc3 << std::endl
			  <<"***************************************\n";        
}

#endif

