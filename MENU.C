class Menu
{

   public:
   Login l1;
   int bookid,qnt,nn,qnt1;
   char n1,n2,n3,title[30],author[30];
   float price;

      void entrybookdata()
      {
	  clrscr();
	  l1.bookhead();
	  cout<<endl;
	  cout<<"Enter Book Data\n";
	  cout<<"-------------------\n";
	  cout<<"Book Id : ";  cin>>bookid;
	  cin.ignore();
	  cout<<"Title   : ";  cin.getline(title,29);
	  cout<<"Author  : ";  cin.getline(author,29);
	  cout<<"Price   : ";  cin>>price;
	  cout<<"Quantity: ";  cin>>qnt;
	       if(bookid==0 || price==0)
	       {
		   cout<<"\n-----------------------------\n";
		   cout<<"Book data not initialize\nPlease enter valid Book Id or Price";
	       }
	       else
	       {
		  ofstream fout;
		  fout.open("Bookdata.dat",ios::app|ios::binary);
		   // if(bookid==this->bookid)
		    {                        //not work  (dought)
		   /*	cout<<"\n--------------------------------\n";
			cout<<"This Book Id is already used\nPlease used another Book Id";
			getch();
		    }
		    else
		    { */
			fout.write((char*)this, sizeof(Menu));
			cout<<"\nBook Data Initialized";
		    }
			fout.close();
	       }

      }

      void showbook()
      {
	   cout<<bookid<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<price<<"\t\t"<<qnt<<endl;
      }

		  void showbookdata();
		  void mainmenu();
		  void bookmenu();
		  void searchbook(char *t);
		  void update();
		  void updatebook(char *t);
		  void deletebook(char *t);

		   void salemenu();
		   void salebook(char *t);
		   void booksale2();
		   void returnbook();
		   void bookbill();
};

void Menu::showbookdata()
      {
      clrscr();
	  ifstream fin;
	  fin.open("Bookdata.dat",ios::in|ios::binary);

	    if(!fin)
	      cout<<"File Not Exist";
	    else
	    {
	       int p=0;
	       cout<<"Book data\n";
	       cout<<"==========================================================================\n";
	       cout<<"Book Id"<<"\t\t"<<"Title"<<"\t\t"<<"Author"<<"\t\t"<<"Price"<<"\t\t"<<"Quantity";
	       cout<<"\n=========================================================================\n";
	       fin.read((char*)this, sizeof(Menu));
	       while(!fin.eof())
	       {
		   showbook();
		   fin.read((char*)this, sizeof(Menu));
		   p++;
	       }
		 if(p==0)
		    cout<<"\nData Not Available";
	       fin.close();
	    }
       }



void Menu::searchbook(char *t)
{
    clrscr();
    ifstream fin;
    char title1[30];
    cout<<"Enter book title for search : ";
    cin.ignore();     // for clear buffer
    cin.getline(title1,29);
    fin.open("Bookdata.dat",ios::in|ios::binary);
      if(!fin)
	 cout<<"\nFIle not exists";
      else
      {
	   cout<<endl<<"Book data\n";
	   cout<<"========================================================================\n";
	   cout<<"Book Id"<<"\t\t"<<"Title"<<"\t\t"<<"Author"<<"\t\t"<<"Price"<<"\t\t"<<"Quantity";
	   cout<<"\n=======================================================================\n";
	 int p=0;
	 fin.read((char*)this, sizeof(Menu));
	 while(!fin.eof())
	 {
	      if(!strcmp(t,title1))
	      {
		showbook();
		p++;
	      }
	       fin.read((char*)this, sizeof(Menu));
	 }
	   if(p==0)
	   {
		cout<<"This book is not available.";
	   }
      }
      fin.close();
}

void Menu::update()
{
   clrscr();
   cout<<"\nWhich portion you want to update :\n";
   cout<<"1. Book Id\n";
   cout<<"2. Title\n";
   cout<<"3. Author\n";
   cout<<"4. Price\n";
   cout<<"5. Quantity\n";
   cout<<"6. All Data\n";
   cout<<"7. Return To Book Menu\n";
   cout<<"===========================\n";
   cout<<"Enter your choice : ";
   cin>>n3;
   cout<<"\n===========================\n";
      switch(n3)
      {
	 case '1':cout<<"\nEnter New Book Id : ";  cin>>bookid;
		  break;
	 case '2':cout<<"\nEnter New Title : ";    cin.ignore();
		  cin.getline(title,29);
		  break;
	 case '3':cout<<"\nEnter New Author : ";   cin.ignore();
		  cin.getline(author,29);
		  break;
	 case '4':cout<<"\nEnter New Price : ";  cin>>price;
		  break;
	 case '5':cout<<"\nEnter New Quantity : "; cin>>qnt;
		  break;
	 case '6':cout<<"\nEnter New Book Record";
		  cout<<"\n------------------------\n";
		  cout<<"Book Id : ";  cin>>bookid;
		  cin.ignore();
		  cout<<"Title   : ";  cin.getline(title,29);
		  cout<<"Author  : ";  cin.getline(author,29);
		  cout<<"Price   : ";  cin>>price;
		  cout<<"Quantity: ";  cin>>qnt;
		   break;
	 case '7':bookmenu(); break;
	 default: cout<<"Invalid Entry\n";
		  getch();
		  update();

      }
}

