//**********************************************************
// PROJECT SALES MANAGEMENT
//**********************************************************

//**********************************************************
// INCLUDED HEADER FILES
//**********************************************************

#include <iostream>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

using namespace std;

//**********************************************************
// CLASS NAME : Menu
// DETAILS : IT CONTROLLS OVER ALL THE FUNCTIONS
//**********************************************************

class menu
{
public :
    void main_menu(void) ;
private :
    void edit_menu(void) ;
} ;


//**********************************************************
// CLASS NAME : Product
// DETAILS : IT CONTROLLS OVER ALL THE FUNCTIONS
// RELATED TO PRODUCT ITEMS
//**********************************************************

class product
{
public :
    void add_item(void) ;
    void delete_item(void) ;
    void modify_item(void) ;
    void list_of_item(void) ;
    void purchase(void) ;
private :
    int last_code(void) ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    void sort(void) ;

    int itemcode ;
    char itemname[30] ;
    float itemcost, itemprice ;
} ;


//**********************************************************
// CLASS NAME : Account
// DETAILS : IT CONTROLLS OVER ALL THE FUNCTIONS
// RELATED TO MAKING BILL
//**********************************************************

class account
{
public :
    void bill_list(void) ;
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_itemcode, char *t_itemname, float t_qty,
                  float t_cost, float t_price) ;
private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, quantity ;
    char name[30] ;
} ;


//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: main_menu(void)
{
    char ch ;
    while (1)
    {

        cout
                <<"*************************************************************" ;

        cout
                <<"*************************************************************" ;

        cout <<"S A L E S M A N A G E M E N T" ;

        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;

        cout <<"1: PURCHASE PRODUCTS" ;
        cout <<"2: LIST OF PRODUCTS" ;

        cout <<"3: EDIT PRODUCTS FILE" ;

        cout <<"4: BILLS REPORT" ;
        cout <<"0: QUIT" ;
        cout <<"Enter Your Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.purchase() ;
        }
        else if (ch == '2')
        {
            product p ;
            p.list_of_item() ;
        }
        else if (ch == '3')
            edit_menu() ;
        else if (ch == '4')
        {
            account a ;
            a.bill_list();
        }
        else if (ch == '0')
            break ;
    }
}


//**********************************************************
// THIS FUNCTION CREATE EDIT MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: edit_menu(void)
{
    char ch ;
    while (1)
    {

        cout
                <<"*************************************************************" ;
        cout
                <<"*************************************************************" ;
        cout <<"E D I T M E N U" ;
        cout <<"~~~~~~~~~~~~~~~~" ;;
        cout <<"1: ADD PRODUCTS" ;;
        cout <<"2: MODIFY PRODUCTS" ;;
        cout <<"3: DELETE PRODUCTS" ;;
        cout <<"0: EXIT" ;;
        cout <<"Enter Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.add_item() ;
            break ;
        }
        else if (ch == '2')
        {
            product p ;
            p.modify_item() ;
            break ;
        }
        else if (ch == '3')
        {
            product p ;
            p.delete_item() ;
            break ;
        }
        else if (ch == '0')
            break ;
    }
}


//**********************************************************
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// PRODUCT FILE (PRODUCT.DAT).
//**********************************************************

int product :: last_code(void)
{
    fstream file("file.txt") ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)))
        t = itemcode ;
    file.close() ;
    return t ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE ITEMS
//**********************************************************

void product :: list_of_item(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0) ;
    int row = 6 , found = 0 ;
    cout <<"LIST OF ITEMS" ;
    cout <<"ITEM CODE ITEM NAME ITEM COST ITEM PRICE" ;
    cout <<"***********************************************************" ;
    while (file.read((char *) this, sizeof(product)))
    {
        found = 1 ;;
        cout <<itemcode ;
        ;
        cout <<itemname ;
        ;
        cout <<itemcost ;
        ;
        cout <<itemprice ;
        if ( row == 22 )
        {
            row = 5 ;
            cout <<"Press any key to continue..." ;
            getche() ;
            cout <<"LIST OF ITEMS" ;
            cout <<"ITEM CODE ITEM NAME ITEM COST ITEM PRICE" ;
            cout <<"***********************************************************"
                    ;
        }
        else
            row++ ;
    }
    if ( !found )
    {
        cout <<"\7Records not found" ;
    }
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}


//***********************************************************
// THIS FUNCTION ADD RECORDS IN THE PRODUCT.DAT (PRODUCT.DAT)
//***********************************************************

