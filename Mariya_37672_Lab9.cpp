//**************************************
//INCLUDE files for :Equation Solver
//**************************************
#include<iostream>
#include<conio.h>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;

//**************************************
// Name: Equation Solver
// Description: These program can solve first and second degree polynomial equation.
// It evens works when the roots are complex numbers(when delta is a negative value).
//
// Inputs: the coefficients of a polynomial equation
//
// Returns: the roots of the equation
//**************************************

class Root 
{
public:
	Root() {};
	~Root() {};
	void pres();
    void select();
    double root(double a, double b);
    double root_part1(double a, double b, double c, double D);
    double root_part2(double a, double b, double c, double D);
};

double Root::root(double a, double b)
{
	return(-b/a);
}

double Root::root_part1(double a, double b, double c, double D)
{ 
    return sqrt(D)/(2*a);
}

double Root::root_part2(double a, double b, double c, double D)
{
    return sqrt(-D)/(2*a);
}

void Root::pres()
{
    cout << "=============================================================================\n";
    cout << "		      Welcome to the equation solver!                                 \n";
    cout << " This program can solve any first or second degree polynomial equation \n";
    cout << "=============================================================================\n\n";
}

void Root::select()
{
    char car = (char)254;
    char exp = (char)253;
    cout << car << " For solving a first degree equation \"ax + b = 0\" enter '1' or enter '2' \n";
    cout << car << " for solving a second degree equation \"ax" << exp << " + bx + c = 0\": ";
}

void main()
{ 
    Root *p = new Root;
    double a = 0, b = 0, c = 0;
    int choix = 1;
    double D = 0, A = 0, B = 0, C = 0;
    char exp = ( char )253;
    char answer[5] = "yes";
    while( stricmp( answer, "no" ) != 0 )
	{
        p->pres();
        p->select();
        choix = getch();
		cout << endl << endl;
        	 
		switch(choix)
		{
		case '1':
			cout << "a = ";
			cin  >>  a;
            cout << "b = ";
            cin  >>  b;

			while( a == 0 ) 
			{
				cout << "\"a\" can't be 0, please choose another value: ";
				cin >> a;
			}

            cout << "your equation is: " << a << "x + " << b << " = 0" << endl;
            cout << "the solution is: x = "<< p->root( a, b ) << "\n";
            break;
		case '2':
			cout << "a = ";
            cin  >>  a;
            
			while( a == 0 ) 
			{
				cout << "\"a\" can't be 0, please choose another value: ";
				cin >> a;
			}

			cout << "b = ";
            cin  >>  b;
            cout << "c = ";
            cin  >>  c;

            D = b * b - ( 4 * a * c );
            A = -b/( 2 * a );
            cout <<"\nthe equation is: " << a << "x" << exp << " + " << b << "x + " << c << " = 0 " << endl;
            cout << "\nDelta = " << D  << endl << endl;
            if( D < 0 )
			{
                cout << "These equation have two complex roots" << endl;
                cout << "the first one is: x1 = "<< A << " + " << p->root_part2( a, b, c, D ) << "i" << endl;
                cout << "the second one is: x2 = "<< A << " - " << p->root_part2( a, b, c, D ) << "i" << endl;
            }
			else
			{
				cout << "These equation have two real roots" << endl;
                cout << "the first one is: x1 = " << ( -b/( 2 * a ) ) + p->root_part1( a, b, c, D )  << "\n";
                cout << "the second one is: x2 = " << ( -b/( 2 * a )) - p->root_part1( a, b, c, D )  << endl;
			}
            break;
		default: 
			cout << "\n\nThis selection is unknown,select '1' or '2'\n";
		}
        cout << "\nDo you want to solve another equation ? ( Yes ) or ( No )" << endl;
        cin >> answer;
        while(( stricmp( answer, "yes" ) != 0 ) && ( stricmp( answer, "no" ) != 0 ))
		{
            cout << "Please only answer by \"yes\" or \"no\"!" << endl;
            cin  >>  answer;
		}
        system("cls");
	}
    delete p;
}
                

		
