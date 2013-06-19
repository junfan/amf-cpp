#include "amftest.hpp"

#include "amf.hpp"
#include "types/amfundefined.hpp"

TEST(UndefinedSerializationTest, SimpleValue) {
	ASSERT_EQ(v8 { 0x00 }, AmfUndefined().serialize());
}

