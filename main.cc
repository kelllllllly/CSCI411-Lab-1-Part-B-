#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

int main() {
fstream thisProcFile; 

// Open the file for CPU information fstream thisProcFile; 
thisProcFile.open("/proc/sys/kernel/hostname", ios::in);
// Read the file. Note this file only has the host name in it
string line; 
getline(thisProcFile, line); 
cout << "Hostname: " << line << endl << endl; 

// getting the number of processers 
cout << "Number of processsing units: ";
while (getline(thisProcFile,line)){

    if (line.find("processor") != string::npos){
        cout << line << endl;
    }
}
thisProcFile.close();

return 0;
}
