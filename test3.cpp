#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "priority_queue.h"

TEST_CASE("testing empty", "[empty]")
{
  int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
  Priority_queue<int> q1, q2, q3;

  for (int i = 0; i < 13; i++)
  {
    if (i < 5)
    {
      q2.push(adding[i]);
    }
    q3.push(adding[i]);
  }

  REQUIRE(q1.empty() == 1);
  REQUIRE(q2.empty() == 0);
  REQUIRE(q3.empty() == 0);
}
