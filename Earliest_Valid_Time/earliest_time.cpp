#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>  

using namespace std;

std::string get_earliest_time(int A, int B, int C, int D, int E, int F)
{
    // std::cout << "get_earliest_time() Input params are: " << A << "," 
    // << B << "," << C << "," << D << "," << E << "," << F << std::endl;
    
    int vals[6] = {A,B,C,D,E,F};
    std::sort(begin(vals),  std::end(vals), [](int &p1,int &p2) {return p1<p2;} );

    string error = "NOT POSSIBLE";
    string valid_time = ""; 

   // check 'seconds' first digit
   // array is sorted , so if TRUE other numbers also less than 6   
   if (vals[4] < 6) 
   { 
        // if number of hours is correct ? 
        if (10 * vals[0] + vals[1] < 24)
        {
            return std::to_string(vals[0]) +
                std::to_string(vals[1]) + ":" +
                std::to_string(vals[2]) +
                std::to_string(vals[3]) + ":" +
                std::to_string(vals[4]) +
                std::to_string(vals[5]);
        }
        else
        {
          return error;
        }
   } 
   else
   // check 'minutes' second digit  
   if (vals[3] < 6) 
   {
        // if number of hours is correct ? 
        if (10 * vals[0] + vals[1] < 24)
        {
            //  minutes and seconds 
            return std::to_string(vals[0]) +
                std::to_string(vals[1]) + ":" +
                std::to_string(vals[2]) +
                std::to_string(vals[4]) + ":" +
                std::to_string(vals[3]) +
                std::to_string(vals[5]);

        }
        else
        {
            return error;
        }
    } 
    //Our last chance. check 'minutes' first digit 
    else if (vals[2] < 6) 
    { 
        // check that we can have correct 'hours' using component 0 and 3
        if (10 * vals[0] + vals[3] < 24)
        {
                 return std::to_string(vals[0]) +
                       std::to_string(vals[3]) + ":" +
                       std::to_string(vals[1]) +
                       std::to_string(vals[4]) + ":" +
                       std::to_string(vals[2]) +
                       std::to_string(vals[5]);

        }
    } 
  
    return error;
}

