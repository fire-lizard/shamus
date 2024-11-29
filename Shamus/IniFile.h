#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class IniFile {
public:
    IniFile(const string& filename);

    // Function to get the value of a key in a section
    string get(const string& section, const string& key, const string& defaultValue = "") const;

private:
    map<string, map<string, string>> data;

    // Helper function to load and parse the INI file
    void load(const string& filename);

    // Helper function to trim spaces from both sides of a string
    static string trim(const string& str);
};
