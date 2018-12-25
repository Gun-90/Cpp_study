#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker{
	private:
		char name[100];
		int salary;
		
	public:
		// �����ڸ� ���� �̸��� ���� �Է� 
		PermanentWorker(char* name, int money) 
			:salary(money){
			strcpy(this->name, name);	
		}
		// ������ ������ ������ 
		int GetPay() const{
			return salary;
		}
		// �ٷ����� �̸��� ���� ǥ�� 
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
		// �����ڸ� ���� �̸��� ���� �Է� 
		TemporaryWorker(char *name, int pay)
			: workTime(7), payPerHour(pay){	
			strcpy(this->name, name);
		}
		
		// �ٷνð� �Է� 
		void AddWorkTime(int time){
			workTime+=time;
		}
		
		// ������ ������ ������ 
		int GetPay() const{
			return workTime*payPerHour;
		}
		// �ٷ����� �̸��� ���� ǥ��
		void ShowSalaryInfo() const{
			cout<<"name: "<<name<<endl;
			cout<<"salary: "<<GetPay()<<endl<<endl;
		}
};




class EmployeeHandler{
	private:
		PermanentWorker* empList[50];
		// �ӽ��������� �迭 �߰� 
		TemporaryWorker * tempEmpList[50];
		int empNum;
		int tempNum;
	public:
		EmployeeHandler() : empNum(0),tempNum(0){	}
		
		// �ڵ鷯�� ��ü ��� 
		void AddEmployee(PermanentWorker* emp){
			empList[empNum++]=emp;
		}
		// �ӽ����� ��� �Լ� �߰� 
		void AddTemps(TemporaryWorker* sale){
			tempEmpList[tempNum++]=sale;
		} 
		
		// ��� �ٷ��� �������� ���� Ȯ�� 
		void ShowAllSalaryInfo() const{
			for(int i=0; i<empNum; i++){
				empList[i]->ShowSalaryInfo();
			}
			// �ӽ���  ���� Ȯ���� ���� �ݺ��� �߰� 
			for (int i=0; i<tempNum; i++){
				tempEmpList[i]->ShowSalaryInfo(); 
			}
		}
		// ��� ���� �ջ� 
		void ShowTotalSalary() const{
			int sum=0;
			for (int i=0; i<empNum; i++)
				sum+=empList[i]->GetPay();
			//�ӽ��� ���� �ջ��� ���� �ݺ��� �߰� 
			for (int i=0; i<tempNum; i++)
				sum+=tempEmpList[i]->GetPay();
			
			cout<<"salary sum: "<<sum<<endl;	
		}
		//  �Ҹ��ڿ��� empList ���� 
		~EmployeeHandler(){
			for(int i=0; i<empNum; i++)
				delete empList[i];
			// ������ �迭 ���� 
			for(int i=0; i<tempNum; i++)
				delete tempEmpList[i];
		}
};

int main(void){
	EmployeeHandler handler;
	
	// ���� ��� 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddTemps(new TemporaryWorker("Gun",4000));
	handler.AddTemps(new TemporaryWorker("Woo",5000));
	
	// �̹� �޿� �����ؾ� �� �޿��� ���� 
	handler.ShowAllSalaryInfo();
	
	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0; 
	
	
}
