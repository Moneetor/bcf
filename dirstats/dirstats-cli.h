//
// Created by lineprog on 08.11.2021.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "dirent.h"
#include "sstream"
#include "thread"
#include <unistd.h>

using namespace std;

#ifndef BCF_DIRSTATS_CLI_H
#define BCF_DIRSTATS_CLI_H

class DirEntry
{
public:
    string name;
    int files{};
    int dirs{};
    bool scanned{};
    static queue<string> Files, ScannedFiles, ProcessingFiles;
    static queue<string> Dirs, ScannedDirs, ProcessingDirs;
    DirEntry();
    explicit DirEntry(string dirname);
    ~DirEntry()= default;;
    void ScanDir();
};
class FileEntry
{
public:
    string name;
    int lines;
    int words;
    bool scanned;
    explicit FileEntry(string filename);
    void ScanFile();
    ~FileEntry(){};
};
#endif //BCF_DIRSTATS_CLI_H
