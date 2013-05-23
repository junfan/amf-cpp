#include "gtest/gtest.h"

#include "amf.hpp"
#include "types/amfbool.hpp"

template <size_t N>
static void isEqual(u8 (&expected)[N], bool value) {
	ASSERT_EQ(make_vector(expected), AmfBool(value).serialize());
}

TEST(BoolSerializationTest, SimpleValues) {
	u8 v1[] = { 0x02 };
	isEqual(v1, false);
	u8 v2[] = { 0x03 };
	isEqual(v2, true);
}
