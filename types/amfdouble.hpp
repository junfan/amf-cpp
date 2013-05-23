#pragma once
#ifndef AMFDOUBLE_HPP
#define AMFDOUBLE_HPP

#include "amfitem.hpp"

class AmfDouble : public AmfItem {
public:
	// TODO: range check somewhere
	AmfDouble(double v) : value(v) { };
	operator double() const { return value; }

	std::vector<u8> serialize() const {
		u8 v[] = { AMF_DOUBLE };
		v8 buf = make_vector(v);

		double netvalue = hton(value);
		const u8* bytes = reinterpret_cast<const u8*>(&netvalue);
		buf.insert(buf.end(), bytes, bytes + sizeof(double));
		return buf;
	}

private:
	double value;
};

#endif
