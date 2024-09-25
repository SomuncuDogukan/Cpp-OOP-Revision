/*
######################### ENCAPSULATION ############################################
What is encapsulation?

Encapsulation is an object-oriented programming (OOP) concept that involves bundling the data (variables) 
and the methods (functions) that operate on the data into a single unit, known as a class. 
It restricts direct access to some of the object's components, ensuring controlled interaction 
with the data through public methods (getters/setters).

What is encapsulation used for?

Encapsulation is used to protect the internal state of an object from unintended or harmful changes. 
By controlling access to the data through defined interfaces, it promotes data integrity, 
improves modularity, and enhances code maintainability and security.

######################### ABSTRACTION ############################################
What is abstraction?

Abstraction is an object-oriented programming (OOP) concept that focuses on simplifying complex systems 
by only exposing essential details while hiding the underlying implementation.
It enables programmers to handle objects at a higher level, without needing to understand the inner workings. 
This is typically achieved using abstract classes or interfaces.

What is abstraction used for?

Abstraction is used to reduce complexity and increase efficiency by providing a clear separation between 
what a system does and how it does it. It allows developers to focus on the functionality rather than 
the implementation, promoting code reusability, flexibility, and easier maintenance across complex systems.

What is inheritance?

Inheritance is an object-oriented programming (OOP) concept that allows a new class (known as a derived class or subclass) to 
inherit properties and methods from an existing class (known as a base class or superclass). This mechanism promotes code reusability 
and establishes a hierarchical relationship between classes, allowing the derived class to extend or modify the behaviors of the base class.

What is inheritance used for?

Inheritance is used to create a new class that builds upon the functionality of an existing class, allowing developers to reuse code 
and reduce redundancy. It enables polymorphism, where a derived class can be treated as an instance of its base class. 
This leads to more organized and manageable code, facilitating easier maintenance and scalability of applications.

What is polymorphism?

Polymorphism is an object-oriented programming (OOP) concept that allows objects of different classes to be treated as instances of the same base class. 
It enables one interface to be used for a general class of actions, where the specific action is determined by the type of object that is calling the method. 
Polymorphism can be achieved through method overriding (runtime polymorphism) and method overloading (compile-time polymorphism).
What is polymorphism used for?

Polymorphism is used to provide flexibility and extensibility in code. It allows developers to write more generic and reusable code, where a single function or 
method can work with different types of objects. This leads to cleaner, more maintainable systems, as new classes can be added with minimal changes to existing code. 
It is fundamental for implementing interfaces and ensuring scalability in complex systems.
*/





///////////////////////////////////////////////////////////////////////////

class AbstractEmployee {   	//Interface kinda //Acts like an interface in C++

	virtual void AskForPromotion() = 0; //=0 means it is pure virtual function // Declared with = 0; must be overridden in the derived class.


};



#include <iostream>
using std::string;
class Employee :AbstractEmployee { //:AbstractEmployee inherited
private: //private : Only accessible within the Employee class, not by derived classes or outside objects
	
	string Company;
	int Age;

protected: //protected: Can be accessed by derived classes but not from outside the class
	string Name;

public:    //public: Can be accessed from outside the class to create an instance of Employee
	void setName(string name) { //setter
		Name = name;

	}

	string getName() { //getter
		return Name;
	}

	void setCompany(string company) {
		Company = company;

	}

	string getCompany() {
		return Company;
	}

	void setAge(int age) {
		//validation rule
		if (age >= 18) Age = age;


	}

	int getAge() {
		return Age;
	}

	void IntroduceYourself() {

		std::cout << "Name - " << Name << std::endl;
		std::cout << "Age - " << Age << std::endl;
		std::cout << "Company - " << Company << std::endl;

	}

	//Consturctor
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;

	}

	void AskForPromotion() {
		//Assume that implementation of complex logic for example
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " no promotion for you!\n";

	}
	
	//polymoprhism purpose
	virtual void Work() { //when function is virtual here, is like cheking if there are other Work function implemented on derived class if yes execture them instead of this one
		std::cout << Name << " is chechking email, task backlog, performing tasks" << std::endl;

	}

};
							 //The Developer class inherits from the Employee class.	
class Developer: public Employee {  //In this case, Developer became the subclass (derived class or child class), and Employee is called the base class, superclass, or parent class.
							//This inheritence private by default if we write like  "class Developer: Employee" so we add public modifier.

public:
	string FavProgrammingLanguage;

	// Constructor has no return type, has the same name as the class, and should be public.
	Developer(string name, string company, int age, string favProgrammingLanguage)
	:Employee(name, company,age) //Call the Employee constructor to initialize inherited properties (name, company, age) instead of assigning them again in the Developer class
	{
		//Additional Developer-specific initialization here
		FavProgrammingLanguage = favProgrammingLanguage;

	}
	
	void FixBug() {

		std::cout << getName() << "fixed bug using " << FavProgrammingLanguage << std::endl;

		//I can reach Name here directly because it is protected. Derieved class
		std::cout << Name << "fixed bug using " << FavProgrammingLanguage << std::endl;

	
	}

	void Work() {

		std::cout << Name << " is writing " << FavProgrammingLanguage << "code" << std::endl;

	}

};

class Teacher:public Employee { //class is private by default to be able to reach it we are making public
public:
	string Subject;
	
	void PrepareLesson() {

		std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
	
	}

	Teacher(string name, string company, int age, string subject)
	:Employee(name, company,age)
	{
		Subject = subject;
	}

	void Work() {

		std::cout << Name << " is teaching " << Subject << std::endl;

	}
};


int main (){ // The most common use of polymorphism is when a parent class reference is used to refer to a child class object

	Employee employee1 = Employee("EMP1", "companyTest", 99);
	employee1.IntroduceYourself();
	
	Employee employee2 = Employee("employee2", "Company2", 16);
	employee2.IntroduceYourself();

	Developer d = Developer("insideDevName ", "DevEmp", 22, "c++");
	d.FixBug();
	d.AskForPromotion(); //I can reach that method because now it is public inheritence comes from "class Developer: public Employee"



	//Teacher object has been created.
	Teacher t = Teacher("TeacherName", "School", 25, "Math");  //Copy Initialization: A temporary object is created, which is then copied to the target object.

	//Teacher t("TeacherName", "School", 25, "Math");  //Direct Initialization: An object is created by directly calling the constructor.

	//Key Differences:
	//Performance: Direct Initialization is usually faster as it creates only one object.
	//Copying: Copy Initialization involves additional copying, leading to more overhead.

	t.PrepareLesson();
	t.AskForPromotion();

	//Encapsulation test
	/*employee1.setAge(15);
	std::cout << employee1.getName() << " is " << employee1.getAge() << " years" << std::endl;*/


	/*employee1.AskForPromotion();
	employee2.AskForPromotion();
	*/


	//polymorphism//
	
	//d.Work();
	//t.Work();


	Employee* e1 = &d;
	Employee* e2 = &t;

	e1->Work();
	e2->Work();
	
	return 0;
}