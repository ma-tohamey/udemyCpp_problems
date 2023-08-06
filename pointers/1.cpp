    #include <iostream>
    using namespace std;
     
    struct Employee {
    	string name;
    	int* id = nullptr;
     
    	Employee(int id_, string name_) {
    		name = name_;
    		id = new int { id_ };
    	}
     
    	~Employee() {
    		cout<<"Bye "<<flush;
    		if (id != nullptr)
    			delete id;
    		id = nullptr;
    	}
     
    	void print() {
    		cout << *id << " " << name << " ";
    	}
     
    	void set_nulls() {
    		id = nullptr;
    	}
    };
     
    int main() {
    	Employee e1(20, "belal");
     
    	e1.print();
     
    	Employee e2(e1);
     
    	e2.print();
    	e2.set_nulls();
     
    	return 0;
    }
     