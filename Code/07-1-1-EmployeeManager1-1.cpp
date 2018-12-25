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

class SalesWorker{
	private:
		char name[100];
		int salesResult;
		double bonusRatio;
		int salary;
		
	public:
		// �����ڸ� ���� �̸��� ���� �Է� 
		SalesWorker(char* name, double _bonusRatio,int _salary) 
			:salesResult(0),bonusRatio(_bonusRatio),salary(_salary){
			strcpy(this->name, name);	
		}
		// ���� �Է� 
		void AddSalesResult(int value){
			salesResult+=value;
		}
		// ������ ������ ������ 
		int GetPay() const{
			return salary+(int)(salesResult*bonusRatio);
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
		// ������������ �迭 �߰� 
		SalesWorker * salesEmpList[50];
		int empNum;
		int salesNum;
	public:
		EmployeeHandler() : empNum(0),salesNum(0){	}
		
		// �ڵ鷯�� ��ü ��� 
		void AddEmployee(PermanentWorker* emp){
			empList[empNum++]=emp;
		}
		// �������� ��� �Լ� �߰� 
		void AddSales(SalesWorker* sale){
			salesEmpList[salesNum++]=sale;
		} 
		
		// ��� �ٷ��� �������� ���� Ȯ�� 
		void ShowAllSalaryInfo() const{
			for(int i=0; i<empNum; i++){
				empList[i]->ShowSalaryInfo();
			}
			//  ������ ���� Ȯ���� ���� �ݺ��� �߰� 
			for (int i=0; i<salesNum; i++){
				salesEmpList[i]->ShowSalaryInfo(); 
			}
		}
		// ��� ���� �ջ� 
		void ShowTotalSalary() const{
			int sum=0;
			for (int i=0; i<empNum; i++)
				sum+=empList[i]->GetPay();
			//�������� ���� �ջ��� ���� �ݺ��� �߰� 
			for (int i=0; i<salesNum; i++)
				sum+=salesEmpList[i]->GetPay();
			
			cout<<"salary sum: "<<sum<<endl;	
		}
		//  �Ҹ��ڿ��� empList ���� 
		~EmployeeHandler(){
			for(int i=0; i<empNum; i++)
				delete empList[i];
			// ������ �迭 ���� 
			for(int i=0; i<salesNum; i++)
				delete salesEmpList[i];
		}
};

int main(void){
	EmployeeHandler handler;
	
	// ���� ��� 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddSales(new SalesWorker("Gun",0.5,4000));
	handler.AddSales(new SalesWorker("Woo",0.5,5000));
	
	// �̹� �޿� �����ؾ� �� �޿��� ���� 
	handler.ShowAllSalaryInfo();
	
	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0; 
	
	
}
