/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h> 

using namespace std;

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}


int main()
{
    cout<<"Hello World";
    
    int x = 34;
    float y = 1 / sqrt(x);
    float y1 = Q_rsqrt(x);
    
    cout << "La radice inversa esatta di "<<x<<" è: "<<y;
    cout << "\n La radice inversa approssimata di "<<x<<" è: "<<y1;

    return 0;
}