void Menu::updatebook(char *t)
{
    clrscr();
    char title1[30];
    fstream file;
    cout<<"Enter book title for update : ";
    cin.ignore();          //for clear buffer
    cin.getline(title1,29);
    file.open("Bookdata.dat",ios::in|ios::out|ios::ate|ios::binary);
       if(!file)
	  cout<<"File not exists";
       else
       {
	   file.seekg(0);
	   file.read((char *)this, sizeof(Menu));
	   int p=0;
	   while(!file.eof())            //both condition same (! and ==0)
	   {
	       if(strcmp(t,title1)==0)   //both condition same (! and ==0)
	       {
		   update();
		     if(bookid==0||price==0)
		     {
		       cout<<"\n-------------------------------------------------\n";
		       cout<<"Book id and Price must be greater than zero(0)";
		       getch();
		       cout<<"\n-----------------------------------------------\n";
		       cout<<"Data not updated";
		       getch();
		       bookmenu();
		     }
		     else
		     {
			    file.seekp(file.tellp()- sizeof(*this));
			    file.write((char*)this, sizeof(Menu));
			    p++;
		     }
	       }
			 file.read((char*)this, sizeof(Menu));
	   }
	     if(p==0)
	     {
		 cout<<"\n----------------------\n";
		 cout<<"Book Not Found ";
	     }
		 else
	     {
		 cout<<"\n--------------------\n";
		 cout<<"Data Updated";
	     }

       }
    file.close();
}

void Menu::deletebook(char *t)
{
    clrscr();
    ifstream fin;
    ofstream fout;
    char title1[30];
    cout<<"Enter book data for delete : ";
    cin.ignore();
    cin.getline(title1,29);
    fin.open("Bookdata.dat",ios::in|ios::binary);
       if(!fin)
	   cout<<"\nFile not found";
       else
       {
	  fout.open("tempfile.dat",ios::out|ios::binary);
	  fin.read((char*)this, sizeof(Menu));
	  int p=0;
	  while(!fin.eof())
	  {
	     if(strcmp(t,title1))
	     {
		fout.write((char*)this, sizeof(Menu));
	     }
	     else
		p++;
	     fin.read((char*)this, sizeof(Menu));
	   }
	      if(p>0)
	      {
		  cout<<"\n-----------------\n";
		  cout<<"Record deleted";
	      }
	      else
	      {
		  cout<<"\n--------------------\n";
		  cout<<"Record not found";
	      }

	  fin.close();
	  fout.close();
	  remove("Bookdata.dat");
	  rename("tempfile.dat","Bookdata.dat");

	}
}

void Menu::mainmenu()
{
   clrscr();
   l1.bookhead();
   cout<<"            Main Menu     \n";
   cout<<"===============================\n";
   cout<<" 1. Book Menu\n";
   cout<<" 2. Sale Book\n";
   cout<<" 3. Exit\n";
   cout<<"===============================\n"<<endl;
   cout<<"Enter your choice : ";
   cin>>n1;
      switch(n1)
      {
	 case '1': bookmenu();  break;
	 case '2': salemenu(); break;
	 case '3': exit(0);
	 default:
		 cout<<"Invalid entry\n";
		 cout<<"===============================\n";
	 }
      getch();
      mainmenu();
}


void Menu::bookmenu()
      {
	 clrscr();
	 l1.bookhead();
	 cout<<"           Book Menu        \n";
	 cout<<"===============================\n";
	 cout<<"1. Entry New Book Record\n";
	 cout<<"2. Show Book Record\n";
	 cout<<"3. Search Book Record\n";
	 cout<<"4. Update Book Record\n";
	 cout<<"5. Delete Book Record\n";
	 cout<<"6. Return to Main Menu\n";
	 cout<<"7. Exit";
	 cout<<"\n===============================\n";
	 cout<<"Enter your choice : ";  cin>>n2;
	    switch(n2)
	    {
		case '1': entrybookdata();  break;
		case '2': showbookdata();   break;
		case '3': searchbook(this->title); break;
		case '4': updatebook(this->title); break;
		case '5': deletebook(this->title); break;
		case '6': mainmenu();
		case '7': exit(0);
		default:
		cout<<"\nInvalid Entry";
		cout<<"\n===============================\n";
	    }
	 getch();
	 bookmenu();
      }

//////////////////////////////////////////////////////////////////////////////

