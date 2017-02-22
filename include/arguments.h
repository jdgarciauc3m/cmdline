#ifndef XUL_CMDLINE_ARGUMENTS_H
#define XUL_CMDLINE_ARGUMENTS_H

#include <vector>
#include <string>
#include <cstring>
#include <experimental/string_view>

#include <algorithm>

namespace xul {

namespace cmdline {

class arguments;

class arguments_iterator {
  friend class arguments;

//Types
public:
  using argument_view = std::experimental::string_view;

public:
  // Copy interface
  arguments_iterator(const arguments_iterator &) = default;
  arguments_iterator & operator=(const arguments_iterator &) = default;

private:
  // Construct from arguments array to be used only from begin/end
  arguments_iterator(char const * const * p) : pstr_{p} {}

public:

  // Equality compare iterator
  bool operator==(arguments_iterator it) const noexcept { return pstr_ == it.pstr_; }
  bool operator!=(arguments_iterator it) const noexcept { return pstr_ != it.pstr_; }

  // Increment iterators
  arguments_iterator & operator++() noexcept { ++pstr_; return *this; }
  arguments_iterator operator++(int) noexcept { 
    arguments_iterator t{*this}; 
    operator++();
    return t;
  }

  // Addition to iterators
  arguments_iterator operator+(size_t delta) const noexcept { return arguments_iterator{pstr_+delta}; }

  // Get 
  argument_view operator*() const noexcept {
    return {*pstr_, std::strlen(*pstr_)};
  }

  argument_view operator*() noexcept {
    return {*pstr_, std::strlen(*pstr_)};
  }
private:
  // Pointer to the current argument string
  char const * const * pstr_;
};

// Represents argument from a program..
//
// It is expected that it is built providing main's argc and argv.
class arguments {
public:
  using argument_view = std::experimental::string_view;

public:
  arguments(int argc, char const ** argv) noexcept : argc_{argc}, argv_(argv) {}

  argument_view operator[](int i) const noexcept {
    return {argv_[i+1], std::strlen(argv_[i+1])};
  }

  arguments_iterator begin() const noexcept { return arguments_iterator{argv_+1}; }
  arguments_iterator end() const noexcept { return arguments_iterator{argv_ + argc_}; }

  int size() const { return argc_-1; }

  argument_view program_name() const noexcept { return {argv_[0], std::strlen(argv_[0])}; }

private:
  int argc_;
  char const * const * const argv_;
};

} // End namespace cmdline

} // End namespace xul

#endif
