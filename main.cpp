#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void countwords(std::ifstream &inp, int &lines, int &words, int &characters)
{
    std::string line;
    while (std::getline(inp, line))
    {
        ++lines;
        characters += line.length() + 1;
        std::stringstream linestream(line);
        std::string word;
        while (linestream >> word)
        {
            ++words;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: dkwc [-options] <filename>" << "\n";
        return 1;
    }
    bool showWords = false;
    bool showLines = false;
    bool showCharacters = false;
    vector<string> options;
    for (int i = 1; i < argc - 1; i++)
    {
        options.push_back(argv[i]);
    }

    string filename = argv[argc - 1];

    if (filename.empty())
    {
        std::cerr << "Error: No input file specified\n";
        return 1;
    }

    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: could not open file\n";
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    countwords(file, lines, words, characters);
    if (argc == 2)
    {
        std::cout << filename << " " << lines << " " << words << " " << characters << "\n";
    }
    else
    {
        std::cout << filename << " ";
        for (auto it : options)
        {
            if (it == "-c")
            {
                cout << characters << " ";
            }
            if (it == "-l")
            {
                cout << lines << " ";
            }
            if (it == "-w")
            {
                cout << words << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}