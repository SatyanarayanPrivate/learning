#include<iostream>
using namespace std;
namespace nm23
{

	class Employee
	{
	public:
		void DoJob()
		{
			cout << "Employee Job" << endl;
		}
		virtual ~Employee()
		{

		}
	};
	class Manager :public Employee//Is-A
	{
	public:
		void DoJob()
		{
			cout << "Employee Job" << endl;
		}
	};
	class Tester :public Employee
	{
	public:
		void DoJob()
		{
			cout << "Employee Job" << endl;
		}
	};


	void Business(Employee & emp)
	{
		cout << "emp=" << typeid(emp).name() << endl;
		if (typeid(emp) == typeid(Manager))
			cout << "Apple" << endl;
		else
			cout << "Orange" << endl;

		cout << "Business started " << endl;
		emp.DoJob();
		cout << "Business completed " << endl;
		cout << "__________________________" << endl;
	}

	void main()
	{
		Manager man;
		Tester tester;
		Business(man);
		Business(tester);
	}
}