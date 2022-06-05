#include<iostream>
#include<string>

using namespace std;

class Category
{
    static Category* _instance;
    public:
    Category(){}
    static Category* getInstace() {
		if(_instance == NULL) 
			_instance = new Category();
		return _instance;}
    int productId;
    string productName;
    string supplier;
    float price;
    Category(int productId,string productName,string supplier,float price):productId(productId),productName(productName),supplier(supplier),price(price){}
    virtual void viewProductSpecification(){}
};
int cartt=0;

class MensCategory:public Category
{
    public:
    string productType;
    MensCategory(){}
    MensCategory(int productId,string productName,string supplier,float price,string productType):Category(productId,productName,supplier,price),productType(productType){}
    void viewProductSpecification()
    {
            cout<<productId<<"\t"<<productName<<"\t"<<price<<"\t\t"<<productType<<"\t\t"<<supplier<<endl;
    }
};

class WomensCategory:public Category
{
    public:
    string productType;
    WomensCategory(){}
    WomensCategory(int productId,string productName,string supplier,float price,string productType):Category(productId,productName,supplier,price),productType(productType){}
     void viewProductSpecification()
    {
            cout<<productId<<"\t"<<productName<<"\t\t"<<price<<"\t\t"<<productType<<"\t\t"<<supplier<<endl;
    }
};

class KidsCategory:public Category
{
    public:
    string productType;
    KidsCategory(){}
    KidsCategory(int productId,string productName,string supplier,float price,string productType):Category(productId,productName,supplier,price),productType(productType){}
     void viewProductSpecification()
    {
        cout<<productId<<"\t"<<productName<<"\t"<<price<<"\t\t\t"<<productType<<"\t\t"<<supplier<<endl;
    }
};

class Electronics:public Category
{
    public:
    string productType;
    Electronics(){}
    Electronics(int productId,string productName,string supplier,float price,string productType):Category(productId,productName,supplier,price),productType(productType){}
    void viewProductSpecification()
    {
        cout<<productId<<"\t"<<productName<<"\t"<<price<<"\t\t"<<productType<<"\t"<<supplier<<endl;
    }
};

class Products
{
    public:
    MensCategory mc[10];
    WomensCategory wc[10];
    KidsCategory kc[10];
    Electronics ec[10];
    void ShowMenCategory()
    { 
        
        for (int i = 0; i < 10; i++)
        {
            mc[i].viewProductSpecification();
        }
        
        
    }
     void ShowWomenCategory()
    { 
        
        for (int i = 0; i < 10; i++)
        {
            wc[i].viewProductSpecification();
        }
        
        
    }
    void ShowKidsCategory()
    { 
        
        for (int i = 0; i < 10; i++)
        {
            kc[i].viewProductSpecification();
        }
        
        
    }
    void ShowElectroicCategory()
    { 
        
        for (int i = 0; i < 10; i++)
        {
            ec[i].viewProductSpecification();
        }
        
        
    }

};


