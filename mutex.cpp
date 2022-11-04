#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono;

std::mutex m;
int i = 0; 
void makeACallFromPhoneBooth(bool mutex) 
{
    if (mutex) m.lock();  //thread locks the phone booth door  
    
    std::cout <<"\n"<< i << " Hello my friend " << std::endl;
    for (int j=0;j<999999;j++); //"durata" telefonata
    i++;
    //...until now, with no interruption from other men
    
    if (mutex) m.unlock();//thread unlocks the phone booth door 
}

int main() 
{
  bool mutex=true; //prova a cambiare questo valore e ad eseguire più volte, prendendo nota di tempo e risultati
    
    std::cout<<"mutex=="<<mutex;
    auto start_t = high_resolution_clock::now();
    
    std::thread man1(makeACallFromPhoneBooth,mutex);
    std::thread man2(makeACallFromPhoneBooth,mutex);
    std::thread man3(makeACallFromPhoneBooth,mutex);
    std::thread man4(makeACallFromPhoneBooth,mutex);
    std::thread man5(makeACallFromPhoneBooth,mutex);
    std::thread man6(makeACallFromPhoneBooth,mutex);
    std::thread man7(makeACallFromPhoneBooth,mutex);
    std::thread man8(makeACallFromPhoneBooth,mutex);
    std::thread man9(makeACallFromPhoneBooth,mutex);
    std::thread man10(makeACallFromPhoneBooth,mutex);

    man1.join();
    man2.join();
    man3.join();
    man4.join();
    man5.join();
    man6.join();
    man7.join();
    man8.join();
    man9.join();
    man10.join();
    
    auto stop_t = high_resolution_clock::now();
	  auto duration = duration_cast<microseconds>(stop_t - start_t);
 
	  std::cout <<"Durata: "<< duration.count() << "\n";

    return 0;
}
