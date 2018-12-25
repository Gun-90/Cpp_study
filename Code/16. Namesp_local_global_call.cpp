#include <iostream>
int val=100;

int main(void){
	int val=20;
	val+=3;
	::val+=7;
	
	std::cout<<val<<std::endl;
	std::cout<<::val<<std::endl;
	
	
	return 0;
}
