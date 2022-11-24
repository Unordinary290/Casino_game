#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<conio.h>
#include<cstdlib>
using namespace std;
// for login id
class Authentication      
{
    public:
    string username,password,un,pw;
    ofstream fout;
    bool isloggedin();
    int gsdata();
};

bool Authentication::isloggedin()
{
    cout<<"Enter username: ";cin>>username;
    cout<<"Enter password: ";cin>>password;
    ifstream read("data"+username+".txt");   //read the data from (username).txt file.
    getline(read,un);
    getline(read,pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else{
        return false;
    }
}

int Authentication::gsdata()
{
    int choice;
     cout<<"1: Register \n2: Login\nyour choice: "; cin>>choice;
    if (choice == 1)
    {
    cout<< "select a username: "; cin>>username;
    cout <<"select a password: "; cin>>password;
    fout.open ("data"+username+".txt",ios::app);
    fout <<username<<endl<<password<<endl;
    gsdata();
    }
    else if (choice==2)
    {
        bool status = isloggedin();
        if (!status)
        {
            cout<<"False Login! "<<endl;
            system("pause");
            exit(0);
        }
        else{
            cout<<"Succesfully logged in! "<<endl;
            system("Pause");
            return 1;

        }
    }
    else{
        cout<<"Invalid! ";
        exit(0);
    }
    return 0;
}

// it is single level inheritance to access data member from base class to derived class.

class Game :public Authentication  
{
 bool flag=0;			//declaring flag variable as bool data type and initialize by 0.
int amount;int deposit;
char input;int guess;
static int count;     //declaring static variable
public:
void display();  
void rules();   //declaring of function
void game();
};
int Game::count;    //define static count variable outside of class. 
void Game::game()
{
	bool flag=0;
display();        //calling display function.
ofstream fout;
fout.open("data"+username+".txt",ios::app);
cout<<endl;
cout<<"Welcome "<<username<<" to our casino"<<endl;
fout<<username<<endl;
cout<<endl;
cout<<"Enter input your amount Rs :   ";
cin>>amount;
fout<<"Amount you deposite: "<<amount<<endl;
cout<<endl;
do
{
rules();

label1:
cout<<"Enter amount you want to bet Rs : ";
cin>>deposit;
fout<<"Amount "<<count<<" time you bet: "<<deposit<<endl;
cout<<endl;
if(deposit>amount)
{
	cout<<"Invalid input";
	cout<<" You have not enough money"<<endl;
	goto label1;
}

int ball=rand()%10+1;    // using random function.
label2:
cout<<"Enter input method : "<<endl;
cout<<"Press 1 if you want to input your guessing number where ball will stop "<<endl;
cout<<"Press 2 if you think that the number where ball will stop is even number "<<endl;
cout<<"Press 3 if you think that the number where ball will stop is odd number "<<endl;
cout<<"Enter input :   ";
cin>>guess;
cout<<endl;
if(guess==1)
{
	int number;
	cout<<"Enter input guessing number in between 1-10  :      ";
	cin>>number;
    fout<< "The number you put"<<count<<" st round: "<<number<<endl;
	cout<<endl;
	if(guess==ball)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
    
}
else if(guess==2) //=
{
	if(ball%2==0)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
}
else if(guess==3)
{
	if(ball%2!=0)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}	
}
else
{
	cout<<"Invalid input "<<endl;
	goto label2;
}

if(flag==1)
{
	cout<<"Congratulations ! you win "<<endl;
	cout<<"You win Rs"<<deposit*10<<endl;
    fout<<"your "<<count<<"st round win amount: "<<deposit*10<<"Rs"<<endl;
	amount=amount+deposit*10;
    count++;
}
else if(flag==0)
{
	cout<<"Sorry ";
	cout<<"You lose Rs"<<deposit<<endl;
    cout<<"Ball is on number: "<<ball<<endl;
    fout<<"your "<<count<<"st round lose amount: "<<deposit<<"Rs"<<endl;
amount=amount-deposit;	
count++;
}
cout<<"Would you like to play again y/n 		:		";
cin>>input;
cout<<endl;
if(amount==0)
{
	cout<<"You have not enough money to play"<<endl;
	break;
}
}while(input!='n');

cout<<username<<" , "<<" you have "<<amount<<"Rs"<<endl;
fout<<"your "<<count<<"st round total amount: "<<amount<<"Rs"<<endl;
fout.close();
cout<<"\n\n************************************************************************************"<<endl;
system("pause");
exit(0);
}
void Game::rules()
{
	 system("cls");
	   cout << "\n\n";
      cout<<"\n\n========================================================================================\n\n";
    cout << "\t\tRULES OF THE GAME\n";
       cout<<"\n\n========================================================================================\n\n";
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
   cout<<"\n\n========================================================================================\n\n";
}
void Game::display()   // it is part of DSA to print each variable.
{
   {
    int n=5;
    if(n<7){
        for(int i=0;i<15;i++)
        {cout<<"________";}
        cout<<endl;
        
    for(int i=0;i<n;i++)
    {
        // WELCOME
        for(int j=0;j<=n+1;j++) //W
        {
            Sleep(10);
            if(((i<n) && (j==0||j==4))|| ((i==2)&&(j==2) || (i==3&& (j==1||j==3))))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        for(int j=0;j<=n+1;j++) //E
        {
            Sleep(10);
            if(((i==0||i==2||i==4) && (j>0))|| ((i==1)&&(j==1) || (i==3&&j==1)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        cout<<"\t";
        for(int j=0;j<=n+1;j++) //L
        {
            Sleep(10);
            if(((i<n) && (j==1))|| ((i==4)&&(j>0)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        for(int j=0;j<=n+1;j++) //C
        {
            Sleep(10);
            if(((i==0 || i==4 ) && (j==3||j==4||j==5))|| ((i==1 || i==3)&&(j==2) || (i==2&& j==1)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        cout<<"\t";
        for(int j=0;j<=n+1;j++)//O
        {
             Sleep(10);
            if(((i==0||i==4)&&(j==2))||((i==1||i==3)&&(j==1||j==3))||((i==2)&&(j==0||j==4)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        for(int j=0;j<=n+1;j++) //M
        {
            Sleep(10);
            if(((i<n) && (j==0||j==4))|| ((i==2)&&(j==2) || (i==1&& (j==1||j==3))))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
         for(int j=0;j<=n+1;j++) //E
        {
            Sleep(10);
            if(((i==0||i==2||i==4) && (j>0))|| ((i==1)&&(j==1) || (i==3&&j==1)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        cout<<"\t\t";
         for(int j=0;j<=n+1;j++) //X
        {
            Sleep(10);
            if(((i==0||i==4) && (j==0||j==4))|| ((i==1||i==3)&&(j==1||j==3) || (i==2&&j==2)))
            {
                cout<<"X";
            }
            else
              cout<<" ";
        }
        cout<<"\t\t";
         //CASINO
        for(int j=0;j<=n+1;j++) //C
        {
            Sleep(10);
            if(((i==0 || i==4 ) && (j==3||j==4||j==5))|| ((i==1 || i==3)&&(j==2) || (i==2&& j==1)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        
         for(int j=0;j<=n+1;j++)//A
        {
            Sleep(10);
            if(((i==0)&&(j==2||j==3))||((i==1||i==3||i==4)&&(j==1||j==4))||((i==2)&&(j>0&&j<5)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }

         for(int j=0;j<=n+1;j++)//S
        {
            Sleep(10);
            if(((i==1)&&(j==1))||((i==0||i==2||i==4)&&(j<5 && j!=0))||((i==3)&&(j==4)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
         for(int j=0;j<=n+1;j++)//I
        {
            Sleep(10);
            if(((i==0||i==4)&&(j<4 && j!=0))||((i==2||i==1||i==3)&&(j==2)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        for(int j=0;j<=n+1;j++)//N
        {
            Sleep(10);
            if(((i<5)&&(j==0||j==3))||((i==1)&&(j==1))||((i==2)&&(j==2)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
        for(int j=0;j<=n+1;j++)//O
        {
             Sleep(10);
            if(((i==0||i==4)&&(j==2))||((i==1||i==3)&&(j==1||j==3))||((i==2)&&(j==0||j==4)))
            {
                cout<<"*";
            }
            else
              cout<<" ";
        }
           

        cout<<endl;

    }
    for(int i=0;i<15;i++)
        {cout<<"________";}
    }
    
}
}

int main()
{
    Game a;
    a.gsdata();
    a.game();
}
