#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct node{
	char pname[30];
	float price;
	char category[10];
	int quantity;
	char pdate[15];
	char edate[15];
	node *next;
};
class product{
	private:
		node *head, *tail;
	public:
		product(){
			head=NULL;
			tail=NULL;
		}
		void add(){
			char choice='y';
			do{
				node *temp = new node;
				temp->next=NULL;
				cout<<"No Spaces ALLOWED ( Enter _ in place of space )";
				cout<<"\nEnter the Product Name: " ;
				cin>>temp->pname;
				cout<<"Enter the price of the product: ";
				cin>>temp->price;
				cout<<"Enter the category of the product: (Eatables, Self-cleansing, drinks, Home-cleaning, Technology) ";
				cin>>temp->category;
				cout<<"Enter the quantity of the product: ";
				cin>>temp->quantity;
				cout<<"Enter the purchase date of the product (dd-mm-yyyy): ";
				cin>>temp->pdate;
				cout<<"Enter the expiry date of the product (dd-mm-yyyy): ";
				cin>>temp->edate;
				cout<<"Your data is successfully Entered.";
				if(head==NULL){
					head=temp;
					tail=temp;
				}
				else
				{
					tail->next=temp;
					tail=tail->next;
				}
				cout<<"\nDo you want to add more?";
				cin>>choice;
			}while(choice=='y' || choice=='Y');
		}
		void display(){
			node *temp=new node;
			temp=head;
			cout<<"Name\tPrice\tCategory\tQuantity in Store\tPurchase Date\tExpiry Date";
			while(temp!=NULL){
				cout<<temp->pname<<"\t"<<temp->price<<"\t"<<temp->category<<"\t"<<temp->quantity<<"\t"<<temp->pdate<<"\t"<<temp->edate;
				temp=temp->next;
			}
			delete temp;
		}
		void searchc(){
			char Category[20];
			cout<<"Enter the category (Eatables, Self-cleansing, drinks, Home-cleaning, Technology): ";
			cin>>Category;
			node *temp=new node;
			temp=head;
			cout<<"Name\tPrice\tCategory\tQuantity in Store\tPurchase Date\tExpiry Date";
			while(temp!=NULL)
			{	
				if(strcmpi(temp->category,Category)==0){
					cout<<temp->pname<<"\t"<<temp->price<<"\t"<<temp->category<<"\t"<<temp->quantity<<"\t"<<temp->pdate<<"\t"<<temp->edate;
				}
				temp=temp->next;
			}
			delete temp;
		}
		void searchp(){
			int Price;
			cout<<"Enter the Max Price Limit: ";
			cin>>Price;
			node *temp=new node;
			temp=head;
			cout<<"Name\tPrice\tCategory\tQuantity in Store\tPurchase Date\tExpiry Date";
			while(temp!=NULL)
			{	
				if(temp->price<=Price){
					cout<<temp->pname<<"\t"<<temp->price<<"\t"<<temp->category<<"\t"<<temp->quantity<<"\t"<<temp->pdate<<"\t"<<temp->edate;
				}
				temp=temp->next;
			}
			delete temp;
		}		
};
int main(){
	product p;
	char ans='y';
	int choice;
	do{
		cout<<"What do you want to do?\n";
		cout<<"1.ADD Product's Details\n";
		cout<<"2.SHOW All Available Products\n";
		cout<<"3.Search by Category\n";
		cout<<"4.Search by Price\n";
		cout<<"5.Exit\n";
		cout<<"Enter your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: p.add();
				break;
			case 2:p.display();
				break;
			case 3:p.searchc();
				break;
			case 4: p.searchp();
				break;
			case 5: exit(0);
				break;
		}
		cout<<"\nDo you want to go to the main menu? (y/n)";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}

