#include<iostream>//for standard i/o
#include<fstream> //for filing
#include<stdlib.h>//using system("cls") function
//using both time header files to reset a static variable to 0 after a day i.e 24  hours
#include<time.h>  
#include<ctime>
using namespace std;
class magicKingdom{
	protected:
		int package;
		float TotalPrice;
		int number;
	public:
		magicKingdom()//constructor called
		{
		}
		magicKingdom(int p, float tp, int num)//constructor called
		{
			TotalPrice=tp;
			number=num;
			package=p;
			setPackage(package);
		}
		virtual int getPackage()//check
		{
			return package;
		}
		void setPackage(int i)
		{
			if(i==1)
			{
				setTotalPrice(6000.00);
			}
			else if(i==2)
			{
				setTotalPrice(8000.0);
			}
			else if(i==3)
			{
				setTotalPrice(10000.0);
			}
		}
		int getNoOfCustomers()
		{
			return number;
		}
		virtual float getTotalPrice()const
		{
			return TotalPrice;
		}
		virtual void setTotalPrice(float x) //virtual becuase need to use it in a indirect derived class
		{
			TotalPrice=TotalPrice+x;
		}
		void buffet()
		{
			int buffet;
			cout<<"Would you like add-on lunch and dinner buffet for 5000 per person?\nPress 1 for YES and 2 for NO"<<endl;
			//exception handling
		try{
		cin>>buffet;
		fflush(stdin);
		if(cin.fail())
		throw(buffet);
	}
	catch(...)
	{
		cout<<"Character exception";
	}
	//buffet add-on
			if(buffet==1)
			{
				TotalPrice=TotalPrice+(500*number);
			}
			else if(buffet==2)
			exit;
		}
		float AddOnServices()
		{
			int x;
			int i; 
			int n; //total no. of add ons
			cin.ignore();
			cout<<"We have the following add-on services:";
			do{
			cout<<"\nPress 1 for wheel chair\nPress 2 for bicycle\nPress 3 for personal photographer\nPress 4 for add-on rides\nPress 5 for add-on live shows\nPress 6 to exit\n";
		try{	//exception handling
		cin>>x;
		if(cin.fail())
		throw(x);
		}
		catch(...)
		{
		cout<<"Character Exception";
		}
		system("cls");
		cin.ignore();
			if(x==1) 	//wheelchair add-on
			{
				cout<<"How many wheel chair(s) do you want?\n";
				cin>>x;
				TotalPrice=TotalPrice+(x*1500);
			}
			else if(x==2)
			{		//bicycle add-on
				cout<<"How many bicycle(s) do you want?\n";
				cin>>x;
				TotalPrice=TotalPrice+(x*2000);
			}
			else if(x==3)
			{
				TotalPrice=TotalPrice+2500;
			}
			else if(x==4)
			{ 	//in case someone wants more ride than package or same ride twice
				cout<<"Which extra ride would you like";
				do{
				cout<<"\nPress 1 for Roller Coaster\nPress 2 for Bungee Jumping\nPress 3 for Haunted House\nPress 4 for Jungle Cruise\nPress 5 for Splash Mountain\nPress 6 to exit";
				cin>>i;
				system("cls");
		try{
		cin>>i;
		if(cin.fail())
		throw(i);
		}
		catch(...)
		{
		cout<<"Character Exception";
		}
				if(i==1)
				{
					cout<<"How many Roller Coaster rides would you like to add?";
					cin>>n;
					TotalPrice=TotalPrice+(n*1500);
				}
				else if(i==2)
				{
					cout<<"How many Bungee Jumping rides would you like to add?";
					cin>>n;
					TotalPrice=TotalPrice+(n*500);
				}
				else if(i==3)
				{
					cout<<"How many Haunted House rides would you like to add?";
					cin>>n;
					TotalPrice=TotalPrice+(n*1000);
				}
				else if(i==4)
				{
					cout<<"How many Jungle Cruise rides would you like to add?";
					cin>>n;
					TotalPrice=TotalPrice+(n*500);
				}
				else if(i==5)
				{
					cout<<"How many Splash Mountain rides would you like to add?";
					cin>>n;
					TotalPrice=TotalPrice+(n*2000);
				}
			    }while(i!=6);
			}
			else if(x==5)
			{	//in case one wants more live-shows or same live-show twice
				cout<<"Which extra live show would you like?";
				do
				{
				cout<<"\nPress 1 for MonstersInc\nPress 2 for Cindrella Castle\nPress 3 for Cats And Dogs\nPress 4 for Dance and Play\nPress 5 for Mind Freak\nPress 6 for exit";
				cin>>i;
			try{
			cin>>i;
			if(cin.fail())
			throw(x);
			}
			catch(...)
		{
		cout<<"Character Exception";
		}
				system("cls");
				if(i==1)
				{
					cout<<"How many tickets would you like for Monsters Inc.?";
					cin>>n;
				    TotalPrice=TotalPrice+(n*1000);
			    }
				else if(i==2)
				{
					cout<<"How many tickets would you like for the Cinderella Castle?";
					cin>>n;
				    TotalPrice=TotalPrice+(x*700);
				}
				else if(i==3)
				{
					cout<<"How many tickets would you like for Cats and Dogs?";
					cin>>n;
				    TotalPrice=TotalPrice+(n*500);
				}
				else if(i==4)
				{
					cout<<"How many tickets would you like for Dance and Play?";
					cin>>n;
				    TotalPrice=TotalPrice+(n*1500);
				}
				else if(i==5)
				{
					cout<<"How many tickets would you like for Mind Freak?";
					cin>>n;
				    TotalPrice=TotalPrice+(n*2000);
				}
			}while (i!=6);
			}
}while (x!=6);
return x;
	
	}
	float Discount() //random number generator
	{
		cout<<"Congratulations! You're our lucky draw winner! Now you can enjoy 10% discount on your bill.";
		TotalPrice=TotalPrice*0.9;
		return TotalPrice;
	}	
	virtual void Display()=0; //pure virtual function
	~magicKingdom()
	{
	}
};
class AdminData:public magicKingdom
{
	private:
		float Salary;
		string AdminFName;
		string AdminLName;
		int YOB;//Year Of Birth
		char Gender;
	public:
		AdminData()//constructor called
		{
		}
	AdminData(float sal, string fn, string ln, int y, char g, int num):magicKingdom(0,0.0,num)  //conisidered null(?)
		{
			Salary=sal;
			AdminFName=fn;
			AdminLName=ln;
			YOB=y;
			Gender=g;
		}
		//virtual function
        virtual void getdata(string fn,string ln,int yob,char gen, float sal)
        {
			AdminFName=fn;
			AdminLName=ln;
			YOB=yob;
			Gender=gen;
			Salary=sal;
		}
		void Display()
		{
			cout<<"Name: "<<AdminFName<<" "<<AdminLName<<endl<<"Year Of Birth: "<<YOB<<endl<<"Gender: "<<Gender;
		}
		//writing on the file
		void write(string fn,string ln,int yob,char gen, float sal)
		{
			AdminData obj;
			ofstream file;
			file.open("AdminData.txt", ios::out|ios::app);
			fflush(stdin);
			obj.getdata(fn, ln, yob, gen, sal);
			file<<"Name: "<<obj.AdminFName<<" ";
			file<<obj.AdminLName<<"\t";
			file<<"YOB: "<<obj.YOB<<"\t";
			file<<"Gender: "<<obj.Gender<<"\t";
			file<<"Salary: "<<obj.Salary<<"\t";
			file<<endl;
			file.close();
		}
		void read() //read from the file
		{
			string sentence;
			ifstream file;
			file.open("AdminData.txt",ios::in);
			while(getline(file,sentence))
			{
				cout<<sentence;
				cout<<endl;
			}
			file.close();
		}
		void GetSalary()
		{
			cout<<"Salary: "<<Salary;
		}
		void setTotalPrice(float x)
		{
			magicKingdom::setTotalPrice(x);
		}
		float getTotalPrice()
		{
			float x;
			x=magicKingdom::getTotalPrice();
			return x;
		}
		~AdminData()//destructor called
		{
		}
};
class CustomerData:public magicKingdom
{
	private:
		string CustomerFName;
		string CustomerLName;
		string Email;
		protected:
		float Height;
		float Weight;
		int Age;	
	public:
		static int NumberOfVisitors; //public because static
		CustomerData()//constructor called
		{
			NumberOfVisitors=NumberOfVisitors+1;
		}
		//constructor called
		CustomerData(string fn, string ln, string em, float h, float a, int w,int p, float tp, int num):magicKingdom(p,tp,num)
		{
			NumberOfVisitors=NumberOfVisitors+1;
			CustomerFName=fn;
			CustomerLName=ln;
			Email=em;
			Height=h;
			Weight=w;
			Age=a;
		}
		//to get data 
		void getdata(string fn, string ln, string eid,float h, float w, int a)
		{
			CustomerFName=fn;
			CustomerLName=ln;
			Email=eid;
			Height=h;
			Weight=w;
			Age=a;
		}
		void Display()
		{
			cout<<"Name: "<<CustomerFName<<" "<<CustomerLName<<endl<<"Email Address: "<<Email<<endl<<"Height: "<<Height<<endl<<"Weight: "<<Weight<<endl<<"Age: "<<Age<<endl;
		}
		//writing to the file
		void write(string fn, string ln, string eid,float h, float w, int a)
		{
			CustomerData obj;
			ofstream file;
			file.open("CustomerData.txt", ios::out|ios::app);
			obj.getdata(fn, ln, eid,h, w, a);
			file<<"Name: "<<obj.CustomerFName<<" ";
			file<<obj.CustomerLName<<"\t";
			file<<"Email: "<<obj.Email<<"\t";
			file<<"Height: "<<obj.Height<<"\t";
			file<<"Weight: "<<obj.Weight<<"\t";
			file<<"Age: "<<obj.Age<<"\t";
			file<<endl;
			file.close();
		}
		//reading from the file
		void read()
		{
			
			string sentence;
			ifstream file;
			file.open("CustomerData.txt", ios::in);
			while(getline(file,sentence))
			{
				cout<<sentence;
				cout<<endl;				
			}
			file.close();
		}
		void GetNumberOfVisitors()
		{
			cout<<"Number Of Visitors: "<<NumberOfVisitors;
		}
		void SaveAndResetCount()   // saves the total number of visitors per day in the file and resets the static variable to 0
		{ 
			ofstream file;
	        file.open("CustomerData.txt", ios::out|ios::app);
	        file<<"Total visitors: "<<NumberOfVisitors<<endl;
	        NumberOfVisitors=0;
        }
		void checkNumberOfVisitors()const
		{
			if(NumberOfVisitors>5000)
			{
				cout<<"Park is full for the day! Please come tomorrow!";
			}
		}
		void setTotalPrice(float x)
		{
			magicKingdom::setTotalPrice(x);
		}
		float getTotalPrice()
		{
			float x;
			x=magicKingdom::getTotalPrice();
			return x;
		}
		//destructor called
		~CustomerData()
		{
		}
};
int CustomerData::NumberOfVisitors=0; //static variable initialized to zero

