#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<dos.h>

//****************************************************************
// CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno, deposit, withdraw, x;
	char name[50];
	char type;
	public:
	void create_account()
	{
		gotoxy(12,5);cout<<"====NEW ACCOUNT ENTRY FORM====\n";
		gotoxy(12,7);cout<<"Enter The account Number : ";
		cin>>acno;
		gotoxy(12,9);cout<<"Enter The Name of The account Holder: ";
		gets(name);
		gotoxy(12,11);cout<<"Enter Type of The account (C/S) : ";
		cin>>type;
		type=toupper(type);
		gotoxy(12,13);
		cout<<"Enter Initial amount>=500 for Saving & >=1000 for Current :";
		cin>>deposit;
		gotoxy(12,15);cout<<"Your Account Created Successfully ..";
	}
	void show_account()
	{
		gotoxy(12,4);cout<<"-------ACCOUNT STATUS-------\n";
		gotoxy(12,6);cout<<"Account No.                 : "<<acno;
		gotoxy(12,8);cout<<"Account Holder Name         : "<<name;
		gotoxy(12,10);cout<<"Type of Account             : "<<type;
		gotoxy(12,12);cout<<"Balance amount              : "<<deposit;
	}
	void modify_account()
	{
		gotoxy(12,16);cout<<"Account No.                : "<<acno;
		gotoxy(12,18);cout<<"Modify Account Holder Name : ";
		gets(name);
		gotoxy(12,20);cout<<"Modify Type of Account     : ";cin>>type;
		gotoxy(12,22);cout<<"Modify Balance amount      : ";cin>>deposit;
	}
	void dep(int x)
	{
		deposit+=x;
	}
	void draw(int x)
	{
		deposit-=x;
	}
	void report()
	{
		gotoxy(8,13);cout<<acno<<"\t\t"<<name<<"\t\t"<<type<<"\t\t" 			<<deposit<<endl;
	}
	int retacno()
	{
		return acno;
	}
	float retdeposit()
	{	return deposit;
	}
	char rettype()
	{
		return type;
	}
};		//class ends here

//***************************************************************
// 	global declaration for stream object, object
//****************************************************************
fstream fp;
account ac;

//***************************************************************
// 	function for introduction
//****************************************************************
void welcome()
{	clrscr();
	int x;
	/*for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	delay(500);*/
	gotoxy(30,12);
	cout<<"LOADING....";
	int u=0;
	for(int i=1;i<=10;i++)
	{
		gotoxy(30+u,13);
		delay(500);
		cout<<"ÛÛ";
		u=u+2;
		gotoxy(52,13);
		cout<<i<<"0%";
	}
	gotoxy(35,14);
	cout<<"COMPLETE ";
	delay(200);
	cout<<"!";
	delay(200);
	cout<<"!";
	delay(300);
	gotoxy(50,22);
	cout<<"Press Any Key To Continue";
	gotoxy(0,0);
	getch();
	clrscr();
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	delay(500);
	gotoxy(12,5);
	cout<<"******************** W E L C O M E*********************";
	gotoxy(19,9);
	cout<<"B A N K  M A N A G E M E N T  S Y S T E M";
	gotoxy(19,13);
	cout<<" D E V E L O P E D  B Y : ";
	gotoxy(44,13);
	cout<<" YASH TOMAR";
	gotoxy(42,23);
	cout<<" *** PRESS ANY KEY TO CONTINUE ***";
	getch();
}

//****************************************************************
// 	function to write in file
//****************************************************************
void write_account()
{	clrscr();
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	fp.open("account.dat",ios::out|ios::app);
	ac.create_account();
	fp.write((char*)&ac,sizeof(account));
	fp.close();
}

//****************************************************************
// 	function to read specific record from file
//****************************************************************
void display_sp()
{
	clrscr();
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	int n;
	gotoxy(12,4);cout<<"====BALANCE DETAILS====\n";
	gotoxy(12,6);cout<<"Enter the Account Number : ";
	cin>>n;
	int flag=0;
	fp.open("account.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		gotoxy(12,10);
		cout<<"Account Number does not exist\n";
	}
	getch();
}

//***************************************************************
// 	function to modify record of file
//****************************************************************

