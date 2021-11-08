//
// Created by lineprog on 08.11.2021.
//
#include "dirstats-cli.h"

#include <utility>

FileEntry::FileEntry(string filename) {
    this->name = std::move(filename);
    this->lines = 0;
    this->words = 0;
    this->scanned = false;
}

void FileEntry::ScanFile() {
    ifstream ifile1;
    char buf[16000];
    char fname[16000];
    this.name.c_str();
    try {
        ifile1.open(fname, "r");
        while (!ifile1.eof())
        {
            ifile1.getline(buf, 16000);
        }
        ifile1.close();
    }
    catch (exception &E){

    }
}

int main()
{
    cout<<"Hello";
}

DirEntry::DirEntry(string dirname) {
    this->name=std::move(dirname);
    this->dirs=0;
    this->files=0;
    this->scanned=false;

}
