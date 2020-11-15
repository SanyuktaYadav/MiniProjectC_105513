#include "unity.h"

void setUp()
{	}

void tearDown()
{	}

void test_file(void)
{
  	TEST_ASSERT_NOT_EQUAL(-1, fopen("c_file.csv", "r"));
	TEST_ASSERT_NOT_EQUAL(-1, fopen("cpp_file.csv", "r"));
	TEST_ASSERT_NOT_EQUAL(-1, fopen("python_file.csv", "r"));
	TEST_ASSERT_NOT_EQUAL(-1, fopen("sql_file.csv", "r"));
}

int test_main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_file);

	return UNITY_END();
}
