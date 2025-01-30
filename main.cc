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
cout << "Number of processsing units: " << count << endl << endl;
thisProcFile.close();

cout << "CPU(s) Type and model: " << endl;
// getting the CPU type and model 
thisProcFile.open("/proc/cpuinfo", ios::in); 

vector <string> cpustuff = {"processor", "vendor_id", "model"};
int loop; 
while( loop < 3 && getline(thisProcFile, line)){
    for(const auto cpustuffs : cpustuff){
        if(line.find(cpustuffs) != string::npos){
            cout << line << endl;
            loop++;
        }
    }
}

cout << endl;

thisProcFile.close();

// kernel version

thisProcFile.open("/proc/version", ios::in);
getline(thisProcFile, line);
cout << "Linux Kernel Version: " << line << endl << endl;
thisProcFile.close(); 

// System time
string seconds1;
string seconds2;

thisProcFile.open("/proc/uptime", ios::in);
getline(thisProcFile, line);
thisProcFile >> seconds1 >> seconds2; 

cout << seconds1 << seconds2; 

thisProcFile.close();

return 0;
}
