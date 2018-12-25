#include <iostream>
using namespace std;

class First{
	public:
		virtual	void MyFunc(){ cout<<"FirstFunc"<<endl;}
};

class Second: public First{
	public:
		virtual void MyFunc(){ cout<<"SecondFunc"<<endl;}
};

class Third: public Second{
	public:
		virtual void MyFunc() { cout<<"ThirdFunc"<<endl;}
};

int main(void){
	Third * tptr = new Third();
	Second * sptr=tptr;  // sptr 포인터 변수가 tptr을 가리키게함 
	First * fptr= sptr;  // fptr포인터 변수가 tptr을 가리키게함 
	
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	
	return 0;
}