class ShoppingCart
{
    static ShoppingCart* _instance;
    public:
    ShoppingCart(){}
    static ShoppingCart* getInstace() {
		if(_instance == NULL) 
			_instance = new ShoppingCart();
		return _instance;
	};
    static int itemCount;
    int cartId;
    Category cart[10];
    string dateAdded;
    int quantity;
    float totalPrice;
    ShoppingCart(int cartId,int quantity):cartId(cartId),quantity(quantity){}
    void addCartItem(){}
    void updateQuantity(){}
    void checkout(){}
    void Shopping(Products p, int itemid)
    {
        int checkit=1;
        for (int j = 0; j < 1; j++)
        {
            if(itemid!=0)
            {
            for (int i = 0; i < 10; i++)
            {
                if(p.mc[i].productId==itemid)
                {
                    cart[itemCount].productName=p.mc[i].productName;
                    cart[itemCount].price=p.mc[i].price;
                    cart[itemCount].productId=p.mc[i].productId;
                    cart[itemCount].supplier=p.mc[i].supplier;
                    cout<<"\n'Item "<<cart[itemCount].productId<<"' Added to Cart !"<<endl;
                    ++cartt;
                    checkit=0;
                    ++itemCount;
                    break;
                }
                else if(p.wc[i].productId==itemid)
                {
                    cart[itemCount].productName=p.wc[i].productName;
                    cart[itemCount].price=p.wc[i].price;
                    cart[itemCount].productId=p.wc[i].productId;
                    cart[itemCount].supplier=p.wc[i].supplier;
                    cout<<"\n'Item "<<cart[itemCount].productId<<"' Added to Cart !"<<endl;
                    checkit=0;
                    ++itemCount;
                    break;
                }
                else if(p.kc[i].productId==itemid)
                {
                    cart[itemCount].productName=p.kc[i].productName;
                    cart[itemCount].price=p.kc[i].price;
                    cart[itemCount].productId=p.kc[i].productId;
                    cart[itemCount].supplier=p.kc[i].supplier;
                    cout<<"\n'Item "<<cart[itemCount].productId<<"' Added to Cart !"<<endl;
                    checkit=0;
                    ++cartt;
                    ++itemCount;
                }
                 else if(p.ec[i].productId==itemid)
                {
                    cart[itemCount].productName=p.ec[i].productName; 
                    cart[itemCount].price=p.ec[i].price;
                    cart[itemCount].productId=p.ec[i].productId;
                    cart[itemCount].supplier=p.ec[i].supplier;
                    cout<<"\n'Item "<<cart[itemCount].productId<<"' Added to Cart !"<<endl;
                    checkit=0;
                    ++itemCount;
                    ++cartt;
                    break;
                }
                
         }}


            
           if(checkit==1)
            {
                cout<<"------------WARNING: ENTER 'itemid' Correctly------------"<<endl;

            }
            
        }
        
        
    }
    
    void viewCartDetails()
    {
        totalPrice=0;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Total Items : "<<itemCount<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"ItemId\tItem Name\t\t\tPRICE(Rs)"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        for(int i = 0; i < itemCount; i++)
        {
           cout<<cart[i].productId<<"\t"<<cart[i].productName<<"\t\t\t"<<cart[i].price<<endl; 
        }
        for(int i = 0; i < itemCount; i++)
        {
            totalPrice+=cart[i].price;
        }
        cout<<"-----------------------------------------------"<<endl;
        cout<<"\t\t\t\tTotal : "<<totalPrice<<endl;
        cout<<"-----------------------------------------------"<<endl;

        
    }

    
};

int ShoppingCart::itemCount=0;

class ShippingInfo
{
    static ShippingInfo* _instance;
    public:
    ShippingInfo(){}
    static ShippingInfo* getInstace() {
		if(_instance == NULL) 
			_instance = new ShippingInfo();
		return _instance;
	};
    int shippingId;
    float shippingCost;
    string ShipAddress;
    ShippingInfo(int shippingId,float shippingCost):shippingId(shippingId),shippingCost(shippingCost){}
};


class OrderDetails
{
    static OrderDetails* _instance;
    public:
    OrderDetails(){}
    static OrderDetails* getInstace() {
		if(_instance == NULL) 
			_instance = new OrderDetails();
		return _instance;
	}
    int orderId;
    int productId;
    string productName;
    int quantity;
    float total;
    OrderDetails(int orderId,int productId,string productName,int quantity,float total):orderId(orderId),productId(productId),productName(productName),quantity(quantity),total(total){}
};

class Orders
{
    static Orders* _instance;
    public:
    Orders(){}
    static Orders* getInstace() {
		if(_instance == NULL) 
			_instance = new Orders();
		return _instance;
	}
    int orderId;
    string dateOfOrder;
    string customerName;
    string status;
    ShippingInfo si;
    OrderDetails od;
    Orders(int orderId,string dateOfOrder,string customerName,string status):orderId(orderId),dateOfOrder(dateOfOrder),customerName(customerName),status(status){}
    void OrderDetail()
    {

    }

};

class BankAccount
{
    static BankAccount* _instance;
    public:
    BankAccount(){}
    
