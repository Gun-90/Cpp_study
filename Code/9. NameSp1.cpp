#include <iostream>

namespace BestComImpl{
	void SimpleFunc(void){
		std::cout<<"BestCom define function"<<std::endl;
		
	}	
}

namespace ProgComImpl{
	void SimpleFunc(void){
		std::cout<<"ProgCom define function"<<std::endl;
	}
}
int main(void){
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	
}
