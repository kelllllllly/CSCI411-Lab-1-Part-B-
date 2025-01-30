#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
#include <sstream> 

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

thisProcFile.open("/proc/uptime", ios::in);
string reboot, idle; 

while(getline(thisProcFile, line)){
    stringstream read(line);
    // read in the first second (time since last reboot)
    getline(read, reboot, ' ');
    
    // read in the second seconds (idle time)
    getline(read, idle);

    cout << "Time since last re-boot " << reboot << " seconds." << endl;
    cout << "Time in idle is " << idle << " seconds." << endl << endl;
}

thisProcFile.close();

// memory info! 

thisProcFile.open("/proc/meminfo", ios::in);
int loop2;
while(loop2 < 2 && getline(thisProcFile, line)){
    cout << line << endl;
    loop2++;
}
thisProcFile.close();

return 0;
}
