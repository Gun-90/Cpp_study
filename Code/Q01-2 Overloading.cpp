#include <iostream>
using namespace std;

void swap(int* num1, int* num2);
void swap(char* ch1, char *ch2);
void swap(double* ch1, double* ch2);
int main(void){
	int num1=20, num2=30;
	swap(&num1,&num2);
	cout<<num1<<' '<<num2<<endl;
	
	char ch1= 'a', ch2= 'b';
	swap(&ch1, &ch2);
	cout<<ch1<<' '<<ch2<<endl;
	
	double db1=1.111, db2 = 5.555;
	swap(&db1, &db2);
	cout<<db1<<' '<<db2<< endl;
}

void swap(int* num1, int* num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(char* num1, char* num2){
	char temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(double* num1, double* num2){
	double temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

