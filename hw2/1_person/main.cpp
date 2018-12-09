#include "Person.h"

int	main()
{
	Person a;
	Person b("Smith", "John");
	Person c("Miller");

	cout << "Name of A: ";
	a.Show();

	cout << endl << "Name of B: ";
	b.Show();
	cout << endl << "Name of B (formal): ";
	b.FormalShow();
	
	cout << endl << "Name of C: ";
	c.Show();
	cout << endl << "Name of C (formal): ";
	c.FormalShow();
	cout << endl;
}
