//#include<cstdio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<iostream>
#include<time.h>
using namespace std;
static int temp=0;
int best,c;
class toll
{
    char name[50];
    char veichle[10];
    int op,speed1,speed2,speed3,n,each_bill;
    int toll_price,fine_over,total_bill,speeddescision;
    float left;
    public : /*
             void getdata();
             void overspeeding();
             void fine();
             void getdata();
             void total();
             int bill();
             */
            void getdata()
            {
             cout<<"Enter the name of the person.\n";
             cin.getline(name,50);
             cout<<"Enter the Number of Veichle.\n";
             cin >> veichle;
             cout<<"Enter the number of person in vehicle :: \t";
             cin>>n;
             cout<< "Toll Price for your veichle.\n1 -> 2 WHEELER - Rs. 40.\n2 -> 4 WHEELER - Rs 50.\n";
             cout<<"3 -> 8 WHEELER - Rs 100.\n";
             cin >> op;
             switch(op)
             {
                case 1 : toll_price = 40;
                         break;
                case 2 : toll_price = 50;
                         break;
                case 3 : toll_price = 100;
                         break;
                case 4 : cout<<"Invalid Operation";
                         break;
             }
            }
         void overspeeding()
         {
            cout<<"Your Speed That are randomly measured by speedometer in this journey are ::\n";
            cout<<"==================================================================================";
            ifstream inFile;
            inFile.open("abhi.txt");
            inFile>>best;
            if(best == 1)
            {
                cout<<"\n\t\t This is a worst case (When vehicle try to overspeed.).\t\t\n";
                cout<<"\n\t Speed in first 30 kms where the speed limit is 70km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed1 = rand()%80;
                    if(speed1 > 70)
                    {
                        temp++;
                    }
                    cout<< speed1<<"\t";
                }
                cout<<"\n\t Speed in next 20 kms where the speed limit is 100km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed2 = rand()%120;
                    if(speed2 > 100)
                    {
                        temp++;
                    }
                    cout<< speed2<<"\t";
                    //c++;
                }
                cout<<"\n\t Speed in next 50 kms where the speed limit is 60 km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed3 = rand()%70;
                    if(speed3 > 60)
                    {
                        temp++;
                    }
                    cout<< speed3<<"\t";
                }
                ofstream file;
                file.open("abhi.txt",ios::out);
                file<<"0"<<endl;
            }
            else if(best == 0)
            {
                cout<<"\n\t\t This is a best case(When vehicle don't overspeed).\t\t";
                cout<<"\n\t Speed in first 30 kms where the speed limit is 70km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed1 = rand()%60;
                    if(speed1 > 70)
                    {
                        temp++;
                    }
                    cout<< speed1<<"\t";
                }
                cout<<"\n\t Speed in next 20 kms where the speed limit is 100km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed2 = rand()%60;
                    if(speed2 > 100)
                    {
                        temp++;
                    }
                    cout<< speed2<<"\t";
                }
                cout<<"\n\t Speed in next 50 kms where the speed limit is 60 km/h .\n";
                for(int i=0;i<30;i++)
                {
                    speed3 = rand()%50;
                    if(speed3 > 60)
                    {
                        temp++;
                    }
                    cout<< speed3<<"\t";
                }
                ofstream file;
                file.open("abhi.txt",ios::out);
                file<<"1"<<endl;

            }
        }
        void fine()
        {
            cout<<"\n\tTotal number of time the veichle overspeed.\t";
            cout<<temp;
            fine_over = 20*temp;
            cout<< "\nTotal fine due to overspeeding is Rs. "<<fine_over<<endl;
        }
        void total()
        {
            if(temp == 0)
            {
                cout<< "Congratulations You got 20% off on your toll bill just because you havent overspeed.\n";
		        left = 0.2*toll_price;
                total_bill = toll_price - left;
                cout<< "\nThe bill To be paid is Rs. "<<total_bill<<"\n\n";
            }
            else
            {
                cout<<"You overspeed "<<temp<<" times\n";
                if(temp>15)
                {
                    cout<<"Overspeeding Leads to accident. Try to drive slow and safe.\n";
                }
                total_bill = toll_price + fine_over;
                cout<<"Your bill is Rs. "<<total_bill<<"\n";
            }
        }
        int bill()
        {
            cout<< "-------------------------------BILL-----------------------------------------\n\n";
            cout<<"\t\t\tGovernment Of Karnataka\t\n\n";
            cout<<"Driver Name ::   "<<name<<"\t\t\t\t\t\t\tVeichle Number ::   "<<veichle<<endl;
            cout<<"\n\n\n\n";
            cout<<"Total cost of the toll :: \t\t\t\t"<<toll_price<<"\n\n";
            cout<<"Total Fine due to overspeeding ::\t\t\t"<<fine_over<<"\n\n";
	        if(temp == 0)
	        {
		        cout<<"Cashback for driving safely ::  \t\t\t-"<<left<<"\n";
	        }
            cout<<"--------------------------------------------------------------------------------\n";
            cout<<"Total amount to pay :: \t\t\t\t\t"<<total_bill;
            cout<<"\n\n\nTotal amount of money for each person ::\t\t";
            each_bill = total_bill/n;
            cout<<each_bill;
            cout<<"\n\n\n";
            time_t tt;
            struct tm * ti;
            time (&tt);
            ti = localtime(&tt);
            cout << "\n\n\t\tDate and Time is "<< asctime(ti)<<"\n";
            return 0;
        }

};
int main()
{
    char des;
    toll person;
    cout << "\t\t-----------------------Welcome To KARNATAKA toll Gate.---------------------------\n";
    cout << "Enter the details.\n";
    person.getdata();
    cout<<"The fine for overspeeding for each Reading is Rs. 20.\n";
    person.overspeeding();
    person.fine();
    person.total();
    cout<<"Press y to print or display the bill on screen. Press anything else to exit.\n\n ";
    cin>>des;
    if(des == 'y')
    {
        person.bill();
    }
    else
    {
        cout<<"\n\t\t\t\tThank you.\n";
    }
}
