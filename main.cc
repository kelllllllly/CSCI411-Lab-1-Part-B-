#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 

using namespace std; 

int main() {
fstream thisProcFile; 


// Open the file for CPU information fstream thisProcFile; 
thisProcFile.open("/proc/sys/kernel/hostname", ios::in);
string line; 
// Read the file. Note this file only has the host name in it
getline(thisProcFile, line); 
cout << "Hostname: " << line << endl << endl; 

thisProcFile.close();


// getting the number of processers 
thisProcFile.open("/proc/cpuinfo", ios::in);
int count = 0; 
while (getline(thisProcFile,line)){
    if (line.find("processor") != string::npos){
        count++;
    }
}
cout << "Number of processsing units: " << count << endl;
thisProcFile.close();

// getting the CPU type and model 
thisProcFile.open("/proc/cpuinfo", ios::in); 
vector <string> cpustuff = {"processor", "vendor_id", "model"};
int loop; 
while( loop < 3 && getline(thisProcFile, line)){

    for(const auto cpustuffs : cpustuff){
    if(line.find(cpustuffs) != string::npos){
        cout << line << endl;
  }
    }
}
    

thisProcFile.close();

return 0;
}
