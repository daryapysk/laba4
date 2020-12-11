class testClass
{
public:
	int x;
	int y;
	friend bool operator> (const testClass& c1, const testClass& c2);
	testClass(int x, int y);
	testClass();
};

