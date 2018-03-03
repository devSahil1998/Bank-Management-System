/*
Bank_Management_System.cpp
24-Jun-2017
Sahil
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
void Loading(int);
class Intro
{
	//Author's Intro
	const string name,date;
public:
	Intro():name("sahil"),date("24-06-2017"){};
	void display();
};
void Intro::display()  //Displays The Author's Info
{
	cout<<"Bank Management System"<<endl;
	cout<<"\n\n"<<endl;
	cout<<"Designed By "<<name<<" on  "<<date<<endl;
}
class engine           //Engine Of Management System
{
	int no,amount,depamount,withamount;
	char acctype;
	string accname;
public:
	engine():no(0),amount(0),acctype('C'),depamount(0),withamount(0),accname(""){};
	int menu();
	void newacc();
	void depacc();
	void withacc();
	void enquiryacc();
	void listacc();
	void remacc();
	void modacc();
	void exitacc();
}e1;
engine *e=new engine[1000];
int engine::menu()     //Menu Page
{
	int x;
	cout<<"Pick Up Any One Choice"<<endl;
	cout<<"1. "<<"Add New Account"<<endl;
	cout<<"2. "<<"Deposit Amount To Your Account"<<endl;
	cout<<"3. "<<"Withdraw Amount From Your Account"<<endl;
	cout<<"4. "<<"Balance Enquiry"<<endl;
	cout<<"5. "<<"All Account Holder List"<<endl;
	cout<<"6. "<<"Close An Account"<<endl;
	cout<<"7. "<<"Modify An Account"<<endl;
	cout<<"8. "<<"EXIT"<<endl;
	cin>>x;
	if(x==8)
        goto s1;
    Loading(0);
	s1:return x;
}
void engine::newacc()   //Add's New Account To Bank
{
    int a;
    cout<<"Enter Account Number:\t";
    s1:cin>>a;
    if(a==0) // Check if user entered zero as account number
    {
        cout<<"ZERO !! AIN'T NO ACCOUNT NUMBER MAN"<<endl;
        cout<<"Enter Another Account Number:\t";
        goto s1;
    }
    for(int i=0;i<1000;++i)  // check if user entered an already taken account number
    {
        if(e[i].no==a)
        {
            cout<<"CAN't CHOOSE THIS ONE MAN IT's ALREADY TAKEN"<<endl;
            cout<<"Enter Another Account Number And Please Check The Account Holder's List Once Too:\t";
            goto s1;
        }
    }
    no=a;
    cout<<"Enter Name Of The Account Holder:\t";
    cin.ignore();   // ignores newline
    getline(cin,accname);
    transform(accname.begin(), accname.end(),accname.begin(), ::toupper);   // converts account name to upper
    cout<<"Enter Type Of The Account (C/S):\t";
    cin>>acctype;
    acctype=toupper(acctype);
    cout<<"Enter Initial Amount:\t";
    cin>>amount;
}

void engine::depacc()  // deposit amount
{
    int a,z,i;
    cout<<"Enter Account Number:\t";
    cin>>a;
        for(i=0;i<1000;++i) //checks if account number in database or not
        {
            if(e[i].no==a)
            {
                z=1;
                break;
            }
            else
                z=0;
        }
        if(z=1)
        {
            int temp;
            cout<<"Welcome Back "<<e[i].accname<<endl;
            cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance is "<<e[i].amount<<endl;
            s1:cout<<"Enter Deposit amount (**It Should Be Greater Than 500 But Less Than 20,000 And Should Be Multiple Of 5**):\t";
            cin>>temp;
            if(temp<=20000 && temp>=500 && temp%5==0)
                {
                    e[i].amount=e[i].amount+temp;
                    e[i].depamount=temp;
                    cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance is: "<<e[i].amount<<endl;
                } // ternary operator prints current if user entered c otherwise savings
                else
                    {
                    cout<<"Entered Wrong Amount"<<endl;
                    goto s1;
                }
        }
        else if(z==0)
                cout<<"Sorry No Records Found"<<endl;
}
void engine::withacc()  // withdraw amount
{
    int i,a,z;
    cout<<"Enter Account Number:\t";
    cin>>a;
    for(i=0;i<1000;++i)   // checks if account number in database
        {
            if(e[i].no==a)
            {
                z=1;
                break;
            }
            else
                z=0;
        }
    if(z==1)
    {
        int temp;
        cout<<"Welcome Back "<<e[i].accname<<endl;
        cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance is "<<e[i].amount<<endl;
        s1:cout<<"Enter Withdrawing amount (**It Should Be Greater Than 500 But Less Than 50,000 And Should Be Multiple Of 5**):\t";
        cin>>temp;
        if(temp<=50000 && temp>=500 && temp%5==0 && temp<=e[i].amount)
            {
                e[i].amount=e[i].amount-temp;
                e[i].withamount=temp;
                cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance is: "<<e[i].amount<<endl;
            }
        else if(temp>50000 && temp<500 && temp%5!=0) // checks if user entered withdraw amount in wrong format
            {
                cout<<"Entered Wrong Amount"<<endl;
                goto s1;
            }
        else // checks if user has enough money
            {
                cout<<"I Don't Need To Tell You That You Must Enter An Amount Lesser Than The One Present In Your Account"<<endl;
                goto s1;
            }
    }
    else if(z==0)
        cout<<"Sorry No Records Found !!"<<endl;
    }
void engine::enquiryacc()  // mini statement
{
    int x,i,z;
    cout<<"Enter Your Account Number:\t";
    cin>>x;
    for(i=0;i<1000;++i)  // checks if account number in database
        {
            if(e[i].no==x)
            {
                z=1;
                break;
            }
            else
                z=0;
        }
    if(z==1)
        {
            cout<<"Welcome Back "<<e[i].accname<<endl;
            cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance is "<<e[i].amount<<endl;
            cout<<"Your Last Deposit Amounts To "<<((e[i].depamount==0)?0:e[i].depamount)<<endl;
            cout<<"Your Last Withdrawal Amount To "<<((e[i].withamount==0)?0:e[i].withamount)<<endl;
        }
    else if(z==0)
        cout<<"Sorry No Records Found !!"<<endl;
}
void engine::listacc()  // print's all account details present in system
{
    cout<<"************************************************************************************************************************************************************************"<<endl;
    cout<<"Account No.  |"<<"Account Holder's Name                                             |"<<"Account Type      |"<<"Total Amount"<<endl;
    cout<<"************************************************************************************************************************************************************************"<<endl;
    for(int i=0;i<1000;++i)
    {
        if(e[i].no==0)
            continue;
        else
        {
            cout<<left<<setfill(' ')<<setw(14)<<e[i].no<<left<<setfill(' ')<<setw(66)<<e[i].accname<<left<<setfill(' ')<<setw(19)<<((e[i].acctype=='C')?"Current":"Savings")<<"   "<<e[i].amount<<endl;
        }
    }
    Sleep(3000);
}
void engine::remacc()  // remove/close account
{
    int i,a,z; char ch;
    cout<<"Enter Account Number Of The Account You Want To Close:\t";
    cin>>a;
    for(i=0;i<1000;++i)  // checks if user entered a correct account number
        {
            if(e[i].no==a)
            {
                z=1;
                break;
            }
            else
                z=0;
        }
    if(z==1)
        {
            cout<<"Welcome Back Dear "<<e[i].accname<<" To Your "<<((e[i].acctype=='C')?"Current":"Savings")<<endl;
            cout<<"Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Balance Is "<<e[i].amount<<endl;
            if(e[i].amount>0)
                cout<<"Sure You Wanna Close It Cause You Got "<<e[i].amount<<" left buddy And You Haven't Withdrawn It Yet \t"<<endl;
            else
                cout<<"Sure You Wanna Close Your Account Buddy :\t"<<endl;
            cin>>ch;
            e[i].accname=""; e[i].acctype='C'; e[i].amount=0; e[i].depamount=0; e[i].no=0; e[i].withamount=0;
        }
    else if(z==0)
        cout<<"Sorry No Records Found !!"<<endl;
}
void engine::modacc()  // modify account details such as name and type
{
    int a,i,z; char ch;
    cout<<"Enter Your Account Number Whose Details You Want To Modify:\t";
    cin>>a;
    for(i=0;i<1000;++i)  //checks if entered account number in database
    {
        if(e[i].no==a)
        {
            z=1;
            break;
        }
        else
            z=0;
    }
    if(z==1)
    {
        cout<<"Welcome Back "<<e[i].accname<<" To Your "<<((e[i].acctype=='C')?"Current":"Savings")<<" Accounts"<<endl;
        cout<<"You Are About To Modify Your Details"<<endl;
        Sleep(2000);
        cout<<"Enter New Account Name:\t";
        cin.ignore(); //ignores the newline character
        getline(cin,e[i].accname);
        transform(e[i].accname.begin(),e[i].accname.end(),e[i].accname.begin(), ::toupper);  // converts account name to uppercase letters
        cout<<"Enter Your New Account Type:\t";
        cin>>e[i].acctype;
        e[i].acctype=toupper(e[i].acctype);
        cout<<"Now This "<<((e[i].acctype=='C')?"Current":"Savings")<<" Account Holder Name Is "<<e[i].accname<<endl;
    }
    else if(z==0)
        cout<<"Sorry No Records Found !!"<<endl;
}
void engine::exitacc() //exit
{
    cout<<"You Are About To Exit"<<endl;
    Sleep(300);
}
int main()
{
//Bank Management System
	Intro I;
	I.display();
	Loading(0); int i=0;
	while(true)
	{
		switch(e[i].menu())
		{
        case 1:
            {
                e[i].newacc();
                Loading(1);
                ++i;
            }
            break;
        case 2:
            {
                e1.depacc();
                Loading(0);
            }
            break;
        case 3:
            {
                e1.withacc();
                Loading(0);
            }
            break;
        case 4:
            {
                e1.enquiryacc();
                Loading(0);
            }
            break;
        case 5:
            {
                e1.listacc();
                Loading(0);
            }
            break;
        case 6:
            {
                e1.remacc();
                Loading(2);
            }
            break;
        case 7:
            {
                e1.modacc();
                Loading(3);
            }
            break;
        case 8:
            {
                e1.exitacc();
                Loading(4);
                return 0;
            }
		}
	}
return 0;
}
void Loading(int a) //Loading.....
{
    cout<<"\n\n";
	if(a==0)
	{
    for(int i=0;i<3;++i)
	{
		cout<<"\rLOADING";
		for(int j=0;j<5;++j)
		{
			Sleep(300);
			cout<<".";
		}
		Sleep(300);
		cout<<"\r            ";
	}
	}
	else if(a==1) // creating
    {
        for(int i=0;i<3;++i)
	{
		cout<<"\rCREATING";
		Sleep(700);
		cout<<"\r        ";
		Sleep(350);
	}
	Sleep(900);
	cout<<"\rCREATED !!";
	Sleep(500);
    }
    else if(a==2)  //closing
    {
        cout<<"\rCLOSING";
        cout<<"\r";
        for(int i=0;i<7;++i)
            {
                Sleep(800);
                cout<<"X";
            }
        cout<<"\r"; string s1="CLOSING";
        for(int i=0;i<7;++i)
            {
                Sleep(800);
                cout<<s1[i];
            }
        Sleep(400);
        cout<<"\r       ";
        cout<<"\rACCOUNT CLOSED !!";
        Sleep(1050);
    }
    else if(a==3) //modifying
    {
        cout<<"\rMODIFYING";
        cout<<"\r";
        for(int i=0;i<9;++i)
            {
                Sleep(800);
                cout<<"X";
            }
        cout<<"\r"; string s="MODIFYING";
        for(int i=0;i<9;++i)
            {
                Sleep(800);
                cout<<s[i];
            }
        Sleep(400);
        cout<<"\r       ";
        cout<<"\rACCOUNT DETAILS MODIFIED !!";
        Sleep(1050);
    }
    else if(a==4)  //exiting
	{
    for(int i=0;i<3;++i)
	{
		cout<<"\rEXITING";
		for(int j=0;j<3;++j)
		{
			Sleep(300);
			cout<<".";
		}
		Sleep(300);
		cout<<"\r          ";
	}
	}
	if(a!=4)
    {
        system("CLS");
        cout<<"BANK MANAGEMENT SYSTEM..."<<endl;
        cout<<"\n";
    }
    else
    {
        system("CLS");
        cout<<"THANKS YOU ..."<<endl;
    }
}
