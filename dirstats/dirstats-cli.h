//
// Created by lineprog on 08.11.2021.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "dirent.h"
#include "thread"

using namespace std;

#ifndef BCF_DIRSTATS_CLI_H
#define BCF_DIRSTATS_CLI_H

class DirEntry
{
public:
    string name;
    int files;
    int dirs;
    bool scanned;
    queue<string> Files, ScannedFiles;
    queue<string> Dirs, ScannedDirs;
    DirEntry(string dirname);
    ~DirEntry()= default;;
    static void ScanDir();
};
class FileEntry
{
public:
    string name;
    int lines;
    int words;
    bool scanned;
    FileEntry(string filename);
    static void ScanFile();
    ~FileEntry(){};
};
#endif //BCF_DIRSTATS_CLI_H