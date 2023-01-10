//Observer Design Patter
//Implement NOTIFY me Design pattern
// out of stocks product ka notify me implement krna hai

//Video Link
// https://youtu.be/Ep9_Zcgst3U



////problem 
//design the notify system 

////solution 
#include<iostream>
#include<vector>
using namespace std;

//interfaces
class observerInterface {
public:
	virtual void update() = 0;
};
class observableInterface {
public:
	virtual void add(observerInterface* obs) = 0;
	virtual void remove(observerInterface* obs) = 0;
	virtual void notify() = 0;
	virtual void setdata(int data) = 0;
	virtual void getdata() = 0;
};


//implementation
class product :public observableInterface {
public:
	vector<observerInterface*> Users;
	int totalproducts;
	product() {
		totalproducts = 0;
		Users = {};
	
	}
	void add(observerInterface* obs) {
		Users.push_back(obs);
	}
	void remove(observerInterface* obs) {

	}
	void notify() {
		for (auto itr : Users) {
			itr->update();
		}
	}
	void setdata(int data) {
		if (totalproducts == 0) {
			totalproducts += data;
			notify();
		}
		else {
			totalproducts += data;
		}
	}
	void getdata() {
		cout << totalproducts << endl;
	}
};
class MobileUser :public observerInterface {
public:
	//product data mem makes it dynamic  
	observableInterface* product;
	MobileUser(observableInterface* pr) {
		product = pr;
	}
	void update() {
		product->getdata();
	}
};



int main() {
	observableInterface *iphone = new product();
	observerInterface *m1 = new MobileUser(iphone);
	observerInterface* m2 = new MobileUser(iphone);

	iphone->add(m1);
	iphone->add(m2);

	iphone->setdata(10);
	iphone->setdata(10);




}
