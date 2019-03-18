#include <iostream>

using namespace std;

class RandomClass 
{
	int *a, *b, *c;
public:
	RandomClass(int* x, int* y, int* z) :a(x), b(y), c(z) {};

	
	void operator++(int x)
	{
		*a += 5;
		*b += 4;
		*c += 3;
		cout << *a << endl;
		cout << *b << endl;
		cout << *c << endl;
	}

	friend ostream &operator<<(ostream &out,const RandomClass temp) 
	{
		out << *(temp.a) << ", " << *(temp.b) << ", " << *(temp.c);
		return out;
	}
};
//int main() 
//{
//	int X = 2, Y = 6, Z = 19;
//	RandomClass Class= RandomClass(&X, &Y, &Z);
//	Class++;
//	cout << Class<<endl;
//	getchar();
//	return 0;
//}