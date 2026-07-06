 #include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
const int arraysize=10;
string user[arraysize];
string password[arraysize];
string role[arraysize];
float balance[arraysize];
int count=0;
void topheader()
{
	//topheader of bank mengement system app
	cout<<"                     ||======================================||"<<endl;
	cout<<"                     ||                                      ||"<<endl;
	cout<<"                     ||                                      ||"<<endl;
	cout<<"                     ||          Bank mangement system       ||"<<endl;
	cout<<"                     ||                                      ||"<<endl;
	cout<<"                     ||                                      ||"<<endl;
	cout<<"                     ||======================================||"<<endl;
	cout<<"                                                               "<<endl;
	cout<<"                                                               "<<endl;
	
}
void loduser()
{
	ifstream infile("user.txt");
	if(infile.is_open())
		while(infile>>user[count]>>password[count]>>role[count]>>balance[count])
	{
		count++;
	 if(count>=arraysize)
		break;
	}
	else
	{
		cout<<"Error "<<endl;
		return;
	}
	infile.close();
}
void saveuser()
{
	ofstream outfile("user.txt");
	if(outfile.is_open())
	for(int i=0;i<count;i++)
	{
		outfile<<user[i]<<" "<<password[i]<<" "<<role[i]<<" "<<balance[i]<<endl;
	}
	else
	{
		cout<<"Error "<<endl;
	}
	outfile.close();
}
int loginmenu()
{
	int option;
	cout<<"for sinup press key (1)"<<endl;
	cout<<"for login press key (2)"<<endl;
	cout<<"for exit press key (3)"<<endl;
	cout<<"Chose anyoption obove"<<endl;
	cin>>option;
	return option;
}
string signin(string name,string pass)
{
	for(int index=0;index<count;index++)
	{
	if(user[index]==name&&password[index]==pass)
	{
	return role[index];
	}
}
	return "undefined";
}
bool sinup(string name,string pass,string roles)
{
	bool ispresent=false;
	for(int index=0;index<count;index++)
	{
		if(user[index]==name)
		{
			ispresent=true;
			break;
		}
	}
	if(ispresent)
	{
		system("cls");
		cout<<"Already exist user"<<endl;
		return false;
	}
	else if (count<arraysize)
	{
		user[count]=name;
		password[count]=pass;
		role[count]=roles;
		balance[count]=0;
		count++;
		saveuser();
		return true;
	}
	else
	{
		cout<<"User array is full"<<endl;
		return false;
	}
}
void clearscreen()
{
	cout<<endl<<"Press Anay key to countinue....."<<endl;
	getch();
	system("cls");
}									//------user_start----//
int usermenu()
{
	int option;
	cout<<"For Balance check press...(1)"<<endl;
	cout<<"For Deposit Money press...(2)"<<endl;
	cout<<"For widhtdraw Money press (3)"<<endl;
	cout<<"For logout Press......... (4)"<<endl;
	cout<<"Option Choose : ";
	cin>>option;
	return option;
}
void userinterface(int userindex)
{
	int option=0;
	while(option!=4)
	{
		option=usermenu();
		if(option==1)
		{
			system("cls");
			cout<<"------------------"<<endl;
			cout<<"Currunt balance : "<<balance[userindex]<<endl;
			cout<<"------------------"<<endl;
		}
		else if(option==2)
		{
			float amount;
			cout<<"Enter the amount to deposit : ";
			cin>>amount;
			system("cls");
			balance[userindex]=balance[userindex]+amount;
			cout<<"-------------------------------"<<endl;
			cout<<endl<<"<---Amount deposited : "<<amount<<"--->"<<endl<<"<---new balance is : "<<balance[userindex]<<"--->"<<endl;
			cout<<"-------------------------------"<<endl;
			saveuser();
		}
		else if(option==3)
		{
			float amount;
			cout<<endl<<"Enter the widhdraw amount : ";
			cin>>amount;
			system("cls");
			if(amount<=balance[userindex])
			{
				balance[userindex]=balance[userindex]-amount; 
				cout<<"Succwsfully widht draw "<<amount<<endl;
				cout<<"-------------------------------"	<<endl;
				cout<<endl<<"<---Now new amount is : "<<balance[userindex]<<"--->"<<endl;
				cout<<"-------------------------------"<<endl;
				saveuser();
			}
			else
			{
				cout<<"------------------------------------------"<<endl;
				cout<<"<---Balance is less than input amount---> "<<endl;
				cout<<"------------------------------------------"<<endl;
			}
		}
		else if (option==4)
		{
			clearscreen();
		}
		//------user_end----//
	}
}
int adminmenu()			//--------------admin-----------//
{
	int option;
	cout<<"For View users .....(1)"<<endl;
	cout<<"For Delete user ....(2)"<<endl;
	cout<<"For Change user role(3)"<<endl;
	cout<<"For Logout press ...(4)"<<endl;
	cout<<"Anay option Chose  : ";
	cin>>option;
	return option;
}
void viewalluser()
{
	cout<<"All user "<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<"Username : "<<user[i]<<"Password : "<<password[i]<<" Role : "<<role[i]<<" Balance : "<<balance[i]<<endl;
		 
	}
}
bool deleteuser(string username)
{
	for(int i=0;i<count;i++)
	{
		if(user[i]==username)
		{
			for(int j=i;j<count-1;j++)
			{
				user[j]=user[j+1];
				password[j]=password[j+1];
				role[j]=role[j+1];
				balance[j]=balance[j+1];
			}
		}
		count--;
		saveuser();
		cout<<"user"<<username<<"succesfully deleted "<<endl;
		clearscreen();
		return true;
	}
		cout<<"Not Found user"<<endl;
	return false;
}
bool userole(string username,string newrole)
{
	for(int i=0;i<count;i++)
	{
		if(user[i]==username)
		{
			role[i]=newrole;
			saveuser();
			cout<<"New Role is :"<<newrole<<endl;
			return true;
		}
	}
	cout<<"User not found "<<endl;
	return false;
}
void admininterface()
{
	int adminoption;
	while(true)
	{
		adminoption=adminmenu();
		if(adminoption==1)
		{
			viewalluser();
		}
		else if(adminoption==2)
		{
			string username;
			cout<<"Enter the name you want to delete : ";
			cin>>username;
			deleteuser(username);
		}
		else if(adminoption==3)
		{
			string username,newrole;
			{
				cout<<"Enter the name you want to change role : ";
				cin>>username;
				cout<<"Enter new role (admin or user ) : ";
				cin>>newrole;
				userole(username,newrole);
			}
		}
		else if(adminoption==4)
		{
		cout<<"logout"<<endl;
		clearscreen();
		break;
		}
		clearscreen();
	}												
}
				//-----admin_end---//
