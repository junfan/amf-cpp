#include "gtest/gtest.h"

#include "amf.hpp"
#include "serializer.hpp"
#include "types/amfdouble.hpp"

static void isEqual(const std::vector<u8>& expected, double value) {
	ASSERT_EQ(expected, AmfDouble(value).serialize());
}

TEST(DoubleSerializationTest, SimpleValues) {
	isEqual(v8 { 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 0);
	isEqual(v8 { 0x05, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 0.5);
	isEqual(v8 { 0x05, 0xBF, 0xF3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33 }, -1.2);
	isEqual(v8 { 0x05, 0x3F, 0xD5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55 }, 0.3333333333333333);
	isEqual(v8 { 0x05, 0xBF, 0xD5, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55 }, -0.3333333333333333);
	isEqual(v8 { 0x05, 0x4A, 0x9A, 0xBA, 0x47, 0x14, 0x95, 0x7D, 0x30 }, 2.5e+51);
	isEqual(v8 { 0x05, 0xCA, 0x9A, 0xBA, 0x47, 0x14, 0x95, 0x7D, 0x30 }, -2.5e+51);
	isEqual(v8 { 0x05, 0x47, 0x37, 0xC6, 0xE3, 0xC0, 0x32, 0xF7, 0x20 }, 1.2345678912345e+35);
	isEqual(v8 { 0x05, 0xC7, 0x37, 0xC6, 0xE3, 0xC0, 0x32, 0xF7, 0x20 }, -1.2345678912345e+35);
	isEqual(v8 { 0x05, 0x42, 0x06, 0xFE, 0xE0, 0xE1, 0xA0, 0x00, 0x00 }, 12345678900);
	isEqual(v8 { 0x05, 0x3D, 0xE0, 0xF7, 0xBF, 0xE5, 0xDB, 0x09, 0xEB }, 1.23456789e-10);
	isEqual(v8 { 0x05, 0xC2, 0x06, 0xFE, 0xE0, 0xE1, 0xA0, 0x00, 0x00 }, -12345678900);
	isEqual(v8 { 0x05, 0xBD, 0xE0, 0xF7, 0xBF, 0xE5, 0xDB, 0x09, 0xEB }, -1.23456789e-10);
	isEqual(v8 { 0x05, 0x3F, 0xEA, 0x2E, 0x8B, 0xA2, 0xE8, 0xBA, 0x2F }, 0.8181818181818182);
	isEqual(v8 { 0x05, 0x3F, 0xF3, 0x8E, 0x38, 0xE3, 0x8E, 0x38, 0xE4 }, 1.2222222222222223);
	isEqual(v8 { 0x05, 0x40, 0x09, 0x21, 0xF9, 0xF0, 0x1B, 0x86, 0x6E }, 3.14159);
	isEqual(v8 { 0x05, 0xBF, 0xEA, 0x2E, 0x8B, 0xA2, 0xE8, 0xBA, 0x2F }, -0.8181818181818182);
	isEqual(v8 { 0x05, 0xBF, 0xF3, 0x8E, 0x38, 0xE3, 0x8E, 0x38, 0xE4 }, -1.2222222222222223);
	isEqual(v8 { 0x05, 0xC0, 0x09, 0x21, 0xF9, 0xF0, 0x1B, 0x86, 0x6E }, -3.14159);
}