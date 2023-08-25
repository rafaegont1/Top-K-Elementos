#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <chrono>

#define endl L'\n'

using namespace std;

const int HEAP_SIZE = 20;
const wchar_t *word_end = L".!? ,:;()'\"-/\n";

int main()
{
  auto start = chrono::high_resolution_clock::now();

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  unordered_map<wstring, unsigned short> mp;
  unordered_set<wstring> stop_words;
  int file_number = 1;
  wchar_t *buffer = getText(loc, file_number);

  getStopWords(loc, stop_words);

  // Put all words of the inputs on a map
  // (except stop words defined in 'stopwords.txt')

  while(buffer != nullptr) {
    wstring word;

    for(wchar_t *c = buffer; *c; c++) {
      if(!wcschr(word_end, *c)) {
        word += tolower(*c);
      } else if(!word.empty()) {
        if(!stop_words.count(word)) ++mp[word];
        word.clear();
      }
    }

    delete[] buffer;
    buffer = getText(loc, file_number);
  }

//wcout << L"------------------------------\n" 
//         L"Palavras no mapa:" << endl;
//for(const auto &word : mp) {
//  wcout << word.f << L": " << word.s << endl;
//}
//wcout << L"------------------------------" << endl;

  // Search for K most frequent words
  // (K is defined by HEAP_SIZE)

  auto it = mp.begin();
  vector<pair<wstring, unsigned short>> heap;

  for(int i = 0; i < HEAP_SIZE && it != mp.end(); i++, it++) {
    heap.push_back(*it);
  }

  make_heap(heap.begin(), heap.end(), min_heap);

  while(it != mp.end()) {
    if(it->s > heap.front().s) {
      heap.front() = *it;
      make_heap(heap.begin(), heap.end(), min_heap);
    }
    ++it;
  }

  make_heap(heap.begin(), heap.end(), max_heap);

  for(const auto &word : heap) {
    wcout << word.f << L": " << word.s << endl;
  }

  // Show execution time in milliseconds

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>
    (stop - start);
  wcout << '\n' << duration.count() << " ms" << endl;

  return 0;
}
