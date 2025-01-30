#include <iostream>
#include <fstream>
#include <string> 

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
thisProcFile.open("/proc/cpuinfo, ios::in");
int count = 0; 
string readin;
while (getline(thisProcFile,readin)){
    if (line.find("processor") != string::npos){
        count++;
    }
}
cout << "Number of processsing units: " << count << endl;
thisProcFile.close();

return 0;
}
