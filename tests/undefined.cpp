#include "gtest/gtest.h"

#include "amf.hpp"
#include "types/amfundefined.hpp"

TEST(UndefinedSerializationTest, SimpleValue) {
	u8 expected[] = { 0x00 };
	ASSERT_EQ(make_vector(expected), AmfUndefined().serialize());
}