    static BankAccount* getInstace() {
		if(_instance == NULL) 
			_instance = new BankAccount();
		return _instance;
	}
    int AcNum;
    string bankName;
    float Amount;
    string cardType;
    BankAccount(int AcNum,string bankName, float Amount,string cardType):AcNum(AcNum),bankName(bankName),Amount(Amount),cardType(cardType){}
};


class Payment
{
    static Payment* _instance;
    public:
    Payment(){}
    
    static Payment* getInstace() {
		if(_instance == NULL) 
			_instance = new Payment();
		return _instance;
	}
    string paymentId;
    string paymentStatus;
    float payable_amt;
    string paymentType;
    Payment(string paymentId,float payable_amt):paymentId(paymentId),payable_amt(payable_amt){}
};



class MyntraUser
{
    static MyntraUser* _instance;
    public:
    MyntraUser(){}
    static MyntraUser* getInstace() {
		if(_instance == NULL) 
			_instance = new MyntraUser();
		return _instance;
	}
    int userId;
    string password;
    string loginStatus;
    ShoppingCart cart;
    Orders order[10];
    MyntraUser(int userId,string password):userId(userId),password(password){}
    void verifyLogin(){}
    
};
class Customer:public MyntraUser
{
    public:
    string customerName;
    string address;
    string email;
    BankAccount bnk;
    string ShippingInfo;
    Payment paymentmode;
    static int orderCount;

    Customer(){}
    Customer(int userId,string password,string customerName,string address,string email,BankAccount bnk,string ShippingInfo):MyntraUser(userId,password),customerName(customerName),address(address),email(email),bnk(bnk),ShippingInfo(ShippingInfo){}
    
};

int Customer::orderCount=0;

class Myntra
{
    static Myntra* _instance;
    Myntra(){}
    public:
    Customer m[10];
    static Myntra* getInstace() {
		if(_instance == NULL) 
			_instance = new Myntra();
		return _instance;
	}

    void PrintMyntraUsers()
    {
        for (int i = 0; i < 10; i++)
        {
            cout<<m[i].userId<<"\t"<<m[i].password<<"\t"<<m[i].customerName<<endl;;
        }
    }

    int LoginValidation(Myntra *n,int uid,string pas)
     {
        int token=0;

        for (int i = 0; i < 10; i++)
        {
            // cout<<uid;
            //cout<<"h"<<n->m[i].userId<<endl;
            // cout<<pas;

            if(n->m[i].userId==uid && n->m[i].password==pas)
            {
                return 1;

            }
            else
            { 
            }

        }
       
        return 0;
        
     }

