#include "gtest/gtest.h"

#include "amf.hpp"
#include "types/amfnull.hpp"

TEST(NullSerializationTest, SimpleValue) {
	u8 expected[] = { 0x01 };
	ASSERT_EQ(make_vector(expected), AmfNull().serialize());
}
