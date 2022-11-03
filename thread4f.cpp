// CPP program to demonstrate multithreading
// using three different callables.

// test online:  https://www.onlinegdb.com/

#include <iostream>
#include <thread>
using namespace std;

float globale = 500;

void foo(int Z)
{
    // simula operazioni che consumano CPU
    for (int i = 0; i < 10*Z; i++) {
        cout << "Esegue Thread"<<Z<<"\n";
    }
    
    // modifica la variabile globale
    if (Z==1)  globale++;
    else if (Z==2)  globale--;
    else if (Z==3)  globale/=32;
}
  
int main()
{
    cout << "START" << endl;
  
    //crea thread
    thread th1(foo, 1);
    thread th2(foo, 2);
    thread th3(foo, 3);

    //join NB l'ordine NON sarà rispettato
    th1.join();
    th2.join();
    th3.join();
    
    cout << "globale = "<< globale;

    return 0;
}
