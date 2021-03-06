#include <iostream>
#include <vector>

using namespace std;
class Garage;
class ServiceStatus;

class  Car
{
    int license;
    string carModel, ownerName, contactNumber;
    public:
        Car(int license, string carModel, string ownerName, string contactNumber)
        {
            this->license = license;
            this->carModel = carModel;
            this->ownerName = ownerName;
            this->contactNumber = contactNumber;
        }
        friend ostream& operator<< (ostream&os, const Car &car);
};

ostream& operator<< (ostream&os, const Car &car) 
{
    os << "License No. :" << car.license;
    os << "CarModel    :" << car.carModel;
    os << "Owner Name  :" << car.ownerName;
    os << "Contacts:   :" << car.contactNumber;
}


class Service
{
    int serviceId;
    string serviceType;
    bool serviceStatus;
    Car* car;

    public:
        Service(int serviceId){
            this->serviceId = serviceId;
            serviceType = "Repair";
            serviceStatus = 0;

        }

        Service(int serviceId, string ServiceType)
        {
            this->serviceId = serviceId;
            this->serviceType = serviceType;
            serviceStatus = 0;
        }

        bool operator==(const Service &id){
            return serviceId == id.serviceId;
        }

        friend ostream& operator<<(ostream& os, const Service &service);
};

ostream& operator<<(ostream& os, const Service &service)
{
    os << "Service ID    :" << service.serviceId;
    os << "Service Type  :" << service.serviceType;
}

class Garage
{
    vector<Car> licenses;
    vector<Car> carModels;
    vector<Car> ownerNames;
    vector<Car> contactNumbers;
    vector<Service> services;

    public:
        void register_car()
        {
            int license;
            string carModel, OwnerName, contactNumber;
            cout << "******************************************************************************"<<endl;
            cout << "/t/t/tCar Registration" << endl;

            cout << "License Number    :"<<endl;
            cin >> license;
            cout << "Car Model         :"<<endl;
            cin >> carModel;
            cout << "Owner Name        :"<<endl;
            cin >> OwnerName;
            cout << "Contact Number    :"<<endl;
            cin >> contactNumber;

        }
};
