//MADE BY SHAH ZAMAN HAIDER
//https://github.com/ShahZamanHaider


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>

std::vector<std::string> dirs = { "F:\\XYZ\\src\\components", "F:\\XYZ\\src\\chrome\\app" };

int main() {
    std::string search = "Chromium";
    std::string replace = "XYZ";
    std::string userInput;
    int replacedFiles = 0;
    int notReplacedFiles = 0;

    std::cout << "Are you sure you want to perform this task? (y/n) : ";
    std::cin >> userInput;
    if (userInput == "y") {
        for (const auto& dir : dirs) {
            std::string search_path = dir + "\\*";
            std::replace(search_path.begin(), search_path.end(), '\\', '/');
            WIN32_FIND_DATAA fd;
            HANDLE hFind = FindFirstFileA(search_path.c_str(), &fd);
            if (hFind != INVALID_HANDLE_VALUE) {
                do {
                    std::string fileName = fd.cFileName;
                    if (fileName.find(".grdp") != std::string::npos || fileName.find(".grd") != std::string::npos) {
                        std::string fullPath = dir + "\\" + fileName;
                        std::replace(fullPath.begin(), fullPath.end(), '\\', '/');
                        std::ifstream file(fullPath);
                        if (file) {
                            std::string content((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
                            size_t pos = 0;
                            bool replaced = false;
                            while ((pos = content.find(search, pos)) != std::string::npos) {
                                content.replace(pos, search.length(), replace);
                                pos += replace.length();
                                replaced = true;
                            }
                            file.close();
                            if (replaced) {
                                std::ofstream outfile(fullPath);
                                if (outfile) {
                                    outfile << content;
                                    outfile.close();
                                    replacedFiles++;
                                }
                                else {
                                    std::cout << "Unable to write to file: " << fullPath << std::endl;
                                    notReplacedFiles++;
                                }
                            }
                            else {
                                
                                notReplacedFiles++;
                            }
                        }
                        else {
                            std::cout << "Unable to open file: " << fullPath << std::endl;
                            notReplacedFiles++;
                        }
                    }
                } while (FindNextFileA(hFind, &fd));
                FindClose(hFind);
            }
        }
        std::cout << "\n\nText replacement task completed." << std::endl;
        std::cout << "\nNumber of files in which text was replaced: " << replacedFiles << std::endl;
        std::cout << "Number of files in which text was not able to be replaced: " << notReplacedFiles << std::endl;
    }
    else {
        std::cout << "Text replacement task cancelled by user." << std::endl;
    }
    return 0;
}

//MADE BY SHAH ZAMAN HAIDER
