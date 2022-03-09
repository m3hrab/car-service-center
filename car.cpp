#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Admin
{
    string username, password;
    public:
        int loginStatus;
        Admin(const string username,const string password)
        {
            this->username = username;
            this->password = password;
            loginStatus = 0;
        }

        bool verifyLogin()
        {
            if(username=="admin" && password=="12345"){
                loginStatus = 1;
                return loginStatus;
            }
            else{
                cout<<"Wrong username or password"<<endl;
                loginStatus = 0;
                return loginStatus;
            }
        }
};


class Car
{
    private:
        int licenseNo;
        string ownerName, carModel;
    public:
        vector<int> cars;
        vector<string> owners;
        vector<string> car_models;
        Car(){}
        
        void add_car(){
            system("clear");
            cout<<"\t\t\t\tCAR REGISTRATION\n\n";
            cout<<"\t\t*******************************************\n\n";
            cout<<"\t\t\tEnter Car License Number: ";
            cin>>licenseNo;
            cout<<"\t\t\tEnter Car Owner Name: ";
            cin>>ownerName;
            cout<<"\t\t\tEnter Car Brand Name: ";
            cin>>carModel;
            int i;
            cout<<"\n\t\t\tPress 1 to confarmation: ";
            cin>>i;
            if(i==1){
                system("clear");
                cout<<"\n\t\t\tRegistration Successfull ;)"<<endl;
                cars.push_back(licenseNo);
                owners.push_back(ownerName);
                car_models.push_back(carModel);
            }
            else{
                cout<<"\t\t\tRegistration Unsuccessfull"<<endl;
            }

            string any;
            cout<<"\n\n\t\t\tPress any key to continue..";
            cin>>any;
            system("clear");
        }

        void show_cars(){
              system("clear");
              cout<<"\t\t\t\tCARS LIST\n\n";
              cout<<"\t\t*****************************************\n\n\n";
              for (int i = 0; i<cars.size(); i++) {
                cout<<"\t\t\t***********************"<<endl;
                cout << "\t\t\tCar id: "<< i <<endl;
                cout << "\t\t\tLicense Number: " << cars[i]<<endl;
                cout << "\t\t\tOwner Name: " << owners[i]<<endl;
                cout << "\t\t\tCar Brand Name: " << car_models[i]<<endl;
                cout<<"\t\t\t***********************"<<endl<<endl;

              }
              if(cars.size()==0){
                  cout<<"\t\t\tNo cars found. :'("<<endl;
              }

            string any;
            cout<<"\n\t\t\tPress any key to continue..";
            cin>>any;
            system("clear");
        }

        void repair_status(int license_number){
            // find the index of license_number in cars
            int index=-1;
            for(int i=0; i<cars.size();i++){
                if(license_number == cars[i]){
                    index=i;
                    break;
                }
            }

            if (index   != -1){
                cout<<"\t\t\t***********************"<<endl;
                cout << "\t\t\tCar id: "<< index <<endl;
                cout << "\t\t\tLicense Number: " << cars[index]<<endl;
                cout << "\t\t\tOwner Name: " << owners[index]<<endl;
                cout << "\t\t\tCar Brand Name: " << car_models[index]<<endl;
                cout << "\t\t\tRepair Status: Repairing"<<endl;
                cout<<"\t\t\t***********************"<<endl<<endl;
            }
            else{
                cout<<"\t\t\tNo cars found. :'("<<endl;
                
            }
            int i;
            cout<<"\n\n\t\t\tPress any key to continue..";
            cin>>i;
        }
};

int main()
{   
    // login menu
    while(1){
        cout<<"\t\t\tCAR SERVICE CENTER\n\n";
        cout<<"\t\t**************LOGIN********************\n\n";
        cout << "\t\t\tUsername: ";
        string username, password;
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;

        Admin admin(username, password);
        Car car;

        int loginStatus = admin.verifyLogin();
        system("clear");

        while (loginStatus == 1)
        {
            cout<<"\t\t\tCAR SERVICE CENTER\n\n";
            cout<<"\t\t*******************************************\n\n";
            cout <<"\n\t\t\tEnter 1 to add New Car for Repair, "
                "\n\t\t\tEnter 2 to Show Cars,"
                "\n\t\t\tEnter 3 to See Repair Status,"
                "\n\t\t\tEnter 0 to logout\n"
                "\n\t\t\tYour Choice: ";

                    int i;
                    cin >> i;
                    if(i == 0){
                        system("clear");
                        break;
                    }
                    else if(i == 1)
                        car.add_car();
                    else if(i == 2)
                        car.show_cars();
                    else if(i == 3)
                    {
                        system("clear");
                        cout<<"\t\t\tCAR REPAIR STATUS\n\n";
                        cout<<"\t\t*******************************************\n\n";
                        int license;
                        cout<<"\t\t\tEnter License Number: ";
                        cin>>license;
                        car.repair_status(license);

                    }
                    else
                        cout << "\t\t\twrong choice";
                    
        }
        
    }
}