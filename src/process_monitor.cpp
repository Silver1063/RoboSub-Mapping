#include <sys/resource.h>
#include <iostream>

// how to use
//  1. include me
//  2. call process_mem_usage() whenever
//  3. awsomesauce

inline void process_mem_usage()
{
   struct rusage r_usage;
   int err = getrusage(RUSAGE_SELF, &r_usage);
   if (err = -1)
   {
      std::cout << "ummm something went bad" << std::endl;
      return;
   }

   std::cout << std::fixed;
   std::cout.precision(2);
   std::cout << "Using: " << r_usage.ru_maxrss / 1024.0 << " MB" << std::endl;
}
