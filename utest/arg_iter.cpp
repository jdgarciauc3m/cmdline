#include "arguments.h"
#include <gtest/gtest.h>

TEST(arg_iter, valid_range)
{
  using namespace xul::cmdline;
  char const * argv[] { "prog", "arg1", "arg2" };
  arguments a{sizeof(argv)/sizeof(argv[0]), argv};
  auto first = a.begin();
  EXPECT_EQ("arg1", *first);
  EXPECT_EQ("arg2", *(first+1));
  EXPECT_EQ(a.end(), (first+2));
}

TEST(arg_iter, empty_range)
{
  using namespace xul::cmdline;
  char const * argv[] { "prog" };
  arguments a{sizeof(argv)/sizeof(argv[0]), argv};
  EXPECT_EQ(a.end(), a.begin());
}
