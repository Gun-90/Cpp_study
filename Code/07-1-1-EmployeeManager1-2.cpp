#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker{
	private:
		char name[100];
		int salary;
		
	public:
		// 생성자를 통해 이름과 월급 입력 
		PermanentWorker(char* name, int money) 
			:salary(money){
			strcpy(this->name, name);	
		}
		// 봉급의 정보를 가져옴 
		int GetPay() const{
			return salary;
		}
		// 근로자의 이름과 월급 표시 
		void ShowSalaryInfo() const{
			cout<<"name: "<<name<<endl;
			cout<<"salary: "<<GetPay()<<endl<<endl;
		}
};

class TemporaryWorker{
	private:
		char name[100];
		int workTime;
		int payPerHour;
		int salary;
		
	public:
		// 생성자를 통해 이름과 월급 입력 
		TemporaryWorker(char *name, int pay)
			: workTime(7), payPerHour(pay){	
			strcpy(this->name, name);
		}
		
		// 근로시간 입력 
		void AddWorkTime(int time){
			workTime+=time;
		}
		
		// 봉급의 정보를 가져옴 
		int GetPay() const{
			return workTime*payPerHour;
		}
		// 근로자의 이름과 월급 표시
		void ShowSalaryInfo() const{
			cout<<"name: "<<name<<endl;
			cout<<"salary: "<<GetPay()<<endl<<endl;
		}
};




class EmployeeHandler{
	private:
		PermanentWorker* empList[50];
		// 임시직을위한 배열 추가 
		TemporaryWorker * tempEmpList[50];
		int empNum;
		int tempNum;
	public:
		EmployeeHandler() : empNum(0),tempNum(0){	}
		
		// 핸들러에 객체 등록 
		void AddEmployee(PermanentWorker* emp){
			empList[empNum++]=emp;
		}
		// 임시직원 등록 함수 추가 
		void AddTemps(TemporaryWorker* sale){
			tempEmpList[tempNum++]=sale;
		} 
		
		// 모든 근로자 개개인의 월급 확인 
		void ShowAllSalaryInfo() const{
			for(int i=0; i<empNum; i++){
				empList[i]->ShowSalaryInfo();
			}
			// 임시직  월급 확인을 위한 반복문 추가 
			for (int i=0; i<tempNum; i++){
				tempEmpList[i]->ShowSalaryInfo(); 
			}
		}
		// 모든 월급 합산 
		void ShowTotalSalary() const{
			int sum=0;
			for (int i=0; i<empNum; i++)
				sum+=empList[i]->GetPay();
			//임시직 월급 합산을 위한 반복문 추가 
			for (int i=0; i<tempNum; i++)
				sum+=tempEmpList[i]->GetPay();
			
			cout<<"salary sum: "<<sum<<endl;	
		}
		//  소멸자에서 empList 제거 
		~EmployeeHandler(){
			for(int i=0; i<empNum; i++)
				delete empList[i];
			// 영업직 배열 제거 
			for(int i=0; i<tempNum; i++)
				delete tempEmpList[i];
		}
};

int main(void){
	EmployeeHandler handler;
	
	// 직원 등록 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddTemps(new TemporaryWorker("Gun",4000));
	handler.AddTemps(new TemporaryWorker("Woo",5000));
	
	// 이번 달에 지불해야 할 급여의 정보 
	handler.ShowAllSalaryInfo();
	
	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0; 
	
	
}
