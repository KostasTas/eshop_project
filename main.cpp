#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include <algorithm>



using namespace std;

class User{
    protected:
        string name;
        string email;
    public:
        User( string name, string email ){
            this->name=name;
            this->email=email;
        }

        string get_email(){
            return email;
        }

        void set_email( string email ){
            this->email=email;
        }

        string get_name(){
            return name;
        }

        void set_name( string name ){
            this->name=name;
        }

        ~User(){}
};



class Owner:public User{
    bool isAdmin;

    public:
            Owner( string name, string email ):User(name, email){
                isAdmin=true;
            }

            ~Owner(){}
};

class Buyer:public User{
};

class Item{
	protected:
		string name;
		double price;
		string description;
		int stock;
		int id;

		public:
		    static int cnt;
		    Item(){cnt++;}

			string getBasicInfo(){
			    stringstream ss;
				ss<<"onoma: "<<name<<endl;
				ss<<"perigrafh: "<<description<<endl;
				ss<<"timh: "<<price<<" $"<<endl;
				ss<<"apo8ema: "<<stock<<endl;
				ss<<"kwdikos: "<<id<<endl;

				return ss.str();
			}

			void setDetails(string name, string description, int id,int stock, double price){
				this->name=name;
				this->description=description;
				this->id=id;
				this->stock=stock;
				this->price=price;
			}

			string getDetails();

			virtual void toString(){
				cout<<getBasicInfo();
			}

};

int Item::cnt=0;






class Pen:public Item{
	protected:
        string color;
        double tipSize;

	public:
	    static int cnt;
        Pen(string color, double tipSize){
            this->color=color;
            this->tipSize=tipSize;
            cnt++;
        }

        string getDetails(){
            stringstream ss;

            ss<<"Xrwma: "<<color<<endl;
            ss<<"Megethos: "<<tipSize<<endl<<endl;

            return ss.str();
        }

        void toString() override{
            cout<<getBasicInfo();
            cout<<getDetails();
        }
};
int Pen::cnt=0;

enum typos{ H, B, HB };

class Pencil:public Item{
    protected:
        double tipSize;
        typos type;

    public:
        static int cnt;
        Pencil( typos type, double tipSize ){
            this->type=type;
            this->tipSize=tipSize;
            cnt++;
        }

        string getDetails(){
            stringstream ss;

            ss<<"Typos Mytis: ";

            switch(type){
                case(H):ss<<"H"<<endl;break;
                case(B):ss<<"B"<<endl;break;
                case(HB):ss<<"HB"<<endl;break;
            }
            ss<<"Megethos: "<<tipSize<<endl<<endl;

            return ss.str();
        }

        void toString() override{
            cout<<getBasicInfo();
            cout<<getDetails();
        }
};
int Pencil::cnt=0;

class Notebook : public Item{
    protected:
        int subjects;

    public:
        static int cnt;
        Notebook(int subjects){
            this->subjects=subjects;
            cnt++;
        }
         string getDetails(){
            stringstream ss;
            ss<<"8emata: "<<subjects<<endl<<endl;
            return ss.str();
         }
         void toString() override{
            cout<<getBasicInfo();
            cout<<getDetails();
        }
};
int Notebook::cnt=0;

class Paper : public Item{
    protected:
        int weight;
        int pages;

    public:
        static int cnt;
        Paper(int weight, int pages){
            this->weight=weight;
            this->pages-pages;
            cnt++;
        }
        string getDetails(){
            stringstream ss;
            ss<<"varos "<<weight<<endl;
            ss<<"selides "<<pages<<endl;
            return ss.str();
         }
         void toString() override{
            cout<<getBasicInfo();
            cout<<getDetails();
        }
};
int Paper::cnt=0;

class Eshop{
    vector<Item*> itemsList;
    vector<Item*> categoryList;
    Item* temp;
    vector<Buyer> buyerList;


    public:

            void addItem( Item* item ){
                itemsList.push_back(item);
            }

            void addCategory(Item* item){

                for(auto int i=0;i<=itemsList.size();i++){
                    for(auto int j=1;j<=itemsList.size();j++){
                            if(itemsList[i]==item){
                                    temp=itemsList[i];
                                    categoryList.push_back(temp);
                                    temp=item;
                                    categoryList.push_back(temp);							
                            }
                    }
                }
            }


            void showProduct(){
                for(auto i=0;i<=itemsList.size();i++){
                  itemsList[i]->toString();
                }
            }
            void showProductsInCategory(){
                for(auto i=0;i<=categoryList.size();i++){
                    categoryList[i]->toString();
                }
            }

            void removeItem( Item* item ){
                itemsList.erase(find(itemsList.begin(), itemsList.end(), item), itemsList.end());
            }
           void addBuyer( Buyer buyer ){
                buyerList.push_back(buyer);
            }
            void removeBuyer( Buyer buyer ){
                buyerList.erase(find(buyerList.begin(), buyerList.end(), buyer), buyerList.end());
            }	
};

int main(){

                    Eshop eshop;
                    Item* a= new Pen("kokkino",2.1);
                    a->setDetails("stilo", "me kapaki", 1242, 3, 1.5);
                    eshop.addItem(a);

                    Item* d= new Notebook(3);
                    d->setDetails("tetradio", "mikro", 1433, 5 ,4.5);
                    eshop.addItem(d);

                    Item* c= new Pencil(HB, 1.6);
                    c->setDetails("molivi", "mixaniko", 1334, 5, 2.00);
                    eshop.addItem(c);

                    Item* b= new Pen("ble",2.1);
                    b->setDetails("stilo", "aplo", 1233, 4, 1.5);
                    eshop.addItem(b);



                    Item* x= new Pencil(HB, 1.6);
                    x->setDetails("molivi", "kanoniko", 1334, 5, 2.00);
                    eshop.addItem(x);

                    Item* g= new Notebook(3);
                    g->setDetails("tetradio", "mikro", 1433, 5 ,4.5);

                    Item* e= new Notebook(2);
                    e->setDetails("tetradio", "megalo", 1432, 3 ,4.00);
                    eshop.addItem(e);



                    //eshop.removeItem(a); //diagrafei kapoio proion
                    eshop.showProduct();

                    cout << "Total Items: " << Item::cnt<<endl;
                    cout << "Pens: " << Pen::cnt<<endl;
                    cout << "Pencils: " << Pencil::cnt<<endl;
                    cout << "Notebooks: " << Notebook::cnt<<endl;
                    cout << "Papers: " << Paper::cnt<<endl<<endl;


	return 0;
}