void modify_account()
{
	clrscr();
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	int no,found=0;
	gotoxy(12,5);cout<<"====MODIFY RECORD====\n";
	gotoxy(12,7);cout<<"Enter the Account No. : ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==no)
		{
			clrscr();
			for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"#";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"#";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"#";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"#";
			delay(5);
		}
			ac.show_account();
			gotoxy(12,14);cout<<"----Enter the New Details----\n";
			ac.modify_account();
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			gotoxy(12,24);cout<<"\t Record Updated\n";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		gotoxy(12,10);
		cout<<" Record Not Found \n";
	}
	getch();
}
//***************************************************************
// 	function to delete record of file
//****************************************************************

void delete_account()
{     	clrscr();
	int no, x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	gotoxy(12,5);cout<<"\t===Delete Record====\n";
	gotoxy(12,7);cout<<"\tEnter The Account No. : ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()!=no)
		{
			fp2.write((char*)&ac,sizeof(account));
		}
	}
	fp2.close();
	fp.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	gotoxy(12,9);cout<<"\tRecord Deleted ..\n";
	getch();
}

//***************************************************************
// 	function to display all accounts deposit list
//****************************************************************
void display_all()
{	clrscr();
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	fp.open("account.dat",ios::in);
	if(!fp)
	{
		gotoxy(12,5);cout<<" ERROR!!! FILE COULD NOT BE OPEN \n";
		getch();
		return;
	}
	gotoxy(15,5);cout<<"\tACCOUNT HOLDER LIST\n";
	gotoxy(8,7);cout<<"=============================================================\n";
	gotoxy(8,9);cout<<"A/c no.\t\tNAME\t\tType\t\tBalance\n";
	gotoxy(8,11);cout<<"=============================================================\n";
	while(fp.read((char *)&ac,sizeof(account)))
	{
		ac.report();
	}
	fp.close();
	getch();
}

//***************************************************************
// 	function to deposit and withdraw amounts
//****************************************************************
void deposit_withdraw(int option)
{	clrscr();
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"#";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"#";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"#";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"#";
		delay(5);
	}
	int no,found=0,amt;

	gotoxy(12,4);cout<<"====ACCOUNT TRANSCATION FORM====\n";
	gotoxy(12,6);cout<<"Enter The account No. : ";
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==no)
		{
			ac.show_account();
			if(option==1)
			{
				gotoxy(12,20);
				cout<<"Enter The amount to DEPOSIT : ";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				gotoxy(12,20);
				cout<<"Enter The amount to WITHDRAW : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 &&ac.rettype()=='S')||(bal<1000&&ac.rettype()=='C'))
					cout<<"\nInsufficient balance";
				else
					ac.draw(amt);
			}
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			gotoxy(12,22);cout<<"\t Record Updated \n";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		gotoxy(12,10);
		cout<<" Record Not Found \n";
	}
	getch();
}

//***************************************************************
// 	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{	char ch;
	textcolor(YELLOW);
	textbackground(BLUE);
	welcome();
	do
	{
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"#";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"#";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"#";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"#";
			delay(5);
		}
		gotoxy(12,5);cout<<"MAIN MENU\n";
		gotoxy(12,7);cout<<"01. NEW ACCOUNT\n";
		gotoxy(12,9);cout<<"02. DEPOSIT AMOUNT\n";
		gotoxy(12,11);cout<<"03. WITHDRAW AMOUNT\n";
		gotoxy(12,13);cout<<"04. BALANCE ENQUIRY\n";
		gotoxy(12,15);cout<<"05. ALL ACCOUNT HOLDER LIST\n";
		gotoxy(12,17);cout<<"06. CLOSE AN ACCOUNT\n";
		gotoxy(12,19);cout<<"07. MODIFY AN ACCOUNT\n";
		gotoxy(12,21);cout<<"08. EXIT\n";
		gotoxy(12,23);cout<<"Select Your Option (1-8) : ";
		ch=getch();
		switch(ch)
		{
			case '1': write_account();
				  break;
			case '2': deposit_withdraw(1);
				  break;
			case '3': deposit_withdraw(2);
				  break;
			case '4': display_sp();
				  break;
			case '5': display_all();
				  break;
			case '6': delete_account();
				  break;
			case '7': modify_account();
				  break;
			case '8': exit(0);
		}
	}while(ch!='8');
}

//***************************************************************
//		END OF PROJECT
//***************************************************************
