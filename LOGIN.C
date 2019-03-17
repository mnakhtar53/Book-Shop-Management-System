class Login
{
   private:
      char un[20],up[10],n;
   public:
      void bookhead()
      {
	  cout<<"===============================\n";
	  cout<<"  BOOK SHOP MANAGMETNT SYSTEM\n";
	  cout<<"===============================\n";
      }

	   void getuserdata()
	   {
		cout<<"Enter user Id : "; cin>>un;
		cout<<"Enter Password  : "; 			//cin>>up;
		for(int i=0;i<=3;i++)
		{
			up[i]=getch();
			putchar('*');
			}
			up[i]='\0';

	   }

void login1()
{

  char u[20],p[20];
  clrscr();
  Menu m;
  bookhead();
  cout<<"             Login             \n";
  cout<<"===============================\n";
  cout<<endl;
  ifstream fin;
  cout<<"Enter user Id : "; cin>>u;
  cout<<"Enter Password  : "; 				//cin>>p;
  for(int i=0;i<=3;i++)
  {
	p[i]=getch();
	putch('*');
  }
	p[i]='\0';
  fin.open("S_Books.dat", ios::in|ios::binary);
  fin.seekg(0, ios::beg);
    int q=0;
    while(fin.read((char*)this, sizeof(Login)))   // for end of file
    {
       if(strcmp(u,this->un)==0 && strcmp(p,this->up)==0)
       {
	   m.mainmenu();
	   q++;
       }
    }
       if(q==0)
       {
	  cout<<"=========================================";
	  cout<<"\nUser name and password does not match\n";
	  cout<<"=========================================";
	  getch();
       }
 fin.close();
 this->main_window();
}


	       void signup();
	       void viewuserdata();
	       void changepass();
	       void main_window();
	       void deleteuser();
	       void passchange();
};

void Login::main_window()
      {
	clrscr();
	bookhead();
	cout<<endl;
	cout<<"1. Sign Up\n";
	cout<<"2. Login\n";
	cout<<"3. Change Password\n";
	cout<<"4. Show user data\n";
   //	cout<<"5. Change User Id & Password\n";
	cout<<"5. Delete User\n";
	cout<<"6. Exit.\n"<<endl;
	cout<<"===============================\n";
	cout<<"  Enter Your Choice: ";  cin>>n;


	switch(n)
	  {
	     case '1': this->signup(); break;
	     case '2': this->login1(); break;
	     case '3': this-> passchange(); break;
	     case '4': this->viewuserdata(); break;
	    // case '5': this->changepass(); break;
	     case '5': this->deleteuser(); break;
	     case '6': exit(0);
	    default: cout<<endl<<"  Invalid Entry.";
		     cout<<"\n===============================";
		     getch();
		     main_window();
	   }
      }

void Login::signup()
{
  char u[20],p[10];
  clrscr();
  bookhead();
  cout<<"            Sign Up           \n";
  cout<<"===============================\n";
  cout<<endl;
  ofstream fout;
  Login a1;
  a1.getuserdata();

  int c=0;
  ifstream fin;
  fin.open("S_Books.dat",ios::in | ios::binary);
     fin.read((char*)this, sizeof(Login));
     while(!fin.eof())
     {
	 if(strcmp(a1.un,this->un)==0)
	 {
	     c++;
	 }
	 fin.read((char*)this, sizeof(Login));

     }
      fin.close();
     if(c>0)
     {
	cout<<"\n-----------------------------\n";
	cout<<"This user Id already exist.\nPlease enter other user Id\n";
	cout<<"press any key to continue\n";
	getch();
	main_window();

     }
     else
     {
      /*	if(strcmp(a1.un,0) && strcmp(a1.up,0))
	{
	     cout<<"-----------------------------------";
	     cout<<"\nNot valid User name or password\nPlease try again\n";
	     getch();
	}
	else
	{  */
	fout.open("S_Books.dat", ios::app | ios::binary);
	fout.write((char*)&a1, sizeof(Login));
	fout.close();
	cout<<"--------------------";
	cout<<"\nUser Id created.";
	getch();
	}
	main_window();
 // }
}

void Login::viewuserdata()
{

   clrscr();
    bookhead();
    cout<<"            User Data          \n";
    cout<<"===============================\n";
    cout<<endl;
   ifstream fin;
   fin.open("S_Books.dat", ios::in|ios::binary);
     if(!fin)
     {
	 cout<<"File not exist";
	getch();
	main_window();
     }
     else
     {
	fin.read((char*)this, sizeof(Login));
	int p=0;
	while(!fin.eof())
	{
	   cout<<"\nUser Id: "<<un;
	   cout<<"\nUser password: "<<up;
	   fin.read((char*)this, sizeof(Login));
	   p++;
	}
	  if(p==0)
	  {
	      cout<<"Data not Exist";
	  }
	fin.close();
	getch();
	main_window();
     }
}

