#include <iostream>
#include <fstream>
#include <sstream>
#include "ActiveCombatHeader.h"
// #define DISABLE_ACTIVE_COMBAT
#define IDENTIFIER_NAME(x) #x

std::string createModifiedNameCPP(std::string pszFileName, std::string pszFileNum)
{
    std::stringstream ss(pszFileName);

    std::string word;
    std::string newFileName;
    if (pszFileNum != "none" || pszFileNum != "NONE")
    {
        if (pszFileNum.size() == 1)
            pszFileNum.insert(0, "0");
        newFileName.append(pszFileNum + "--");
    }
    while (ss >> word)
    {
        newFileName.append(word);
    }
    newFileName.append(".cpp");
    return newFileName;
}

int processFileNameFileNum()
{
#ifndef ONLINE_JUDGE
    freopen((string{__FILE__}.substr(0, string{__FILE__}.find('.')) + "Error.txt").c_str(), "w", stderr);
#endif

    std::string szFileName, szFileNum;
    // can implement via open() mem func also, or constructor
    // std::ofstream out("utility--remove-space-file-name--add-file-number__file-name-list.txt", std::ofstream::app);
    std::ofstream outFile;
    outFile.open("utility--remove-space-file-name--add-file-number__file-name-list.txt", std::ofstream::app);
    if (!outFile)
    {
        std::cout << IDENTIFIER_NAME(outFile) << " was not created successfully";
        return -1;
    }

    std::string szFileAutoCreateFlag;
    std::cout << "Create file automatically? (y/n): ";
    // manip ws removes leading whitespace (\t, \n, ' ', \v, etc.) from input stream
    // ActiveCombatHeader includes bits/stdc++.h, so already added if Active is include
    getline(std::cin >> std::ws, szFileAutoCreateFlag);
    watch(szFileAutoCreateFlag);
    while (true)
    {
        std::cout << "File Number (Before Description) (or, Type \"exit\" or \"none\"): ";
        getline(std::cin >> std::ws, szFileNum);
        watch(szFileNum);
        if (szFileNum == "exit" || szFileNum == "EXIT")
            break;

        std::cout << "File Name (Remove Spaces) (Directly Paste In): ";
        getline(std::cin, szFileName);
        watch(szFileName);

        std::string modifiedFileName = createModifiedNameCPP(szFileName, szFileNum);
        outFile << modifiedFileName << '\n';
        outFile.flush();

        std::cout << modifiedFileName << '\n';

        if (szFileAutoCreateFlag != "y" && szFileAutoCreateFlag != "Y")
        {
            continue;
        }
        // new file created for every loop
        // tempFile.open(IDENTIFIER_NAME(modifiedFileName), std::ofstream::out);
        std::ofstream tempFile;
        if (!tempFile)
        {
            std::cout << IDENTIFIER_NAME(tempFile) << " was not created successfully";
            return -1;
        }

        // tempFile.open("created-files\\" + modifiedFileName, std::ofstream::out);
        // tempFile.open(modifiedFileName, std::ofstream::out);

        // this is a dirty, terrible solution. I wanted to use <filesystem>
        // to chk if the directory existed, but filesys no work for me, lel,
        // so we inverted the folder structure to construct in a file that is
        // guaranteed to exist, i.e, the folder before the current one

        // windows specific
        // tempFile.open("..\\" + modifiedFileName, std::ofstream::out);
        tempFile.open("..\\" + modifiedFileName, std::ofstream::out);
    }
    return 0;
}

int main()
{
    processFileNameFileNum();
    return 0;
}