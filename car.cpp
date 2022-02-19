#include <iostream>
#include <vector>
using namespace std;

class Admin
{
    string username, password, loginStatus;
    public:
        Admin(const string username,const string password)
        {
            this->username = username;
            this->password = password;
            loginStatus = "Log out";
        }

        bool verifyLogin()
        {
            if(username=="admin" && password=="12345"){
                loginStatus = "Loged in";
                return 1;
            }
            else{
                cout<<"Wrong username or password"<<endl;
                return 0;
            }
        }
};


class Customers
{
    private:
        string customerName, email, phoneNo;
    public:
        Customers(){}

        void addCustomer(string customerName, string email, string phoneNo)
        {
            this->customerName = customerName;
            this->email = email;
            this->phoneNo = phoneNo;
        }

        friend ostream& operator<<(ostream& os, const Customers &customer);
};

ostream& operator<<(ostream& os, const Customers &customer)
{
    os << "Customer Name   : " << customer.customerName;
    os << "Email           : " << customer.email;
    os << "Phone No.       : " << customer.phoneNo;
}


class Car
{
    private:
        string licenseNo, model

};

int main()
{   
    cout << "username: "<<endl;
    string username, password;
    cin >> username;
    cout << "password: ";
    cin >> password;
    
    Admin admin(username, password);
    cout << admin.verifyLogin() << endl;
    

}