void Menu::salemenu()
   {
	 clrscr();
	 char n5;
	 l1.bookhead();
	 cout<<"           Sale Menu        \n";
	 cout<<"===============================\n";
	 cout<<"1. Sale Book\n";
	 cout<<"2. Search for Book\n";
	 cout<<"3. Return Book\n";
	 cout<<"4. Return to Main Menu\n";
	 cout<<"5. Exit\n";
	 cout<<"===============================\n";
	 cout<<"Enter your choice : ";
	 cin>>n5;

	 switch(n5)
	 {
	   case '1': salebook(this->title); break;
	   case '2': searchbook(this->title); break;
	   case '3': returnbook(); break;
	   case '4': mainmenu(); break;
	   case '5': exit(0);
	   default : cout<<"\nInvalid Entry\n";
		     cout<<"================================\n";
	 }
	 getch();
	 salemenu();
 }

void Menu::booksale2()
{
	qnt1=1;
	cout<<"Enter quantity : ";
	cin>>nn;
	qnt1=nn*price;
	this->qnt=this->qnt-nn;
	fstream file;
	file.open("salebook.dat", ios::app|ios::binary);
	  file.write((char *)this, sizeof(Menu));
	file.close();
}
       //how to access one method variable into another  (like nn,qnt1)

void Menu::bookbill()
{
	fstream file;
	file.open("salebook.dat", ios::in|ios::binary);

	cout<<"Bill\n";
	cout<<"------------------------------------\n";
	cout<<"========================================================================\n";
	cout<<"Title"<<"\t\t"<<"Author"<<"\t\t"<<"Quantity"<<"\t"<<"Price";
	cout<<"\n=======================================================================\n";
	      file.read((char *)this, sizeof(Menu));
	while(!file.eof())
	{
	     cout<<title<<"\t\t"<<author<<"\t\t"<<nn<<"\t\t"<<qnt1<<endl;
	     file.read((char *)this, sizeof(Menu));
	}
	file.close();
}


void Menu::salebook(char *t)
{
	 clrscr();
	 char title1[30],c;
	 l1.bookhead();
	 cout<<"           Sale Book        \n";
	 cout<<"===============================\n";
	 cout<<"\nEnter book title : ";
	 cin.ignore();
	 cin.getline(title1,29);
	    fstream file;
	    file.open("Bookdata.dat",ios::in|ios::out|ios::ate|ios::binary);
	    file.seekg(0);
	       file.read((char*)this, sizeof(Menu));
	       int p=0;
	       while(!file.eof())
	       {
		  if(strcmp(title1,t)==0)
		  {
		     booksale2();
		     file.seekp(file.tellp()- sizeof(*this)); // for write qnt
		     file.write((char *)this, sizeof(Menu));
		     p++;
		     cout<<"\nDo you want to sell more books (y/n) : ";
		     cin>>c;
		     if(c=='y' || c=='Y')
		     salebook(t);
		     else
		     {
		     clrscr();
		     bookbill();
		     }
		     break;
		  }
		   file.read((char*)this, sizeof(Menu));
	       }
		 if(p==0)
		 {
		     cout<<"\n--------------------\n";
		     cout<<"Book not available";
		     cout<<"\n--------------------\n\n";
		     cout<<"Do you want to sell more books (y/n) : ";
		     cin>>c;
		     if(c=='y' || c=='Y')
		     salebook(t);
		     else
		     {
		     clrscr();
		     bookbill();
		     }
		 }
		 file.close();

		   ofstream fout;
		   fout.open("salebook.dat",ios::out|ios::binary);
		   fout.close();
}



////////////////////////////////////////////////////////////////////////////
void Menu::returnbook()
{
	 clrscr();
	 char title1[30],c;
	 int q,n,i;
	 l1.bookhead();
	 cout<<"           Return Book        \n";
	 cout<<"===============================\n";
	     cout<<"\nEnter book title : ";
	     cin.ignore();
	     cin.getline(title1,29);
	     int p=0;
	     fstream file;
	     file.open("Bookdata.dat", ios::in|ios::out| ios::ate | ios::binary);
	     file.seekg(0);
	     file.read((char *)this, sizeof(Menu));
	     while(!file.eof())
	     {
	       if(strcmp(title1,this->title)==0)
	       {
		   cout<<"Enter quantity : ";
		   cin>>q;
		   qnt=qnt+q;
		   file.seekp(file.tellp()- sizeof(*this));
		   file.write((char*)this, sizeof(Menu));
		   cout<<"--------------------------------------";
		   cout<<"\nBook added to record succesfully.\n\n";
		   p++;
		   cout<<"Do you want to return more book (y/n) : ";
		   cin>>c;
		   if(c=='y' || c=='Y')
		   returnbook();
	       }
		file.read((char *)this, sizeof(Menu));
	     }
	       if(p==0)
	     {
		cout<<"\n------------------------\n";
		cout<<"Book record not found\n\n";
		cout<<"Do you want to return more book (y/n) : ";
		cin>>c;
		if(c=='y' || c=='Y')
		returnbook();
	     }
	     file.close();
}