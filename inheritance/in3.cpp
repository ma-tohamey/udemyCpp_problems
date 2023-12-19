#include<iostream>
using namespace std;
 
class BaseClass
{
public:
     void Display()
    {
        cout << "\nThis is Display() method"
                " of BaseClass\n";
    }
    void Show()
    {
        cout << "\nThis is Show() method "
               "of BaseClass\n";
    }
};
 
class DerivedClass : public BaseClass
{
public:
    // Overriding method - new working of
    // base class display method
    void Display()
    {
        cout << "\nThis is Display() method"
               " of DerivedClass\n";
    }
};
 
// Driver code
int main()
{
    DerivedClass dr;
    BaseClass &bs = dr;
    bs.Display();
    dr.Display();
}
