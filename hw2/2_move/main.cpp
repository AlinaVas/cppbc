#include "Move.h"
#include <iostream>

int main()
{
	Move i;
	cout << "==== Move i ====" << endl;
	i.showmove();

	Move j(5.9, 10.1);
	cout << "==== Move j ====" << endl;
	j.showmove();

	i.reset(0.1, 0.9);
	cout << "==== Reset i ===" << endl;
	i.showmove();
	
	cout << "==== Move k ====" << endl;
	Move k = i.add(j);
	k.showmove();
}
