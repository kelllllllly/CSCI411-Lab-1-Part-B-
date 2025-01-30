#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

int main() {
fstream thisProcFile; 
string line; 

// Open the file for CPU information fstream thisProcFile; 
thisProcFile.open("/proc/sys/kernel/hostname", ios::in);
// Read the file. Note this file only has the host name in it
getline(thisProcFile, line); 
cout << "Hostname: " << line << endl << endl; 

thisProcFile.close();


// getting the number of processers 
thisProcFile.open("/proc/cpuinfo, ios::in");
int count = 0; 
string line;
while (getline(thisProcFile,line)){
    if (line.find("processor") !=string::npos){
        count++;
    }
}
cout << "Number of processsing units: " << count << endl;
thisProcFile.close();

return 0;
}
