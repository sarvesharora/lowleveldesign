//Strategy Design Pattern

//Video Link
//https://youtu.be/u8DttUrXtEw



////problem 
//if you have several child classes(c1,c2,..cn) and some classes are grouped based on 
//functionality that they require for example c1,c2,c4 needs some same strategy therefore 
//parent class cannot have only one common function so it requires different strategy.


////solution 
//you make a interface with different strategy making a abstract class


//in example below a goodsvehicle require normal engine whereas sports and ofroad
//vehicle requires special engine, so the base vehicle class can not have a single engine
//so we have decided to make a interface engine and added normal and special engine to it 





#include<iostream>
#include<vector>
using namespace std;

//driver interface
class drive_interface {
public:
	virtual void engine() = 0;
};
class special_drive :public drive_interface{
public:
	void engine() {
		cout << "this is very special engone of 4K horse power"<<endl;
	}
};
class normal_drive :public drive_interface{
public:
	void engine() {
		cout << "this is the very normal engine"<<endl;
	}
};

//base class of vehicle
class Vehicle {
public:
	//we are making pointer as we cannot make the object
	//as the class is abstract
	drive_interface* drive;
	Vehicle(drive_interface * drive_obj) {
		drive = drive_obj;
	}
	void engine_drive() {
		drive->engine();
	}
};
class GoodsVehicle :public Vehicle{
public:
	GoodsVehicle():Vehicle(new normal_drive()) {

	}
};
class Offroad :public Vehicle {
public:
	Offroad() :Vehicle(new special_drive()) {

	}
};
class Sports : public Vehicle {
public:
	Sports() : Vehicle(new special_drive()) {

	}
};

int main() {
	
	Sports lambo;
	lambo.engine_drive();
	GoodsVehicle omni;
	omni.engine_drive();
}
