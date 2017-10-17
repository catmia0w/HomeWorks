/*假设类Student有一个数据成员averGrade表示学生的平均学分绩，请给该类添加一个友元函数，用于计算两个学生的平均学分绩。*/
#include "iostream"
using namespace std;

class student
{
private:	double averGrade;
public:
	void getGrade()
	{
		cout << "请输入学生的平均学分绩：" << endl;
		cin >> averGrade;
	}
	friend double count(student& a,student& b)
	{
		cout << "两位学生的平均学分绩为："<<endl;
		cout<< ((a.averGrade + b.averGrade) / 2);
		return 0;
	}

};

int main()
{
	student stu1;
	student stu2;
	stu1.getGrade();
	stu2.getGrade();
	count(stu1,stu2);
	return 0;
}