void Login::passchange()
{
    char uname[20],up1[20];
    clrscr();
    bookhead();
    cout<<"        Change password    \n";
    cout<<"===============================\n";
    cout<<endl;
    cout<<"Enter User Id  : "; cin>>uname;
    cout<<"Enter Password : "; cin>>up1;

     fstream file;
     file.open("S_Books.dat",ios::in|ios::out|ios::ate|ios::binary);
     file.seekg(0,ios::beg);
	file.read((char*)this, sizeof(Login));
	if(!file)
	   cout<<"File not exists";
	else
	{
	   int p=0;
	   while(!file.eof())
	   {
	       if(strcmp(uname,this->un)==0 && strcmp(up1,this->up)==0)
	       {
		   cout<<"\n----------------------------\n";
		   cout<<"Enter new password :";
		   cin>>this->up;
		    file.seekp(file.tellp()-sizeof(Login));
		    file.write((char*)this, sizeof(Login));
		    p++;
	       }
	       file.read((char *)this, sizeof(Login));
	   }

	   if(p==0)
	   {
		cout<<"\n---------------------------------";
		cout<<"\nUser id and Password not match\nPlease try again";
	   }
	   else
	   cout<<"\nPassword changed successfully";
	}
	   file.close();
	   getch();
	   main_window();


}

/*
void Login::changepass()
{
   char uname[20];
   int recno=0,location;
   clrscr();
    bookhead();
    cout<<"   Change user Id & password    \n";
    cout<<"===============================\n";
    cout<<endl;
   cout<<"Enter Id name for update user data : ";  cin>>uname;

   fstream file,file1;
   file.open("S_Books.dat",ios::in|ios::out|ios::ate|ios::binary);

	file.seekg(0,ios::beg);
	file.read((char*)this, sizeof(Login));
	if(!file)
	   cout<<"File not exists";
	else
	{
	   int p=0,s=0;
	   while(!file.eof())
	   {
	       if(strcmp(uname,this->un)==0)
	       {
		 Login a2;
		 cout<<"\nEnter new data\n";
		 cout<<"----------------------\n";
		 a2.getuserdata();
		 file.seekg(0);
		   file.read((char*)this, sizeof(Login));
		   while(!file.eof())
		   {
			if(strcmp(a2.un,this->un)==0)
			{
			   s++;
			}
			 file.read((char *)this, sizeof(Login));
		   }
			if(s>0)
			{
			   cout<<"\n-------------------------------\n";
			   cout<<"This user Id already exists\n Please try again\n";
			   p++;
			   getch();
			}
			else        // data not updated
			{

			file1.open("S_Books.dat",ios::out|ios::ate|ios::binary);
			     //	file1.seekg(0,ios::beg);
			    file1.seekp(file.tellp()-sizeof(*this));
			    cout<<"seekp";
			    getch();
			    file1.write((char*)&a2, sizeof(*this));
			    cout<<"write";
			    getch();
			    p++;
			    cout<<"\n--------------------\n";
			    cout<<"Data updated";
			    getch();
			    file1.close();
			}
	       }
		 file.read((char*)this, sizeof(Login));
	   }
		if(p==0)
		{
		  cout<<"\n--------------------\n";
		  cout<<"Data not found";
		  getch();
		}
	 }

	file.close();
	main_window();

}
*/
void Login::deleteuser()
{
     clrscr();
     bookhead();
     cout<<"          Delete User Id    \n";
     cout<<"===============================\n";
     cout<<endl;
     char uname1[20];
     cout<<"Enter user Id for delete : ";
     cin>>uname1;
     ifstream fin;
     ofstream fout;
     fin.open("S_Books.dat", ios::in | ios::binary);
     if(!fin)
	cout<<"File not exist.";
     else
     {
	fout.open("tmp.dat", ios::out | ios::binary);
	    fin.read((char*)this, sizeof(Login));
	    int p=0;
	    while(!fin.eof())
	    {
		if(strcmp(uname1,this->un))
		{
		   fout.write((char*)this, sizeof(Login));
		}
		else
		   p++;
		  fin.read((char*)this, sizeof(Login));
	    }
	       if(p>0)
	       {
		  cout<<"\n--------------------\n";
		  cout<<"Id deleted.";
	       }
	       else
	       {
		  cout<<"\n-----------------------\n";
		  cout<<"Id not found.";
	       }
       fin.close();
       fout.close();
       remove("S_Books.dat");
       rename("tmp.dat","S_Books.dat");
     }
     getch();
     main_window();

}