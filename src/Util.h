//
// Created by lance on 3/18/17.
//

#ifndef MANDELBULBER_OPENCL_1_21_1_PATCH_UTIL_H
#define MANDELBULBER_OPENCL_1_21_1_PATCH_UTIL_H


#include <string>
#include <bits/ios_base.h>
#include <ios>
#include <fstream>
#include <zconf.h>
#include <vector>

class Util {
    std::string getThisDirectory();
    void clearFile (std::string fileName);
    bool fileIsEmpty (std::string fileName);
    void log (std::string entry);
    void sleepSeconds (float seconds);
    std::vector<std::string> jsonFileToVector (std::string fileName);
    void runCommandQueue(bool hold = false);
    void sysExec(std::string command);
    void appendCommandToQueue(std::string command1);
    std::vector<std::string> readAllLines(std::string filePath);
};


#endif //MANDELBULBER_OPENCL_1_21_1_PATCH_UTIL_H
