#include "arguments.h"
#include <iostream>

int main(int argc, char const ** argv)
{
  using namespace xul::cmdline;
  using namespace std;

  arguments args{argc,argv};

  cout << "Number of arguments:" << args.size() << endl;
  cout << "Program: " << args.program_name() << endl;  
  cout << "\nArguments interation:\n";
  for (auto a : args) {
    cout << "\t" << a << endl;
  }

  cout << "\nArguments indexing:\n";
  for (int i=0;i<args.size();++i) {
    cout << "\tArgument " << i << ": " << args[i] << endl;
  }
}
