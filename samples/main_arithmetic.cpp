#include <arithmetic.h>

	using namespace std;
	
	int main()
	{
		try {
			string s;
			unsigned k;
			cout << "Enter the expression " << endl;
			getline(cin, s);
			Arithmetic res;
			res.vectorLexem(s);
			cout << endl;
			if (res.Correct()) {
				cout << endl;
				res.Postfix();
				cout << endl;
				res.print();
				cout << endl;
				res.PutVariable(res);
				cout << endl;
				cout << endl;
				cout << "Result: " << res.calculation();
				cout << endl;
			}
		}
	    catch (char* error) 
		{
					cout << error << endl;
				}
				cout << endl;
		return 0;
	}