void product :: add_item(void)
{
    int tcode, valid ;
    char ch, t_itemcost[10], t_itemprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
    {
        cout <<"<0>=Exit" ;
        cout <<"ADDITION OF PRODUCTS" ;
        cout <<"********************" ;
        cout <<"Item Code : " <<tcode ;
        cout <<"Item Name : " ;
        cout <<"Item Cost : " ;
        cout <<"Item Price : " ;
        do
        {
            valid = 1 ;
                                                cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
            cout <<"Item Name : " ;
            gets(itemname) ;
            strupr(itemname) ;
            if (itemname[0] == '0')
                return ;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
            {
                valid = 0 ;
                cout <<"\7 Range = 1..20" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
                                                cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
            cout <<"Item Cost : " ;
            gets(t_itemcost) ;
            itemcost = atof(t_itemcost) ;
            if (t_itemcost[0] == '0')
                return ;
            if (itemcost < 1 || itemcost > 800)
            {
                valid = 0 ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;
                                                cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
            cout <<"Item Price : " ;
            gets(t_itemprice) ;
            itemprice = atof(t_itemprice) ;
            if (t_itemprice[0] == '0')
                return ;
            if (itemprice < itemcost || itemprice > 1000)
            {
                valid = 0 ;
                cout <<"\7 Range = " <<itemcost <<"..1000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
                                                cout <<"Do you want to save this record (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            itemcode = tcode ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(product)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
                                                cout <<"Do you want to add more records (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: display_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            cout <<"Item Code : "<<itemcode ;
            cout <<"Item Name : "<<itemname ;
            cout <<"Item Cost : "<<itemcost ;
            cout <<"Item Price : "<<itemprice ;
            break ;
        }
    }
    file.close() ;
}


//**********************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

int product :: item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}


//**********************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

int product :: recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}


//**********************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO DELETE RECORD FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: delete_item(void)
{
    char t_code[5], ch ;
    int t, tcode ;
    cout <<"Press <ENTER> to see the list" ;
    cout <<"Enter Item Code of the item to be deleted : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
                cout <<"Press <ENTER> to Exit" ;
        cout <<"Enter Item Code of the item to be deleted : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    if (!item_found(tcode))
    {
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
                cout <<"Do you want to delete this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;
    cout <<"\7Record Deleted" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_itemcost[10], t_itemprice[10], t_itemcode[5] ;
    cout <<"<0>=Exit" ;
    cout <<"Item Code : " ;
    cout <<"Item Name : " ;
    cout <<"Item Cost : " ;
    cout <<"Item Price : " ;
    do
    {;
                cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
                                cout <<"ENTER ITEM CODE TO ADD IN THE MENU" ;
        cout <<"Item Code : " ;
        gets(t_itemcode) ;
        t_code = atoi(t_itemcode) ;
        if (t_code == 0)
            return ;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            cout <<"\7 CODE ALREADY GIVEN" ;
            getch() ;
        }
    }
    do
    {;
                cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
                                cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
        cout <<"Item Name : " ;
        gets(itemname) ;
        strupr(itemname) ;
        if (itemname[0] == '0')
            return ;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0 ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {;
                cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
                                cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
        cout <<"Item Cost : " ;
        gets(t_itemcost) ;
        itemcost = atof(t_itemcost) ;
        if (t_itemcost[0] == '0')
            return ;
        if (itemcost < 1 || itemcost > 800)
        {
            valid = 0 ;
            cout <<"\7 Range = 1..800" ;
            getch() ;
        }
    }
    do
    {;
                cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
                                cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
        cout <<"Item Price : " ;
        gets(t_itemprice) ;
        itemprice = atof(t_itemprice) ;
        if (t_itemprice[0] == '0')
            return ;
        if (itemprice < itemcost || itemprice > 1000)
        {
            valid = 0 ;
            cout <<"\7 Range = " <<itemcost <<"..1000" ;
            getch() ;
        }
    }
    do
    {
                                cout <<"Do you want to save this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    itemcode = t_code ;
    cout <<"\n" <<itemname ;
    cout <<itemcost ;
    cout <<itemprice ;
    getch() ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::out | ios::ate) ;
    int location ;
    location = (recno-1) * sizeof(product) ;
    file.seekp(location) ;
    file.write((char *) this, sizeof(product)) ;
    file.close() ;
    sort() ;
    cout <<"\7Record Modified" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: modify_item(void)
{
    char t_code[5], ch ;
    int t, tcode ;
    cout <<"Press <ENTER> to see the list" ;
    cout <<"Enter Item Code of the item to be Modify : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
                cout <<"Press <ENTER> to Exit" ;
        cout <<"Enter Item Code of the item to be modify : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    if (!item_found(tcode))
    {
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        cout <<"Do you want to Modify this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    modify_record(tcode) ;
}


//****************************************************************
// THIS FUNCTION SORT THE RECORD IN THE PRODUCT FILE (PRODUCT.DAT)
// ACCORDING TO THE CODE NOS.
//****************************************************************

void product :: sort(void)
{
    int i=0,j ;
    product arr[100] ;
    product temp ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(product)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("PRODUCT.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(product)) ;
    file.close() ;
}


//**********************************************************
// THIS FUNCTION PURCHASES THE PRODUCT ITEM IN THE MENU
//**********************************************************

void product :: purchase(void)
{
    account a ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch;
    float t_quantity ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_itemcode ;
    float t_qty, t_cost, t_price ;
    char t_itemname[30] ;
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    do
    {
        cout <<"Press <ENTER> to see the list" ;
        cout <<"Enter Item Code of the item to be Purchase : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_item() ;
                        cout <<"Press <ENTER> to Exit" ;
            cout <<"Enter Item Code of the item to be Purchase : " ;
            gets(t_code) ;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
        if (!item_found(tcode))
        {
            cout <<"\7Item Code not found" ;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
        display_record(tcode) ;
        do
        {
            valid = 1 ;
                                                cout <<"ENTER QUANTITY TO BE PURCHASE IN Kg." ;
            cout <<"Quantity : " ;
            cin>>t_quantity ;
            qty=t_quantity ;
            if (t_quantity == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0 ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
                        cout <<"Do you want to cancel this purchase (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(product)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode ;
                    strcpy(t_itemname,itemname) ;
                    t_cost = itemcost ;
                    t_price = itemprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno,t_itemcode,t_itemname,t_qty,t_cost,t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {
                        cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}


//**********************************************************
// THIS FUNCTION RETURNS THE BILL NO. OF THE LAST RECORD
// IN THE BILL FILE (BILL.DAT)
//**********************************************************

int account :: last_billno(void)
{
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}


//**********************************************************
// THIS FUNCTION ADDS THE RECORD IN THE BILL FILE (BILL.DAT)
//**********************************************************

void account :: add_bill(int t_billno, int t_itemcode, char
t_itemname[30], float t_qty, float t_cost, float t_price)
{
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    dd = d1 ;
    mm = m1 ;
    yy = y1 ;
    code = t_itemcode ;
    strcpy(name,t_itemname) ;
    cost = t_cost ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account)) ;
    file.close() ;
}


//**********************************************************
// THIS FUNCTION PREPARES AND DISPLAYS THE BILL FOR THE
// GIVEN BILL NO. ACCORDING TO PURCHASES MADE.
//**********************************************************

void account :: prepare_bill(int t_billno)
{
    struct date d;
    int d1, m1, y1 ;
    getdate(&d);
    d1 = d.da_day ;
    m1 = d.da_mon ;
    y1 = d.da_year ;
    float total=0.0, total_bill=0.0 ;
    cout <<"CUSTOMER BILL" ;
    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
    cout <<"ITEMS PURCHASED" ;
    cout <<"+++++++++++++++" ;
    cout <<"Item code Item name Cost Price Qty Total"
            ;
    cout <<"------------------------------------------------------------"
            ;
    int row=11 ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(account)) !=0 )
    {
        if (billno == t_billno)
        {
            cout <<"BILL NO. # " <<billno ;
            cout <<"===============" ;
            ;
            cout <<code ;
            ;
            cout <<name ;
            ;
            cout <<cost ;
            ;
            cout <<price ;
            ;
            cout <<quantity ;
            total = quantity * price ;
            ;
            cout <<total ;
            total_bill = total_bill + total ;
            row++ ;
        }
    }
    file.close() ;1) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE BILLS
//**********************************************************

void account :: bill_list(void)
{
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;
    cout <<"LIST OF BILLS" ;
    cout <<"Billno. Date Item Code Item name Cost Pri Qty Total" ;
    cout
            <<"===========================================================================" ;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                ;
                cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            };
            cout <<billno ;
        }
        flag = 1 ;
        ;
        cout <<dd <<"/" <<mm <<"/" <<yy ;
        ;
        cout <<code ;
        ;
        cout <<name ;
        ;
        cout <<cost ;
        ;
        cout <<price ;
        ;
        cout <<quantity ;
        total = quantity * price ;
        ;
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
            cout <<"Press any key to continue..." ;
            getche() ;
            cout <<"LIST OF BILLS" ;
            cout <<"Billno. Date Item Code Item name CostPrice Qty Total" ;
            cout
                    <<"===========================================================================" ;
        }
        prev_billno = billno ;
    }
    row++ ;
    ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
    if ( !found )
    {
        cout <<"\7Records not found" ;
    }
    cout <<"Page no. : " <<pageno ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}


//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************

void main(void)
{
    menu m ;
    m.main_menu() ;
}
