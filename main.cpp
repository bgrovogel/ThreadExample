#include <iostream>
#include <thread>
#include <chrono>

void worker_functionA(void)
{
        int loop = 0;
        // Loops a 1000 times
        while(loop < 1000)
        {
            // Sleep for 0.77 seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(0777));
            std::cout << "Group 1 Reporting: " << loop << std::endl;
            loop++;
        }
}

void worker_functionB(void)
{
        int loop = 0;
        // loops a 1000 times
        while(loop < 1000)
        {
          // Sleep for 0.66 seconds
           std::this_thread::sleep_for(std::chrono::milliseconds(0666));
           std::cout << "Group 2 Reporting: " << loop << std::endl;
           loop++;
        }
}

int main()
{
   char result;
   
   std::thread worker_threadA(worker_functionA); 
   std::thread worker_threadB(worker_functionB); 

  
   std::cout << "Groups will now start reporting" << std::endl;
   
   worker_threadA.join();
   worker_threadB.join();
   
   return 1;
}
