#include "function.h"

using namespace std;

void loadcarinfo(std::ifstream&infile,carinfo car,unorderlist<carinfo> &car1,orderlist<carinfo>&car2)
{
  std::string model;
  std::string color;
  int carid;
  float speed;
  float sellprice;
  float retailprice;
  float oTRprice;
  float totalSales;
  infile.open("info.dat");//change file path
  if(!infile)
  {
    cout << "cannot open file" <<endl;
  }
  else{
    while(infile)
    {
      //infile >> carid >> model >> color >>speed >> sellprice >> retailprice >> oTRprice >> totalSales;
      infile>>car.id;
      getline(infile,car.models);
      getline(infile,car.color);
      infile>>car.speed >> car.sellprice >> car.retailprice >> car.oTRprice >> car.totalSales;
      car1.insertLast(car);
      car2.insert(car);
    }

  }
  infile.close();
}



void menu1(int &opt){
  do{
  	cin.clear();
    cin.ignore(100,'\n');
    system("cls");
    cout<<"==================================================================================="<<endl
        <<"   menu1 Choose following operation                                                "<<endl
        <<"==================================================================================+"<<endl
        <<"       1.insert car details                                                        "<<endl
        <<"       2.Display                                                                   "<<endl
        <<"       3.Search car By ID number                                                   "<<endl
        <<"       4.Delete Car                                                                "<<endl
        <<"       5.Delete All Car                                                            "<<endl
        <<"       6.Exit the Program                                                          "<<endl
        <<"==================================================================================="<<endl;
      cout<<"Your operation: "; cin >> opt;

  }while(cin.fail()||(opt<=0 || opt >=7));
  switch(opt){
    case 1:
    {
      do{
        system("cls");
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"==================================================================================="<<endl
            <<"   menu2 Choose following operation                                                "<<endl
            <<"==================================================================================+"<<endl
            <<"       1.insert car front of list                                       "<<endl
            <<"       2.insert car end of list                                         "<<endl
            //<<"       3.insert car based on On The Road Price (ordered)                           "<<endl
            <<"       3.Back to menu1                                                             "<<endl
            <<"==================================================================================="<<endl;
          cout<<"Your operation: "; cin >> opt;

      }while(cin.fail()||(opt<=0 || opt >=4));
      opt+=10;
      break;
    }
    case 2:{
      do{
        system("cls");
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"==================================================================================="<<endl
            <<"   menu2 Choose following operation                                                "<<endl
            <<"==================================================================================+"<<endl
            <<"       1.Display All carinfo inside list                                           "<<endl
            <<"       2.Display specific car by Car ID                                            "<<endl
            <<"       3.Display All car ID                                                        "<<endl
            <<"       4.Display Summarise info                                                    "<<endl
            <<"       5.back to menu1                                                             "<<endl
            <<"==================================================================================="<<endl;
          cout<<"Your operation: "; cin >> opt;

      }while(cin.fail()||(opt<=0 || opt >=6));
      opt+=20;
      break;
    }
  }
}


bool getanswer(bool&ans)
{
  char opt;
  cout << "stay? (Y/N): "; cin>>opt;
  if(opt=='Y'|| opt=='y')
  {
    ans=true;
    return false;
  }
  else{
    ans=false;
    return true;
  }
}

void askcarinfo(carinfo &car){
	do{
		cout << "Engine id= "; cin >> car.id;
	}while(cin.fail());
  cout << "Models= ";cin.clear(); cin.ignore(100,'\n');getline(cin,car.models);
  cout << "Color= ";getline(cin,car.color);
  cout << "Speed= "; cin>>car.speed;
  cout << "sellprice= "; cin >> car.sellprice;
  cout << "retailprice= "; cin>>car.retailprice;
  cout << "On The Road Price= ";cin>>car.oTRprice;
  cout << "totalSales= "; cin>>car.totalSales;
}

void banner(){
	cout << "====================================================\n"
	     << "                                                    \n"
	     << "     H     H   0 0   N    N  D D D      AAA         \n"
		 << "     H     H  0   0  N N  N  D    D    A   A        \n"
		 <<	"	  H HHH H  0   0  N  N N  D     D  A     A       \n"
		 <<	"	  H     H  0   0  N   NN  D    D  A AAAAA A      \n"
		 <<	"	  H     H    0    N    N  D D D  A         A     \n"
		 << "====================================================\n";
		 system("pause");
}