     void ModeOfPayment(Myntra *cust, string ptype,ShoppingCart cart,Payment pay, Orders order[10])
    {
        int ch;
        float tcharge;
        int orderid=0;
        
        for (int i = 0; i < 10; i++)
        {
            try
            {
                if((ptype=="CreditDebit")&&(cust->m[i].bnk.cardType=="Credit" || cust->m[i].bnk.cardType=="Debit"))
                { 
                    pay.paymentId="xxxx";
                    pay.payable_amt=cart.totalPrice;
                    cust->m[i].bnk.Amount=cust->m[i].bnk.Amount - pay.payable_amt;
                    cart.totalPrice=0;
                    //cout<<cust.m[i].bnk.Amount<<endl;
                    pay.paymentStatus="PAID !";
                    pay.paymentType="Credit/Debit";
                    order[i].customerName=cust->m[i].customerName;
                    order[i].orderId=++orderid;
                    order[i].status="Shipped";
                    
                    cout<<"ORDER PLACED! ThankYou For Ordering."<<endl;

                    break;
                }
                else if(ptype=="EMI")
                {
                    if(cust->m[i].bnk.cardType=="Credit")
                    {
                        pay.payable_amt=cart.totalPrice;

                        // 3 MONTH EMI
                        cout<<"-----------3 MONTH EMI-----------"<<endl;
                        tcharge=pay.payable_amt+pay.payable_amt*(0.02);
                        for (int i = 0; i < 3; i++)
                        {
                        cout<<i+1<<".\tRs. "<<tcharge/3 <<"\tMonth "<<i+1<<endl;
                        }
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"\t\tTotal : "<<tcharge<<endl;
                        cout<<"-----------------------------------------"<<endl;

                        //6 MONTH EMI
                        cout<<"\n\n-----------6 MONTH EMI-----------"<<endl;
                        tcharge=pay.payable_amt+pay.payable_amt*(0.08);
                        for (int i = 0; i < 6; i++)
                        {
                        cout<<i+1<<".\tRs. "<<tcharge/6 <<"\tMonth "<<i+1<<endl;
                        }
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"\t\tTotal : "<<tcharge<<endl;
                        cout<<"-----------------------------------------"<<endl;

                        // 12 MONTH EMI
                        cout<<"\n-----------12 MONTH EMI-----------"<<endl;
                        tcharge=pay.payable_amt+pay.payable_amt*(0.12);
                        for (int i = 0; i < 12; i++)
                        {
                            cout<<i+1<<".\tRs. "<<tcharge/12 <<"\tMonth "<<i+1<<endl;
                        }
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"\t\tTotal : "<<tcharge<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        
                        do
                        {
                        int ch;
                        pay.paymentId="xxxx";
                        
                        //Option Generating
                        cout<<"\n\n1: 3 MONTH EMI (2% Charge)"<<endl;
                        cout<<"2: 6 MONTH EMI (8% Charge)"<<endl;
                        cout<<"3: 12 MONTH EMI (12% Charge)"<<endl;
                        cout<<"4: Go Back"<<endl;
                        cout<<"Choose Any One Option :";
                        cin>>ch;
                        cout<<endl; 
                        switch (ch)
                        {
                        case 1:
                        pay.paymentType="3 MONTH EMI";
                        cout<<"ThankYou! You've selected 3 MONTH EMI"<<endl;
                        break;
                        
                        case 2:
                        pay.paymentType="6 MONTH EMI";
                        cout<<"ThankYou! You've selected 6 MONTH EMI"<<endl;
                        break;

                        case 3:
                        pay.paymentType="12 MONTH EMI";
                        cout<<"ThankYou! You've selected 12 MONTH EMI"<<endl;
                        break;
                        default:
                        break;
                        }} while(ch!=4);
                        
                    }
                }
                else if(ptype=="COD")
                {
                    pay.paymentStatus="UNPAID";
                    cout<<"ORDER PLACED!! ThankYou For Ordering.\n"<<endl;
                    pay.paymentType="COD";
                    break;

                }
                else
                {
                    throw(0);
                }
            }
            catch(const int x)
            {
                cout<<endl;
            }
            

        }
        
    }
     







};
void welcome()
{
    cout<<"***      ***    ***    ***    ***        ***    ***********    ***********    ***********"<<endl;
    cout<<"***      ***    ***    ***    *** *      ***        ***        ***     ***    ***     ***"<<endl;
    cout<<"*** ***  ***     ***  ***     *** ***    ***        ***        ***     ***    ***     ***"<<endl;
    cout<<"*** ***  ***      *****       ***  ***   ***        ***        ***********    ***********"<<endl;
    cout<<"***  *   ***       ***        ***   ***  ***        ***        *** *          ***********"<<endl;
    cout<<"***      ***       ***        ***    *** ***        ***        ***  **        ***     ***"<<endl;
    cout<<"***      ***       ***        ***     ******        ***        ***   ***      ***     ***"<<endl; 
}


void Navbar()
{
    cout<<"ID\t"<<"NAME\t\t"<<"PRICE(Rs)\t"<<"TYPE\t\t"<<"SUPPLIER\n"<<endl;
}

int Shop()
{
    int ch;
    cout<<"\n1: Shop"<<endl;
    cout<<"2: Switch To Other Category"<<endl;
    cin>>ch;
    cout<<endl;
    return ch;
}

int PlaceOrder()
{
    int ch;
    cout<<"\n1: CREDIT/DEBIT Card"<<endl;
    cout<<"2: EMI"<<endl;
    cout<<"3: COD"<<endl;
    cout<<"4: Go back"<<endl;
    cin>>ch;
    cout<<endl; 
    return ch;
}

Myntra * Myntra::_instance = NULL;
int main()

