#include<iostream>
#include<windows.h>

using namespace std;

class Account
{
	private:
		//Actual
		string username;
		string password;
		string place;
		string food;
		string date;
		char ch;
		//Testing
		string Username;
		string Password;
		string newP;
		string Place;
		string Food;
		string Date;
		char Ch,CH;
	public:
		void input()
		{ 
			cout<<"\n\t\t\tAccount SignUp\n";
			while(1)
			{
			    cout<<"\nUsername : ";
			    cin>>username;
				cout<<"\nPassword : ";
				cin>>password;
			        system("cls");
			        cout<<"\n\t\t\tAccount SignUp\n";
			    	cout<<"\nTo keep your account & data secured in case you forget your password  ";
			        cout<<"\nWe would like to ask some questions ";
			        break;
		    }
		    while(1)
		    {
			    cout<<"\n\t\tWould you like to proceed(y/n)";
		    	cin>>ch;
		    	system("cls");
			    if(ch=='y'||ch=='Y')
			    {
			    	cout<<"\n\t\t\tAccount SignUp";
			    	cout<<"\nEnter your date of birth(D/M/Y) : ";
		    	    cin>>date;
		    		cout<<"\nEnter your favorite place : ";
			    	cin>>place;
			    	cout<<"\nEnter your favorite food : ";
			    	cin>>food;
				}
				else if(ch=='n'||ch=='N')
				{
				    food=" ";
				    date=" ";
			    	place=" ";
				}
				else
				    continue;
				break;
		    }
	    }
		int Signin()
		{
			system("cls");
			cout<<"\n\t\t\tSignin";
			int count=0;
			char check;
			while(1)
			{
				cout<<"\nUsername : ";
				cin>>Username;
				if(Username!=username)
				{
					PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
					cout<<"\nUser not found.";
					continue;
				}
				while(1)
				{
					if(username=="0" || password=="0")
					    break;
					cout<<"\nPassword : ";
			        cin>>Password;
			        if(password!=Password)
				    {
				    	PlaySound(TEXT("C:/Users/PC/Downloads/Denied.wav"),NULL,SND_FILENAME | SND_SYNC);
				    	cout<<"\nWrong Password.";
						count++;
						if(count>=3)
						{
							cout<<"\n\t\t\tForgot Password?(y/n)";
							cin>>check;
						}
						if(check=='y' || check=='Y')
						{
							Forgot();
							if(username=="0"&&password=="0"&&food=="0")
							    return 0;
							continue;
						}
						continue;
					}
					break;
				}
				    PlaySound(TEXT("C:/Users/PC/Downloads/Access.wav"),NULL,SND_FILENAME | SND_SYNC);
				    system("cls");
					return 1;
				}
		}
        void Forgot()
        {
        	system("cls");
	        if(food==" " && date==" " && place==" ")
	        {
	        	PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
	           	cout<<"\n\t\tSorry you didn't provide us with the information while creating this account .";
		        cout<<"\n\t\tTherefore , we can't help you .";    
	        }
	        else
	        {
	        	while(1)
	        	{
		            cout<<"\nEnter your date of birth(D/M/Y) : ";
		            cin>>Date;
		            cout<<"\nEnter your favorite place : ";
		            cin>>Place;
	        	    cout<<"\nEnter your favorite food : ";
				    cin>>Food;
				    if(food==Food && date==Date && place==Place)
		    	    {
					    Change();
					    break;
					}
		   		 	else 
		    		{
		    			PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
		    		    cout<<"\n\t\tPrivate information doesn't match.Try Again.";
		    	   	    continue;
					}
				}
			}
		}
		void Change()
		{
			int x;
			while(1)
			{
				system("cls");
				cout<<"\n\t\t\t1.View Password ";
				cout<<"\n\t\t\t2.Change Password";
				cout<<"\n\t\t\t3.Delete Account";
				cout<<"\n\t\t\tChoose from (1-3)  ";
				cout<<"\nReturn(R)";
				cout<<"\n\t\tYou choose:";
				cin>>Ch;
				switch(Ch)
				{
				case '1':
					system("cls");
					cout<<"\n\tYour password is "<<password<<" !";
					system("pause");
					break;
				case '2':
					system("cls");
					cout<<"\nNew password : ";
					cin>>newP;
					password=newP;
					cout<<"\n\t\tYour password has been changed !";
					system("pause");
					break;
				case '3':
					system("cls");
					cout<<"\n\t\tAre you sure you want to delete your account(y/n)?";
					cin>>CH;
					if(CH=='y' || CH=='Y')
					{
					    username="0";
		            	password="0";
		    	        place="0";
		        	    food="0";
		            	date="0";
		            	x=1;
		            	cout<<"\n\t\tYour Account has been deleted !";
		            	system("pause");
					}
					break;
				case 'R':
				case 'r':
					x=1;
					break;
				default:
					PlaySound(TEXT("C:/Users/PC/Downloads/User.wav"),NULL,SND_FILENAME | SND_SYNC);
					cout<<"\n\t\t\tInvalid command";
					break;
			}
				if(x==1)
				    break;
			    }
}};
