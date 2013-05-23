#pragma once
#ifndef AMFNULL_HPP
#define AMFNULL_HPP

#include <vector>
#include "amfitem.hpp"

class AmfNull : public AmfItem {
public:
	AmfNull() { }

	std::vector<u8> serialize() const {
		return v8(1, AMF_NULL);
	}
};

#endif
