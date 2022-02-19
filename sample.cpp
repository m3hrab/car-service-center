#include <iostream>
#include <vector>

using namespace std;
class Inventory;
class StockIn;

class Category{
    string name;
    public:
        Category(string name){ // parameterized constructor
            this->name = name;
        }
        friend ostream& operator<<(ostream& os, const Category &category); //friend function
};

ostream& operator<<(ostream& os, const Category &category)  // << operator overloaded
{
    os << "Category:  " <<  category.name ;
    return os;
}

class Product{
    string name;
    Category* category;
public:
    Product(string name, Category* category1){ // parameterized constructor
        this->name = name;
        this->category = category1;
    }

    bool operator==(const Product &other) const {
        return name == other.name;
    }
    friend ostream& operator<<(ostream& os, const Product &product); // friend function
};

ostream& operator<<(ostream& os, const Product &product) // << operator overloaded//
{
    os << "Product:  " <<  product.name << ", ";
    os << *product.category  ;
    return os;
}

class ProductQuantity{
    Product* product;
    int quantity;
public:
    ProductQuantity(Product *product, int quantity){ // parameterized constructor
        this->product = product;
        this->quantity = quantity;
    }
    int get_quantity(){
        return quantity;
    }
    ProductQuantity  operator +( int x){   //  + operator overloaded
        this->quantity = this->quantity + x;
        return *this;
    }
    bool operator==(const Product &other) const {
        return *product == other;
    }
    ProductQuantity  operator -( int x){ // - operator overloaded
        this->quantity = this->quantity - x;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const ProductQuantity &productQuantity);
};

ostream& operator<<(ostream& os, const ProductQuantity &productQuantity) // << operator overloaded
{
    os << "\t"<< *productQuantity.product <<  " quantity: " << productQuantity.quantity << endl;
    return os;
}

class StockIn{
    vector<ProductQuantity> stock_in_products;
    string date, name;
public:
    StockIn(string date, string name){
        this->date = date;
        this->name = name;
    }
    void add_stock_in_products(Product *product, int quantity){
        ProductQuantity productQuantity(product, quantity);
        stock_in_products.push_back(productQuantity);
    }
    int size(){
        return stock_in_products.size();
    }
    ProductQuantity* get_stock_in_product(int index){
        return &stock_in_products[index];
    }
    friend ostream& operator<<(ostream& os, const StockIn &stockIn);
};

ostream& operator<<(ostream& os, const StockIn &stockIn) // << operator overloaded
{
    os << "Stock In details: ";
    os <<  stockIn.name << endl;
    os << "\tdate: " << stockIn.date << endl;
    for(int i = 0; i < stockIn.stock_in_products.size(); i++){
        os << stockIn.stock_in_products[i];
    }
    return os;
}

class Inventory{
    vector<Product> products;
    vector<Category> categories;
    vector<ProductQuantity> stock;
    vector<StockIn> stock_ins;
public:
    void add_products(){
        string name;
        cout <<" enter product name : ";
        cin >> name;
        show_categories();
        cout << "Choose one Category number "<< endl;
        int item;
        cin >> item;
        if( categories.size() >= item){
            Product product(name, &categories[item - 1]);
            products.push_back(product);
        } else {
            cout << "No such category item" << endl;
        }
    }
    void add_categories(){
        string name;
        cout <<" enter category name : ";
        cin >> name;
        Category category(name);
        categories.push_back(category);
    }
    void initialize_stock(){
        for(int i = 0; i< products.size(); i++){
            ProductQuantity productQuantity(&products[i], 0);
            stock.push_back(productQuantity);
        }
    }
    void show_categories(){
        cout<< "Categories: " << endl;
        for(int i = 0; i< categories.size(); i++){
            cout << "\t" << i + 1 << ".";
            cout << categories[i];
            cout << endl;
        }
    }
    void show_products(){
        cout<< "Products: " << endl;
        for(int i = 0; i< products.size(); i++){
            cout << "\t" << i + 1 << ".";
            cout << products[i];
            cout << endl;
        }
    }
    void menu(){
        while (1) {
            cout <<"Enter 1 to view Categories, "
                    "\nEnter 2 to view Products,"
                    "\nEnter 3 to view stocks, "
                   "\nEnter 4 to  add a new stock-in"
                   "\nEnter 5 to view Stock-ins, "
                    "\nEnter 0 to exit."
                    "\n Your Choice: ";
            int i;
            cin >> i;
            switch (i) {
                case 0:
                    exit(0);
                case 1:
                    show_categories();
                    break;
                case 2:
                    show_products();
                    break;
                case 3:
                    show_stock();
                    break;
                case 4:
                    new_stock_in();
                    break;
                case 5:
                    show_stock_ins();
                    break;
                default:
                    cout <<" wrong input\n";
            }
        }
    }
    void new_stock_in() {
        cout <<"enter a name/label for this stock-in";
        string name;
        cin >> name;
        cout << "enter a date: ";
        string date;
        cin >> date;

        StockIn stockIn(date, name);
        while (1) {
            cout << "Enter 1 : to add stock-in product \nEnter 0 to exit.\n Your Choice: ";
            int i;
            cin >> i;
            if (i == 0)
                break;
            else if (i == 1) {
                show_products();
                int item;
                cout << "choose a product: ";
                cin >> item;
                if (products.size() >= item) {
                    int quantity;
                    Product *product = &products[item - 1];
                    cout << " enter the quantity : ";
                    cin >> quantity;
                    stockIn.add_stock_in_products(product, quantity);
                    update_stock(product, quantity);
                } else {
                    cout << "No such product item" << endl;
                }
            } else
                cout << "wrong input " << endl;
        }

        stock_ins.push_back(stockIn);
    }
    void show_stock(){
        cout<< "Stock: " << endl;
        for(int i = 0; i< stock.size(); i++){
            cout << "\t" << i + 1 << "." << stock[i]<< endl;
        }
    }
    void show_stock_ins(){
        cout<< "Stock-ins : " << endl;
        for(int i = 0; i< stock_ins.size(); i++){
            cout << "\t" << i + 1 << "." << stock_ins[i]<< endl;
        }
    }
    void update_stock(Product *product, int quantity){
            for(int i = 0; i< stock.size(); i++){
                if(stock[i] == *product){
                    stock[i] = stock[i] + quantity;
                }
            }
    }
};

int main() {
    Inventory inventory;
    while (1) {
        cout <<"\nEnter 1 to add Categories, "
               "\nEnter 2 to add Products,"
               "\nEnter 0 to finish."
               "\n Your Choice: ";
        int i;
        cin >> i;
        if(i == 0)
            break;
        else if(i == 1)
            inventory.add_categories();
        else if(i == 2)
            inventory.add_products();
        else
            cout << "wrong choice";
    }
    inventory.initialize_stock();
    inventory.menu();
    return 0;
}