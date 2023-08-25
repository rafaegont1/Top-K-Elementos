#ifndef UTILS_HPP
#define UTILS_HPP

#include <unordered_set>
#include <codecvt>

#define f first
#define s second

wchar_t *getText(const std::locale &loc, int &file_number);
void getStopWords(const std::locale &loc,
                  std::unordered_set<std::wstring> &set);
bool min_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b);
bool max_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b);

#endif /* UTILS_HPP */
