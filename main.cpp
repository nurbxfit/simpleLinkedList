
#include "function.h"
using namespace std;
int main(){
  orderlist<carinfo>car2;
  unorderlist<carinfo>car1;
  carinfo car;
  ifstream infile;
  loadcarinfo(infile,car,car1,car2); // load information from the text file
  int opt;
  bool loop;
  bool answ;
  system("cls");
  cout << "\n\n\n\n\t>>>>>>>>>>>>> HONDA CAR INFORMATION <<<<<<<<<<<<<<<<\n";
  cout << "\n\n\n";
  system("pause");
  do{
  	menu1(opt);
  	switch(opt){
  		case 11:
  			{
  				do{
  					askcarinfo(car);
  					car1.insertFirst(car);
  					car2.insertFirst(car);
				  	loop = getanswer(answ);	
				  }while(answ);
				  break;
			  }
		case 12:
			{
				do{
					askcarinfo(car);
					car1.insertLast(car);
					car2.insertLast(car);
					loop = getanswer(answ);
				}while(answ);
				break;
			}
		case 13:
			{
				break;
			}
		case 21:
			{
				system("cls");
				cout << "+++++++++++++++++ FROM LIST 1 +++++++++++++++++++\n";
				car1.print();
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
				cout << "+++++++++++++++++ FROM LIST 2 +++++++++++++++++++\n";
				car2.print();
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
				system("pause");
				loop = true;
				break;
			}
		case 22:
			{
				do{
				cout << "Engine ID= "; cin >> car.id;
				cout << "==============List 1===============\n";
				car1.showspecific(car);
				cout << "==============List 2===============\n";
				car2.showspecific(car);
				loop = getanswer(answ);
				system("pause");
			}while(answ);
				break;
			}
		case 23:
			{
				system("cls");
					car1.printID();
					car2.printID();
					system("pause");
					loop = true;

				break;
			}
		case 24:
			{
				car1.showsummarise();
				car2.showsummarise();
				system("pause");
				break;	
			}
		case 25:
			{
				loop = true;
				break;
			}
		case 3:
			{
				do{
				cout << "Engine ID= "; cin >> car.id;
				cout << "==============List 1===============\n";
				car1.showspecific(car);
				cout << "==============List 2===============\n";
				car2.showspecific(car);
				loop = getanswer(answ);
				system("pause");
			}while(answ);
				break;
			}
		case 4:
			{
				do
				{
				cout << "Engine ID= "; cin >> car.id;
				car1.deleteItem(car);
				car2.deleteItem(car);
				loop = getanswer(answ);
			}while(answ);
				break;
			}
		case 5:
			{
				car1.initialize();
				car2.initialize();
				cout << "All List Deleted!\n";
				system("pause");
				loop = true;
				break;	
			}
		case 6:
			{
				return 0;
			}
	  }
  }while(loop);

}



