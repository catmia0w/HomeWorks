#include "iostream"
using namespace std;

class Cat
{
private: static int HowManyCats;
public: static int HowMany()
	{
	    return HowManyCats;
	}
};
int Cat::HowManyCats=20;

int main()
{
    Cat cat;
    cout<<cat.HowMany();
	cout<<endl;
	return 0;
}
