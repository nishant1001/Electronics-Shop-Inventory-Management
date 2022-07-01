#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
using namespace std;
int main()
{
    MYSQL* conn;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"192.168.62.48","admin","admin","dbms_theory_project",0,NULL,0);
    if(conn)
        cout<<"Connected";
    else
        cout<<"Not Connected";

    int ch,temp;
float r;
//User - Interface
cout<<"\nEnter 1, if you are admin";
cout<<"\nEnter 2, if you are a customer";
cout<<"\nEnter your choice - ";
cin>>temp;

if (temp==1)
{
    string password;
    cout<<"\nEnter Password - ";
    cin>>password;
    if (password=="admin")
    {
        cout<<"\nEnter 1, To Add New Order";
        cout<<"\nEnter 2, To Add New Products";
        cout<<"\nEnter 3, To Add New Employee";
        cout<<"\nEnter 4, To see previous Orders";
        cout<<"\nEnter 5, To see Products Details";
        cout<<"\nEnter 6, To see Employees Details";
        cout<<"\nEnter 7, To see customer Details";
        cout<<"\nEnter your choice - ";
        cin>>ch;
    switch(ch)
    {
    case 1:
            {
            int id,cust_id,amount,quantity,emp_id;
            string cust_name,product_name,cust_add,cust_phone;
            cout<<"\nEnter id - ";
            cin>>id;
            cout<<"\nEnter Customer ID - ";
            cin>>cust_id;
            cout<<"\nEnter Customer Name - ";
            cin>>cust_name;
            cout<<"\nEnter Customer Address - ";
            cin>>cust_add;
            cout<<"\nEnter Customer Phone No. - ";
            cin>>cust_phone;
            cout<<"\nEnter Product Name - ";
            cin>>product_name;
            cout<<"\nEnter Quantity - ";
            cin>>quantity;
            cout<<"\nEnter Price - ";
            cin>>amount;
            cout<<"Enter Employee Id - ";
            cin>>emp_id;
            int qstate1=0,qstate2=0;
            stringstream ss1,ss2;
            if (conn)
            {
                ss1 << "insert into customer_order values ("<<id<<","<<cust_id<<",'"<<cust_name<<"','"<<product_name<<"',"<<quantity<<","<<amount<<","<<emp_id<<")";
                ss2 << "insert into customer values ("<<cust_id<<",'"<<cust_name<<"','"<<cust_add<<"','"<<cust_phone<<"')";
                string query1 = ss1.str();
                string query2 = ss2.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                const char* q2 = query2.c_str();
                qstate2 = mysql_query(conn, q2);
                if (qstate1 == 0 && qstate2==0)
                    cout<<"Record Updated...";
                else
                    cout<<"\nFailed to Update...";
            }
            }
            break;
    case 2:
            {
            int id,quantity,price;
            string name;
            cout<<"\nEnter id - ";
            cin>>id;
            cout<<"\nEnter Name - ";
            cin>>name;
            cout<<"\nEnter Quantity - ";
            cin>>quantity;
            cout<<"\nEnter Price - ";
            cin>>price;
            int qstate1=0;
            stringstream ss1;
            if (conn)
            {
                ss1 << "insert into products values ("<<id<<",'"<<name<<"',"<<quantity<<","<<price<<")";
                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                if (qstate1 == 0)
                    cout<<"Record Updated...";
                else
                    cout<<"\nFailed to Update...";
            }
            }
            break;
    case 3:
            {
            int id;
            string name,address,phone;
            cout<<"\nEnter id - ";
            cin>>id;
            cout<<"\nEnter Name - ";
            cin>>name;
            cout<<"\nEnter Address - ";
            cin>>address;
            cout<<"\nEnter Phone - ";
            cin>>phone;
            int qstate1=0;
            stringstream ss1;
            if (conn)
            {
                ss1 << "insert into employee values ("<<id<<",'"<<name<<"','"<<address<<"','"<<phone<<"')";
                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                if (qstate1 == 0)
                    cout<<"Record Updated...";
                else
                    cout<<"\nFailed to Update...";
            }
            }
            break;
    case 4:
            {
            MYSQL_ROW row;
            MYSQL_RES* res;
            if (conn)
            {
                int qstate=mysql_query(conn,"select * from customer_order");
                if (!qstate)
                {
                    res=mysql_store_result(conn);
                    cout<<"\nId\t  "<<"Customer Id\t"<<"Customer Name\t     "<<"Product Name\t"<<"Quantity\t"<<"Amount\t"<<"Employee ID\n";
                    cout<<"___________________________________________________________________________________________________\n\n";
                    while(row=mysql_fetch_row(res))
                        cout<<row[0]<<"\t  "<<row[1]<<"\t\t"<<row[2]<<"\t\t     "<<row[3]<<"\t\t"<<row[4]<<"\t\t"<<row[5]<<"\t"<<row[6]<<endl;
                }
                else
                    cout<<"\nNo record found";
            }
            }
            break;
    case 5:
            {
            MYSQL_ROW row;
            MYSQL_RES* res;
            int qstate1=0;
            stringstream ss1;
            if (conn)
            {
                ss1 << "select * from products";
                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                if (qstate1 == 0)
                {
                    res=mysql_store_result(conn);
                    cout<<"\nId\t  "<<"Name\t\t"<<"Quantity\t   "<<"Price\n";
                    cout<<"------------------------------------------------\n";
                    while(row=mysql_fetch_row(res))
                        cout<<row[0]<<"\t  "<<row[1]<<"\t\t"<<row[2]<<"\t\t   "<<row[3]<<endl;
                }
                else
                    cout<<"\nNo record found";
            }
            }
            break;
    case 6:
            {
            MYSQL_ROW row;
            MYSQL_RES* res;
            int qstate1=0;
            stringstream ss1;
            if (conn)
            {
                ss1 << "select * from employee";
                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                if (qstate1 == 0)
                {
                    res=mysql_store_result(conn);
                    cout<<"\nId\t  "<<"Name\t\t"<<"Address\t\t   "<<"Phone\n";
                    cout<<"-----------------------------------------------------\n";
                    while(row=mysql_fetch_row(res))
                        cout<<row[0]<<"\t  "<<row[1]<<"\t"<<row[2]<<"\t\t   "<<row[3]<<endl;
                }
                else
                    cout<<"\nNo record found";
            }
            }
            break;
    case 7:
            {
            MYSQL_ROW row;
            MYSQL_RES* res;
            int qstate1=0;
            stringstream ss1;
            if (conn)
            {
                ss1 << "select * from customer";
                string query1 = ss1.str();
                const char* q1 = query1.c_str();
                qstate1 = mysql_query(conn, q1);
                if (qstate1 == 0)
                {
                    res=mysql_store_result(conn);
                    cout<<"\nId\t  "<<"Name\t\t"<<"Address"<<"\t\tPhone\n";
                    cout<<"--------------------------------------------------\n";
                    while(row=mysql_fetch_row(res))
                        cout<<row[0]<<"\t  "<<row[1]<<"    \t"<<row[2]<<"     \t"<<row[3]<<endl;
                }
                else
                    cout<<"\nNo record found";
            }
            }
            break;
    default:cout<<"Wrong Choice...";
    }
    }
    else
        cout<<"Wrong Password...";
}
else if (temp==2)
{
    cout<<"\nEnter the name you want to search in database - ";
    MYSQL_ROW row;
    MYSQL_RES* res;
    string name1;
    cin>>name1;
    int qstate1=0;
    stringstream ss1;
    if (conn)
    {
        ss1 << "select * from customer_order where customer_name='"<<name1<<"'";
        string query1 = ss1.str();
        const char* q1 = query1.c_str();
        qstate1 = mysql_query(conn, q1);
        if (qstate1 == 0)
        {
            res=mysql_store_result(conn);
            cout<<"\nId\t  "<<"Customer Id\t"<<"Customer Name\t     "<<"Product Name\t"<<"Quantity\t"<<"Amount\t\t"<<"Employee ID\n";
            cout<<"___________________________________________________________________________________________________________\n\n";
            while(row=mysql_fetch_row(res))
                cout<<row[0]<<"\t  "<<row[1]<<"\t\t"<<row[2]<<"\t\t     "<<row[3]<<"\t\t"<<row[4]<<"\t\t"<<row[5]<<"\t\t"<<row[6]<<endl;
        }
        else
            cout<<"\nNo record found";
    }
}
else
    cout<<"\nWrong choice...";
cout<<endl;
return 0;
}
