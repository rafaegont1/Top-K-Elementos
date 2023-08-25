#include "utils.hpp"
#include <iostream>
#include <fstream>

using namespace std;

wchar_t *getText(const std::locale &loc, int &file_number)
{
  const string file_name = "./dataset/input"
                         + to_string(file_number++)
                         + ".data";
  wifstream txt(file_name, ios::binary);

  // Return nullptr if couldn't read file
  if(!txt.is_open()) return nullptr;

  // Set the locale to handle UTF-8 encoding
  txt.imbue(loc);

  // Determine the size of the file in bytes
  txt.seekg(0, ios::end);
  streampos fileSize = txt.tellg();
  txt.seekg(0, ios::beg);

  // Allocate memory for the wchar_t buffer
  wchar_t* buffer = new wchar_t[fileSize];

  // Read the file contents into the buffer
  txt.read(buffer, fileSize);

  // Close the file
  txt.close();

  return buffer;
}

void getStopWords(const std::locale &loc,
                  std::unordered_set<std::wstring> &set)
{
  wifstream txt("./dataset/stopwords.txt", ios::binary);
  wstring line;

  if(!txt.is_open()) {
    wcout << L"Nenhum arquivo de stop words foi encontrado!"
          << endl;
    return;
  }

  txt.imbue(loc);

  while(getline(txt, line)) {
    set.insert(line);
  }

  txt.close();
}

bool min_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b)
{ return a.second > b.second; }

bool max_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b)
{ return a.second < b.second; }
