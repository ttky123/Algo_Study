#include <iostream>
#include "myvector.h"
using namespace std;
 
int main()
{
	
	myvector a = myvector(64);
	myvector b = myvector(64);
	a[1] = 1;
	a.get_capacity();
	getchar();
}