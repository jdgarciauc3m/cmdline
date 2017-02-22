#include "arguments.h"
#include <gtest/gtest.h>

TEST(arg_init, empty)
{
  using namespace xul::cmdline;
  char const * argv[] { "prog" };
  arguments a{1, argv};
  EXPECT_EQ(0,a.size());
  EXPECT_EQ("prog", a.program_name());
}

TEST(arg_init, one)
{
  using namespace xul::cmdline;
  char const * argv[] { "prog", "arg1" };
  arguments a{sizeof(argv)/sizeof(argv[0]), argv};
  EXPECT_EQ(1,a.size());
  EXPECT_EQ("prog", a.program_name());
  EXPECT_EQ("arg1", a[0]);
}

TEST(arg_init, two)
{
  using namespace xul::cmdline;
  char const * argv[] { "prog", "arg1", "arg2" };
  arguments a{sizeof(argv)/sizeof(argv[0]), argv};
  EXPECT_EQ(2,a.size());
  EXPECT_EQ("prog", a.program_name());
  EXPECT_EQ("arg1", a[0]);
  EXPECT_EQ("arg2", a[1]);
}
