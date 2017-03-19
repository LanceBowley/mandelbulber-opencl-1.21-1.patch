//
// Created by lance on 3/18/17.
//
#include "Util.h"

std::string getThisDirectory ()
{
    std::string dir;
    system("bash ./Env.sh");
    std::ifstream envFile;
    envFile.open("EnvVar.txt");
    getline(envFile, dir);
    system("> EnvVar.txt");
    return dir;
}

void clearFile (std::string fileName)
{
    std::fstream file;
    file.open(fileName, std::fstream::out|std::fstream::trunc);
    file.close();
}

bool fileIsEmpty (std::string fileName)
{
    bool empty = false;
    std::ifstream file;
    file.open(fileName);
    std::string line1;
    std::getline(file, line1);
    if(!line1.compare("null") || !line1.compare(""))
    {
        empty = true;
    }
    return empty;
}

void log (std::string entry)
{
    std::fstream file;
    file.open("log.txt", std::fstream::app|std::fstream::out);
    file << entry;
}

void sysExec(std::string command)
{
    // command = "sudo " + command;
    const char * c = command.c_str();
    system(c);
}


void runCommandQueue (bool hold)
{
    std::string execPath = getThisDirectory() + "/Exec.sh";
    if (hold)
    {
        sysExec("echo \"wait\" >> " + execPath + "\n");
    }
    sysExec("bash " + execPath);
    clearFile(execPath);
}

void appendCommandToQueue(std::string command1)
{
    std::string execPath = getThisDirectory() + "/Exec.sh";
    std::string command2 = "echo \"" + command1 + "\" >> " + execPath + "\n";
    sysExec(command2);
}

std::vector<std::string> readAllLines(std::string filePath) {
    std::string line;
    std::vector<std::string> lines;
    std::fstream file;
    file.open(filePath);
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}


