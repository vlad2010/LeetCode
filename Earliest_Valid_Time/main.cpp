#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "earliest_time.h"

using namespace std;

vector<string> separate_string(string s);

int main()
{
    std::ifstream file("testcases.txt");
    
    std::string str; 
    while (std::getline(file, str))
    {
        if(str.find_first_not_of(' ') != std::string::npos)
        {
            vector<string> cmp = separate_string(str);

            if(cmp.size()<7)
            {
                cout << "ERROR: Invalid test case: " << str << endl;
                continue;
            }

            string res_time = get_earliest_time(
                    stoi(cmp[0]),                      
                    stoi(cmp[1]),                      
                    stoi(cmp[2]),                      
                    stoi(cmp[3]),                      
                    stoi(cmp[4]),                      
                    stoi(cmp[5]));

            if (res_time.compare(cmp[6]))
            {
                cout << "Test case falure. Res: " << res_time 
                      << " for line: " << str << endl; 
            }
        }
    }
}

vector<string> separate_string(string str)
{
    vector<string> v; 
    stringstream ss(str); 
  
    while (ss.good()) 
    { 
        string substr; 
        getline(ss, substr, ','); 
        v.push_back(substr); 
    } 
    return v;
}