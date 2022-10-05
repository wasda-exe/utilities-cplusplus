#include <iostream>
#include <string>
#include <Windows.h>

void __external_code__startup(LPCSTR lpApplicationName)
{
    // additional information
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    CreateProcessA(
        lpApplicationName, // the path
        NULL,              // Command line
        NULL,              // Process handle not inheritable
        NULL,              // Thread handle not inheritable
        FALSE,             // Set handle inheritance to FALSE
        // NULL, // Opens file in a separate console
        // 0,    // Opens file in a separate console
        CREATE_NEW_CONSOLE, // Opens file in a separate console
        NULL,               // Use parent's environment block
        NULL,               // Use parent's starting directory
        &si,                // Pointer to STARTUPINFO structure
        &pi                 // Pointer to PROCESS_INFORMATION structure
    );
    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main()
{
    // std::string szRelativePathToExe = "created-files\\utility__pkg\\utility--remove-space-file-name--add-file-number.exe";
    // std::wstring wszRelativePathToExe = std::wstring(szRelativePathToExe.begin(), szRelativePathToExe.end());
    // // LPCWSTR LPCWSTRzRelativePathToExe = wszRelativePathToExe.c_str();
    // LPCSTR LPCWSTRzRelativePathToExe = wszRelativePathToExe.c_str();

    // std::string szRelativePathToExe = "created-files\\utility__pkg\\utility--remove-space-file-name--add-file-number.cpp";
    // for debugging, taken to same level
    // std::string szRelativePathToExe = "utility--remove-space-file-name--add-file-number.exe";
    std::string szRelativePathToExe = "utility__pkg\\utility--remove-space-file-name--add-file-number.exe";
    LPCSTR LPCSTRzRelativePathToExe = szRelativePathToExe.c_str();
    __external_code__startup(LPCSTRzRelativePathToExe);

    // std::wstring *pwszRelativePathToExe = &wszRelativePathToExe;

    // if (!CreateProcess(LPCWSTRzRelativePathToExe, // No module name (use command line)
    //                    NULL,                      // Command line
    //                    NULL,                      // Process handle not inheritable
    //                    NULL,                      // Thread handle not inheritable
    //                    FALSE,                     // Set handle inheritance to FALSE
    //                    CREATE_NEW_CONSOLE,        // No creation flags
    //                    NULL,                      // Use parent's environment block
    //                    NULL,                      // Use parent's starting directory
    //                    NULL,                      // Pointer to STARTUPINFO structure
    //                    NULL)                      // Pointer to PROCESS_INFORMATION structure
    // )
    // {
    //     std::cerr << "CreateProcess failed \n";
    //     return -1;
    // }
}