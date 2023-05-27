#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class purevirtual
{public:
virtual void display()=0;
};


class dress:public purevirtual
{
    int pcode;
    float pprice;
    string pname;
    string psize;
    public:
    void menu();
    void administrator();
    void add();
    void edit();
    void rem();
    void entry();
    

void display()
{
    cout<<"\nCODE:";cin>>pcode;
    cout<<"\nPRICE:";cin>>pprice;
    cout<<"\nNAME:";cin>>pname;
    cout<<"\nSIZE:";cin>>psize;
}
void reciept()
 {
   int n,total=0;
   cout<<"Enter the number of product:";
   cin>>n;
   for(int i=0;i<n;i++)
   {cout<<"Poduct "<<i+1<<":";
    display();
    total=total+pprice;
   }
   cout<<"VAT:5%"<<endl;
   cout<<"TOTAL:"<<total+total*0.05;
 }

};

void dress::entry()
{   string email,pass;
    cout<<"\nPlease login:"<<endl;
    cout<<"Enter email:"<<endl;
    cin>>email;
    cout<<"Password:"<<endl;
    cin>>pass;
}

void dress::administrator()
{m:
    int choice;
cout<<"\nAdministrator menu"<<endl;
cout<<"1.Add product"<<endl;
cout<<"2.Modify product"<<endl;
//cout<<"3.Delete product"<<endl;
cout<<"3.Back to menu"<<endl;
cout<<"Please enter your choice:"<<endl;
cin>>choice;
switch(choice)
{
        case 1:add();goto m;
         break;
        case 2:edit();goto m;
         break;
        case 3:menu();
         break;
        default:
         cout<<"\nEnter the correct option:";

}
//goto m;
}



void dress::add()
{   m:
    fstream data;
    int c,token=0;
    float p;
    string n;
    cout<<"Add new product"<<endl;
    cout<<"CODE:"<<endl;
    cin>>pcode;
    cout<<"NAME:"<<endl;
    cin>>pname;
    cout<<"Price"<<endl;
    cin>>pprice;
    data.open("Product.txt",ios::in);
    if(!data)
   { 
    data.open("Product.txt",ios::app|ios::out);
    data<<pcode;
    data<<pname;
    data<<pprice;
    data.close();}
else{
    data>>c>>n>>p;
    while(!data.eof())
    {if(c==pcode)
    {
        token++;
    }
        data>>c>>n>>p;}
    data.close();
}
if(token==1)
{goto m;}
else{
    data.open("product.txt,ios::app|ios::out");
    data<<pcode<<pname<<pprice<<endl;
    data.close();
}

}

void dress::edit()
{
    fstream data,data1;
    int c,pkey,token=0;
    float p;
    string n;
    cout<<"Edit product"<<endl;
    cout<<"CODE:"<<endl;
    cin>>pkey;
    data.open("Product.txt",ios::in);
    if(!data)
   { cout<<"\nFile doesn't exist"<<endl;
    }
    else{
    data1.open("Product1.txt",ios::app|ios::out);
    data>>pcode>>pname>>pprice;
    while(!data.eof())
    {if(pkey==pcode)
    {
        cout<<"New code"<<endl;
        cin>>c;
        cout<<"Name"<<endl;
        cin>>n;
        cout<<"Price"<<endl;
        cin>>p;
        token++;
    }else{data1<<pcode<<pname<<pprice<<endl;}
       data>>pcode>>pname>>pprice;}
    data.close();
    data1.close();
    remove("Product.txt");
    rename("Product1.txt","Product.txt");


}}


void dress::menu()
{m:
int opt,ch;dress d;
    cout<<"\t\t\tBOND CLOTHING WEAR\n";
    cout<<"_____________________________________________________________\n";
    cout<<"Sib bari mor,Khulna"<<"\t\t\tPhone:01745986247\n";
    cout<<"_____________________________________________________________";
    cout<<"\n1.Administrator";
    cout<<"\n2.Buyer";
    cout<<"\n3.Exit";
    cout<<"\nPlease select:";
    cin>>opt;
    if(opt==1)
    {   entry();
        administrator();
    }
    else if(opt==2)
    {cout<<"\n1.Make bill"<<endl;
    cout<<"2.Go back"<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>ch;
    if(ch==1)
       { d.reciept();
       goto m;}
    else{ 
    menu();}
            
    }
    else if(opt==3)
    {

    }
    else if(opt==3)
    {
       //exit(0); 
       cout<<"Out of menu!!";
    }
    else
    {cout<<"\nEnter the correct option";
        }
    
}

class female:public dress
{
    int thpiece;
    float twpiece;
    string opiece;
    string sharee;
    public:
female()
{
cout<<"Entering female section"<<endl;


}

void display()
{   cout<<"\nEdit stock details after every purchase"<<endl;
    cout<<"\nThree piece remained:";cin>>thpiece;
    cout<<"\nTwo piece remained:";cin>>twpiece;
    cout<<"\nOne piece remained:";cin>>opiece;
    cout<<"\nSharee remained:";cin>>sharee;
}

 friend ostream & operator<< (ostream & output,female & a)
 {
    output<<"Three piece"<<a.thpiece<<"\tTwo piece"<<a.twpiece<<"\tOne piece"<<a.opiece<<"\tSharee"<<a.sharee<<endl;
    return output;
 }
 
 
};



class male:public dress
{
    int shirt;
    float pant;
    string panjabi;
    string tshirt;
    public:
male()
{
cout<<"Entering male section"<<endl;
}
void display()
{
    cout<<"\nEdit stock details after every purchase"<<endl;
    cout<<"\nShirt remained:";cin>>shirt;
    cout<<"\nPant remained:";cin>>pant;
    cout<<"\nPanjabi remained:";cin>>panjabi;
    cout<<"\nT shirt remained:";cin>>tshirt;
}

 friend ostream & operator<< (ostream & output,male & a)
 {
    output<<"Shirt"<<a.shirt<<"\tPant"<<a.pant<<"\tPanjabi"<<a.panjabi<<"\tT shirt"<<a.tshirt<<endl;
    return output;
 }

};


class children:public dress
{
    int cshirt;
    float cpant;
    string cpanjabi;
    string frock;
    public:
children()
{
cout<<"Entering children section"<<endl;
}

void display()
{   cout<<"\nEdit stock details after every purchase"<<endl;
    cout<<"Shirt remained:";cin>>cshirt;
    cout<<"\nPant remained:";cin>>cpant;
    cout<<"\nPanjabi remained:";cin>>cpanjabi;
    cout<<"\nFrock remained:";cin>>frock;
}

 friend ostream & operator<< (ostream & output,children & a)
 {
    output<<"Shirt:"<<a.cshirt<<"\tPant;"<<a.cpant<<"\tPanjabi:"<<a.cpanjabi<<"\tFrock:"<<a.frock<<endl;
    return output;
 }

};
int main()
{   dress d;int n,m;
d.menu();
m:
cout<<"\nWant to edit stock details?"<<endl;
cout<<"1.YES"<<endl;
cout<<"2.NO"<<endl;
cout<<"Select any:";
cin>>n;
if(n==1)
{
    cout<<"1.FEMALE SECTION"<<endl;
    cout<<"2.MALE SECTION"<<endl;
    cout<<"3.CHILDREN SECTION"<<endl;
    cout<<"Select:"<<endl;
    cin>>m;
    if(m==1)
    {
        female f;
        f.display();
        cout<<f;
    }
    else if(m==2){
    male m;
    m.display();
    cout<<m;
    }
    else{children c;
    c.display();
    cout<<c;
    }
    goto m;
}
else{cout<<"\nFinished";}

}