int main()
{
	int loginoption;
	string name,pass,roleinput;
	loduser();
	while(true)
	{
		topheader();
		loginoption=loginmenu();
		if(loginoption==1)
		{
			cout<<"sinup please...."<<endl;
			cout<<"Enter your name : ";
			cin>>name;
			cout<<"Enter the pasword : ";
			cin>>pass;
			cout<<"User or Admin : ";
			cin>>roleinput;
			if(sinup(name,pass,roleinput))
			{
				system("cls");
				cout<<"successfully sinup....."<<endl;
				clearscreen();
			}
		}
		else if(loginoption==2)
		{
			cout<<"Plese Login...."<<endl;
			cout<<"Enter the name : ";
			cin>>name;
			cout<<"Enter login password : ";
			cin>>pass;
			system("cls");
			string userrole=signin(name,pass);
			if(userrole=="undefined")
			{
				cout<<"Please Try again some mistake.....etc"<<endl;	
			}
			else if(userrole=="admin")
			{
				cout<<"Successfully login....."<<endl;
				cout<<"-------------------"<<endl;
				cout<<".   Welcome Admin ."<<endl;
				cout<<"-------------------"<<endl;
				admininterface();
			}
			else
			{
				cout<<"Successfully login....."<<endl;
				cout<<"-------------------"<<endl;
				cout<<".   Welcome user  ."<<endl;
				cout<<"-------------------"<<endl;
				int userindex;
				for(int x=0;x<count;x++)
				{
					if(user[x]==name)
					{
						userindex=x;
						break;
					}
				}
				userinterface(userindex);
			}
		}
		else if(loginoption==3)
		{
			system("cls");
			cout<<"Program end...."<<endl;
		}
		else
		{
			cout<<"Try Again.. ";
		}
	}
}























