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
				cout << "Did you want to use some variables? " << endl;
				cout << "1) Yes" << endl;
				cout << "2) No" << endl;
				cin >> k;
				switch (k)
				{
				case 1:
				{
					res.PutVariable(res);
					break;
				}
				case 2:
				{
					break;
				}
				}
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