class finance:public AdminData,public CustomerData   //Maintenance money + other workers??
{
	private:
		int package;
	public:
		finance()
		{
		}
		void setPackage(int pack)
		{
			if(pack==1)
			{					
				setTotalPrice(6000);
			}
			else if(pack==2)
			{
				setTotalPrice(8000);
			}
			else if(pack==3)
			{
				setTotalPrice(10000);
			}
		}
		void setTotalPrice(float x)
		{
			AdminData::setTotalPrice(x);
		}
		float getTotalPrice()
		{
			float x;
			x=AdminData::getTotalPrice();
			return x;
		}
		~finance()
		{
		}
};
class discount:public finance{
	private:
		string CustomerCity;
	public:
		discount()//constructor called
		{
		}
		discount(string cc, int n,float as, int numb,int p, float tp, int num):finance()//constructor called
		{
			CustomerCity=cc;
		}
	void getdata(string city)
	{
		CustomerCity=city;
	}
	//discount given if customer is from the same city where this pack is located
	discount operator==(discount b)	//operator overloading
	{
	if(CustomerCity== "karachi")
	{
	cout<<"You have received 10% discount for being in the same city where this park is located";
     		float x;
     		fflush(stdin); //to clear buffer
     		x=getTotalPrice();
     		setTotalPrice(x=x*0.9);
	}
	}
	float getTotalPrice()
		{
			float x;
			x=finance::getTotalPrice();
			return x;
		}
    void setTotalPrice(float x)
		{
			finance::setTotalPrice(x);
		}
~discount()
{
}
};
class Rides:public magicKingdom
{
	private:
		float PricePerRide;
		string Ride;//name of the ride;
	public:
		Rides()//constructor called
		{
		}
		Rides(float pp, string r,int p, int tp, int num):magicKingdom(p,tp,num)//constructor called
		{
			PricePerRide=pp;
			Ride=r;
		}
		void RollerCoaster()
		{
			PricePerRide=1500.00; //different price for different rides
		    Ride="RollerCoaster";
		}
		void BungeeJumping()
		{
			PricePerRide=500.50;
			Ride="BungeeJumping";
		}
		void HauntedHouse()
		{
			PricePerRide=1000.00;
			Ride="HauntedHouse";
		}
		void JungleCruise()
		{
			PricePerRide=500.00;
			Ride="JungleCruise";
		}
		void SplashMountain()
		{
			PricePerRide=2000.00;
			Ride="SplashMountain";
		}
		void Display()
		{
			cout<<endl<<Ride;
		}
~Rides()	//destructor called
{
}
};
class RideCriteria:public Rides,public CustomerData //derive from Customer Data
{
	private:
	public:
		RideCriteria()//constructor called
		{
		}
		//constructor called
		RideCriteria(float pp, string r,string fn, string ln, string em, float h, float w, int a,int p, float tp, int num):	Rides(pp,r,p,tp,num),CustomerData(fn,ln,em,h,a,w,p,tp,num)
		{
		}
		bool CheckWeight(float Weight) //checking weight follows the criteria
		{
			if(Weight>35)
			return true;
			else 
			return false;
		}
		bool CheckHeight(float Height)  
		{
			if(Height>140) //the person should be at least around 4.7 feet high
			return true;
			else 
			return false;
		}
		bool CheckAge(int Age) //age criteria
		{
			if(Age>12)
			return true;
			else 
			return false;
		}
		void Display() 
		{
			if(CheckAge(Age)==1&&CheckHeight(Height)==1&&CheckWeight(Weight)==1)
			{
				cout<<"You're eligible for all the rides in this park!";
			}
			else 
				cout<<"You might not be eligible for some rides in this park"<<endl;
		}
~RideCriteria()
{
}
};
class LiveShows:public magicKingdom //Ask Sir
{
private:
	string Show;
	float PricePerShow;
public:
	LiveShows()//constructor called
	{
	}
	//constructor called
	LiveShows(string s, float pp,int p, int tp, int num):magicKingdom(p,tp,num)
	{
		Show=s;
		PricePerShow=pp;
	}
	void MonstersInc()	//different prices for different shows
	{
		Show="MonstersInc";
		PricePerShow=1000;
	}
	void CinderellaCastle()
	{
		Show="CinderallaCastle";
		PricePerShow=700;
	}
	void CatsAndDogs()
	{
		Show="CatsAndDogs";
		PricePerShow=500;
	}
	void DanceAndPlay()
	{
		Show="DanceAndPlay";
		PricePerShow=1500;
	}
	void MindFreak()
	{
		Show="MindFreak";
		PricePerShow=2000;
	}
	void Display()
	{
		cout<<endl<<Show;
	}
~LiveShows()
{
}
};
int main()
{
	string pass;
	cout<<"User: Admin"<<endl<<"Enter password: ";
	cin>>pass;
	if(pass=="admin")
	{
	CustomerData cd1;
	int package;
	int number;
	float TotalPrice;
	int i;
	string Fname;
	string Lname;
	int age;
	int num;
	string email;
	float height;
	float weight;
	int YOB;
	char gender;
	float sal;	
	string city;
	do{
	cout<<"Press 1 for entering data of admin\nPress 2 for entering data of customer\nPress 3 to exit ";
		try{
		cin>>i;
		if(cin.fail())
		throw(i);
	}
	catch(...)
	{
		cout<<"Character Exception";
	}
	if(i==1)
	{	
		cout<<"Enter First Name: ";
		cin>>Fname;
		cout<<"Enter Last Name: ";
		cin>>Lname;
		cout<<"Enter YOB: ";
		cin>>YOB;
		cout<<"Enter gender(M/F): ";
		cin>>gender;
		cout<<"Enter salary:";
		cin>>sal;
		cout<<"Enter Number: ";
		try{
		cin>>num;
		if(cin.fail())
		throw(i);
     	}
	    catch(...)
	    {
		cout<<"Character Exception";
	    }
	    AdminData ad(sal, Fname,Lname,YOB,gender,num);
	    magicKingdom *m;	//abstract base class ptr
	    m=&ad;
        ad.write(Fname, Lname, YOB, gender, sal);
		m->Display();	//upcasting
		cout<<"Do you want to read data?\nPress 1 for admin data\nPress 2 for customer data\nPress 3 to exit";
		int y;
		cin>>y;
		if(y==1)
		{
			ad.read();
		}
		else if(y==2)
		{
			cd1.read();
		}
		else if(y==3)
		{
			exit(0);
		}
	}
	else if(i==2)
	{
	{
	int a;
	system("cls");
	cout<<"Which Package would you like to have?\n1: Silver Package:\n\tCost: 6000\n\tIncludes:\n\t\t3 Live Shows\n\t\t3 Rides\n2: Gold Package\n\tCost: 8000\n\tIncludes:\n\t\t4Live Shows\n\t\t4 Rides\n\t\tComplimentary Hi-Tea\n3: Platinum Package\n\tCost: 10000\n\tIncludes:\n\t\t5 Live Shows\n\t\t5 Rides\n\t\tComplimentary Hi-Tea\n\t\tComplimentary Bicycle with helmet\n";
	cin>>package;
	cout<<"Enter First Name: ";
	cin>>Fname;
	cout<<"Enter Last Name: ";
	cin>>Lname;
	cout<<"Enter email:";
	cin>>email;
	cout<<"Enter Age: ";
	cin>>age;
	cout<<"Enter number: ";
	cin>>number;
	cout<<"Enter height(in cms): ";
	cin>>height;
	cout<<"Enter weight(in kgs): ";
	cin>>weight;
	cout<<"Enter city of residence: ";
	cin>>city;
	cin.ignore();
	CustomerData cd(Fname,Lname, email,height,age,weight,package,0,0);
	cd.getPackage();
	cd.buffet();
	fflush(stdin);
	a=cd.AddOnServices();
	RideCriteria rc;
	rc.CheckAge(age);
	rc.CheckHeight(height);
	rc.CheckWeight(weight);
	rc.Display();
	fflush(stdin);
	
	if(a==6)
		{	
		int a;
		a=rand()%10; 	//randomly chooses a lucky wiwnner
		if(a==6)
		{
		cd.Discount();
		}
	}
	cout<<endl<<"Total Price: "<<cd.getTotalPrice()<<endl;
	cd.write(Fname, Lname, email, height, weight, age);
	time_t t = time(NULL);
    tm* timePtr = localtime(&t);      
	int tester;
	tester=timePtr->tm_hour;
	if(tester==24)   //assumed that after every 24 hours, the count will be reset to zero and will be saved in the file
	cd.SaveAndResetCount();
	}
}
}while(i!=3);
	return 0;
}
else
cout<<"Incorrect Password!";
}