{
    int choice,choice1,choice2,choice3,tokenv,soc,itmid,poc,cnt,uid,cn,ud,custCount=4;
    ShoppingCart c1;
    Orders order[10];
    Payment pay;
    string ptype,pswd, cname, addr, em,sinf, pas;
    static int orderCount=0;
    welcome();
   //int productId,string productName,string supplier,float price,string productType
   //--------------------------------------------MENs--------------------------------------------
   
    MensCategory c1m1(1,"Running Shoes","Puma",5000,"Shoes");
    MensCategory c1m2(2,"Air Max Sneaker","Nike",9000,"Shoes");
    MensCategory c1m3(3,"Slim Fit","Us-polo",1750,"T-shirt");
    MensCategory c1m4(4,"Polo Collar","Super Dry",945,"T-shirt");
    MensCategory c1m5(5,"Trousers","Spykar",1567,"Jeans");
    MensCategory c1m6(6,"Tapered Fit","Levis",1999,"Jeans");
    MensCategory c1m7(7,"Analogue  ","Fastrack",6550,"Watch");
    MensCategory c1m8(8,"Digital  ","G-shock",9999,"Watch");
    MensCategory c1m9(9,"Oversized","H&M",1499,"Shirt");
    MensCategory c1m10(10,"Casual  ","Tommy Hilfiger",2759,"Shirt");
    MensCategory *men[10]={&c1m1,&c1m2,&c1m3,&c1m4,&c1m5,&c1m6,&c1m7,&c1m8,&c1m9,&c1m10};
    Products mc;
    mc.mc[0]=*men[0];mc.mc[1]=*men[1];mc.mc[2]=*men[2];mc.mc[3]=*men[3];mc.mc[4]=*men[4];mc.mc[5]=*men[5];mc.mc[6]=*men[6];mc.mc[7]=*men[7];mc.mc[8]=*men[8];mc.mc[9]=*men[9];
    

   //--------------------------------------------WOMENs--------------------------------------------

    WomensCategory c1w1(11,"Sneaker","Adidas",3400,"Shoes");
    WomensCategory c1w2(12,"Kurta","W",3400,"Top");
    WomensCategory c1w3(13,"Lehenga","Biba",5625,"Top");
    WomensCategory c1w4(14,"Slimfit","Max",1399,"Jeans");
    WomensCategory c1w5(15,"Maxi","Zara",7400,"Dress");
    WomensCategory c1w6(16,"Digital","Fossil",14995,"watch");
    WomensCategory c1w7(17,"A line","Mango",4131,"Watch");
    WomensCategory c1w8(18,"Sneaker","Puma",2400,"Shoes");
    WomensCategory c1w9(19,"Jumper","Mango",1974,"Dress");
    WomensCategory c1w10(20,"Wideleg","Levis",5599,"shoes");
    WomensCategory *women[10]={&c1w1,&c1w2,&c1w3,&c1w4,&c1w5,&c1w6,&c1w7,&c1w8,&c1w9,&c1w10};
    Products wc;
    wc.wc[0]=*women[0];wc.wc[1]=*women[1];wc.wc[2]=*women[2];wc.wc[3]=*women[3];wc.wc[4]=*women[4];wc.wc[5]=*women[5];wc.wc[6]=*women[6];wc.wc[7]=*women[7];wc.wc[8]=*women[8];wc.wc[9]=*women[9];
   
 //--------------------------------------------KIDs--------------------------------------------

    KidsCategory c1k1(21,"Jump-suit ","LilPicks",999,"Dress");
    KidsCategory c1k2(22,"A line C","H & M",799,"Dress");
    KidsCategory c1k3(23,"Camo-Clog","Crocs",2995,"FlipFlp");
    KidsCategory c1k4(24,"SweatShirt","Pepejeans",799,"Shirt");
    KidsCategory c1k5(25,"Shorts MT","Pepejeans",849,"Jeans");
    KidsCategory c1k6(26,"Denim Lev","Levis",1169,"Shirt");
    KidsCategory c1k7(27,"Dungaree","BabyGo",649,"Dress");
    KidsCategory c1k8(28,"Slimfit M","H & M",1286,"Jeans");
    KidsCategory c1k9(29,"Flare Max","M A X",856,"Dress");
    KidsCategory c1k10(30,"Casual S","BATA",1274,"Shoes");
    KidsCategory *kids[10]={&c1k1,&c1k2,&c1k3,&c1k4,&c1k5,&c1k6,&c1k7,&c1k8,&c1k9,&c1k10};
    Products kc;
    kc.kc[0]=*kids[0];kc.kc[1]=*kids[1];kc.kc[2]=*kids[2];kc.kc[3]=*kids[3];kc.kc[4]=*kids[4];kc.kc[5]=*kids[5];kc.kc[6]=*kids[6];kc.kc[7]=*kids[7];kc.kc[8]=*kids[8];kc.kc[9]=*kids[9];

//--------------------------------------------Electronics--------------------------------------------


    Electronics c1e1(31,"Rockerz   ","Boat",1599,"Headsets    ");
    Electronics c1e2(32,"Bluetooth ","JBL",2499,"Speaker     ");
    Electronics c1e3(33,"VS12-Wired ","Noise",799,"Headsets    ");
    Electronics c1e4(34,"Heat-Brush ","Philips",999,"Straightener");
    Electronics c1e5(35,"HairTrimmer","Nova",899,"wiredTrimmer");
    Electronics c1e6(36,"EarPods    ","Boat",1199,"Headsets    ");
    Electronics c1e7(37,"Cobble    ","Realme",1999,"Speaker     ");
    Electronics c1e8(38,"Ceramic   ","Vega",1599,"SalonDryer  ");
    Electronics c1e9(39,"Over head","Hammer",2599,"Headsets    ");
    Electronics c1e10(40,"Heat Curler","Vega",1123,"Straightener");
    Electronics *ele[10]={&c1e1,&c1e2,&c1e3,&c1e4,&c1e5,&c1e6,&c1e7,&c1e8,&c1e9,&c1e10};
    Products ec;
    ec.ec[0]=*ele[0];ec.ec[1]=*ele[1];ec.ec[2]=*ele[2];ec.ec[3]=*ele[3];ec.ec[4]=*ele[4];ec.ec[5]=*ele[5];ec.ec[6]=*ele[6];ec.ec[7]=*ele[7];ec.ec[8]=*ele[8];ec.ec[9]=*ele[9];

// BankAccount(int AcNum,string bankName, float Amount,string cardType):AcNum(AcNum),bankName(bankName),Amount(Amount),cardType(cardType){}

//Customer(string userId,string password,string loginStatus,string customerName,string address,string email,BankAccount bnk,string ShippingInfo,Payment paymentmode):MyntraUser(userId,password,loginStatus),customerName(customerName),address(address),email(email),bnk(bnk),ShippingInfo(ShippingInfo),paymentmode(paymentmode){}
    BankAccount b1(3917,"SBI",20000,"Credit");
    BankAccount b2(3917,"SBI",50500,"Credit");
    BankAccount b3(3917,"SBI",70200,"Debit");
    BankAccount b4(3917,"SBI",65900,"Credit");
    BankAccount b5(3917,"SBI",74324,"Credit");
    Customer m1(1,"shawn123","Shawn","India","prkskrs@gmail.com",b1,"Panaji, Goa, 844101");
    Customer m2(2,"def123","Anusha","India","anusha@gmail.com",b2,"Dharwad, Karnataka, 580021");
    Customer m3(3,"ghi123","Prakash","India","prkshr@gmail.com",b3,"Hajipur, Bihar, 844101");
    Customer m4(4,"jkl123","Aman","India","aman@gmail.com",b4,"Patna, Bihar, 844101");
    Customer m5(5,"mno123","Shashank","India","shashank@gmail.com",b5,"Hubballi, Karnataka, 580021");
    Customer *p[10]={&m1,&m2,&m3,&m4,&m5};
  
    Myntra *n=Myntra::getInstace();
    n->m[0]=*p[0];n->m[1]=*p[1];n->m[2]=*p[2];n->m[3]=*p[3];n->m[4]=*p[4];
    // n->PrintMyntraUsers();
    
    do
    {
        cout<<"\n1: LogIn"<<endl;
        cout<<"2: Create Myntra Id"<<endl;
        cout<<"3: Exit App"<<endl;
        cout<<"\nEnter Choice:";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {

    // Login Myntra
        case 1: cout<<"Enter User Id :";
                cin>>uid;
                cout<<"Enter Password:";
                cin>>pas;
                tokenv=n->LoginValidation(n,uid,pas);
                cout<<tokenv<<endl;
                if(tokenv==1)
                {
                    cout<<"\n------------LoggedIn SuccessFully!------------\n"<<endl;
                    do
                    {
                    cout<<"\n------------------MAIN PAGE------------------\n";
                    cout<<"1: View Category And Shop"<<endl;
                    cout<<"2: View Cart"<<endl;
                    cout<<"3: View Orders"<<endl;
                    cout<<"4: LogOut"<<endl;
                    cout<<"\nEnter Choice:";
                    cin>>choice1;
                    cout<<endl;
                    switch(choice1)
                    {
                        case 1:
                        do
                        {
                            cout<<"1: Mens Category"<<endl;
                            cout<<"2: Womens Category"<<endl;
                            cout<<"3: Kids Category"<<endl;
                            cout<<"4: Electronics Category"<<endl;
                            cout<<"5: Back to Main Page"<<endl;
                            cout<<"\nEnter Choice:";
                            cin>>choice2;
                            cout<<endl;
                            switch(choice2)
                            {
                            case 1: Navbar();
                                    mc.ShowMenCategory();
                                    do{
                                    soc=Shop();
                                    switch(soc)
                                    {
                                    case 1: cout<<"Enter Item Id to Purchase:";
                                            cin>>itmid;
                                            c1.Shopping(mc,itmid);
                                            //c1.viewCartDetails();
                                    break;
                                    } }while(soc!=2);

                            break;
                            
                            case 2: Navbar(); 
                                    wc.ShowWomenCategory();
                                    do{
                                    soc=Shop();
                                    switch(soc)
                                    {
                                    case 1: cout<<"Enter Item Id to Purchase:";
                                            cin>>itmid;
                                            c1.Shopping(wc,itmid);
                                            //c1.viewCartDetails();
                                    break;
                                    }} while(soc!=2);
                            break;

                            case 3: cout<<"ID\t"<<"NAME\t\t"<<"PRICE(Rs)\t\t"<<"TYPE\t\t"<<"SUPPLIER\n"<<endl;
                                    kc.ShowKidsCategory();
                                    do{
                                    soc=Shop();
                                    switch(soc)
                                    {
                                    case 1: cout<<"Enter Item Id to Purchase:";
                                            cin>>itmid;
                                            c1.Shopping(kc,itmid);
                                            //c1.viewCartDetails();
                                    break;
                                    }} while(soc!=2);
                            break;

                            case 4: Navbar(); 
                                    ec.ShowElectroicCategory();
                                    do{
                                    soc=Shop();
                                    switch(soc)
                                    {
                                    case 1: cout<<"Enter Item Id to Purchase:";
                                            cin>>itmid;
                                            c1.Shopping(ec,itmid);
                                            //c1.viewCartDetails();
                                    break;
                                    }} while(soc!=2);
                            break;
                            default:
                                break;
                            }
                        } while (choice2!=5);
                        break;
                        case 2:
                        do
                        {
                            cout<<"-----------------Your Cart----------------\n\n";
                            c1.viewCartDetails();
                            cout<<"\n1: Place Order"<<endl;
                            cout<<"2: Back To Main Page To Add More Item"<<endl;
                            cout<<"\nEnter Choice:";
                            cin>>choice3;
                            cout<<endl;
                            switch(choice3)
                            {
                                case 1:do
                                {
                                    cout<<"-----------------Choose ModeOfPayment---------------\n";
                                    poc=PlaceOrder();
                                    switch(poc)
                                    {
                                    case 1: ptype="CreditDebit";
                                            n->ModeOfPayment(n,ptype,c1,pay,order);
                                            for (int i = 0; i < cartt; i++)
                                            {
                                                ++orderCount;
                                                order[i].orderId=i+1;
                                                //order[i].dateOfOrder=
                                                order[i].customerName=p[uid-1]->customerName;
                                                order[i].od.productName=c1.cart[i].productName;
                                                order[i].od.total=c1.cart[i].price;
                                                order[i].si.shippingId=i+88;
                                                order[i].si.shippingCost=40;
                                                order[i].status="Shipped";
                                                order[i].si.ShipAddress=n->m[uid-1].ShippingInfo;

                                                
                                            }
                                            
                                    break;
                                    case 2: ptype="EMI";
                                            n->ModeOfPayment(n,ptype,c1,pay,order);
                                            for (int i = 0; i < cartt; i++)
                                            {

                                                ++orderCount;
                                                order[i].orderId=i+1;
                                                //order[i].dateOfOrder=
                                                order[i].customerName=p[uid-1]->customerName;
                                                order[i].od.productName=c1.cart[i].productName;
                                                order[i].od.total=c1.cart[i].price;
                                                order[i].si.shippingId=i+88;
                                                order[i].si.shippingCost=40;
                                                order[i].status="Shipped";
                                                order[i].si.ShipAddress=n->m[uid-1].ShippingInfo;
                                                
                                            }
                                    break;
                                    case 3: ptype="COD";
                                            n->ModeOfPayment(n,ptype,c1,pay,order);
                                            for (int i = 0; i < cartt; i++)
                                            {
                                                ++orderCount;
                                                order[i].orderId=i+10;
                                                //order[i].dateOfOrder=
                                                order[i].customerName=p[uid-1]->customerName;
                                                order[i].od.productName=c1.cart[i].productName;
                                                order[i].od.total=c1.cart[i].price ;
                                                order[i].si.shippingId=i+88;
                                                order[i].si.shippingCost=40;
                                                order[i].status="Shipped";
                                                order[i].si.ShipAddress=n->m[uid-1].ShippingInfo;
                                            }
                                    break;
                                    default:
                                        break;
                                    }
                                } while (poc!=4);
                                break;
                                
                                default:
                                break;
                            } }while(choice3!=2);
                        break;

                        case 3: cout<<"-----------------Your Order List----------------\n\n";
                                for (int i = 0; i < cartt; i++)
                                {
                                    cout<<"Order Id : "<<order[i].orderId<<endl;
                                    cout<<"ProductName : "<<order[i].od.productName<<endl;
                                    cout<<"Price(Rs) : "<<order[i].od.total<<endl;
                                    cout<<"Shipping Address : "<< order[i].si.ShipAddress<<endl;
                                    cout<<"\t\t\tName : "<<order[i].customerName<<endl;
                                    cout<<"\t\t\tOrder Status : "<<order[i].status<<endl<<endl;
                                }
                        break;
                        case 4:
                        cout<<"\n------------LoggedOut SuccessFully!------------\n"<<endl;
                        break;
                        default:
                        break;
                    }
                    }while(choice1!=4);
                }
                else
                {
                    cout<<"\nPlease! Create Your Myntra ID Sir. "<<endl;
                    cout<<"Thank You!\n"<<endl;
                }
        break;

    // Create New User
        case 2: cout<<"Please Enter the Following Details to Register"<<endl<<endl;
                cn=++custCount;

                cout<<"Enter User ID:";
                cin>>ud;
                n->m[cn].userId=ud;

                cout<<"Enter Password:";
                cin>>pswd;
                n->m[cn].password=pswd;

                cout<<"Enter Customer Name:";
                cin>>cname;
                n->m[cn].customerName=cname;

                cout<<"Enter Address:";
                cin>>addr;
                n->m[cn].address=addr;
                
                cout<<"Enter Email:";
                cin>>em;
                n->m[cn].email=em;

                cout<<"Enter ShippingInfo:";
                cin>>sinf;
                n->m[cn].ShippingInfo=sinf;
                
               // n->PrintMyntraUsers();




        break;

    // Exit App
        case 3: exit(0);
        break; 
        
        default:
            break;
        }

    } while (choice!=3);

    

    return 0;

}