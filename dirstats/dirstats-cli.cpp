//
// Created by lineprog on 08.11.2021.
//
#include "dirstats-cli.h"

#include <utility>

DirEntry::DirEntry() {
    char cwd[16000];
    if ((getcwd(cwd, 16000)) != nullptr)
        this->name = string(cwd);
    this->dirs=0;
    this->files=0;
    this->scanned=false;
}

DirEntry::DirEntry(string dirname) {
    this->name=std::move(dirname);
    this->dirs=0;
    this->files=0;
    this->scanned=false;
}

void DirEntry::ScanDir() {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(this->name.c_str())) == NULL)
        perror("Can't read directory");
    else{
        while ((entry = readdir(dir)) != NULL)
        {
            //add found directory to queue
            if (entry->d_type == DT_DIR)
            {
                this->dirs++;
                this->Dirs.push(this->name + string(entry->d_name));
            }
            //add found file to queue
            if (entry->d_type == DT_REG)
            {
                this->files++;
                this->Files.push(this->name + string(entry->d_name));
            }
        }
        closedir(dir);
    }
}
FileEntry::FileEntry(string filename) {
    this->name = std::move(filename);
    this->lines = 0;
    this->words = 0;
    this->scanned = false;
}

void FileEntry::ScanFile() {
    ifstream ifile1;
    stringstream streamBuf;
    char buf[16000];
    try {
        ifile1.open(this->name.c_str(), ios_base::in);
        // odczyt ilości linii
        while (!ifile1.eof())
        {
            ifile1.getline(buf, 16000);
            streamBuf<<buf;
            while (streamBuf.get(buf,16000))
            {
                this->words++;
            }
            this->lines++;
        }
        ifile1.close();
        this->scanned = true;
    }
    catch (exception &E){
        fputs("File read error: ", stderr);
        fputs(this->name.c_str(), stderr);
    }
}


int main(int argc, char ** argv)
{
    if (argc<2)
    {
        cout<<"Proszę wybrać plik.";
    } else{
        for (int i = 0; i < argc; i++) {
            cout<<argv[0]<<" ";
        }
    }
}
