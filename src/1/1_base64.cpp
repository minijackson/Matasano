#include "1_base64.hpp"

#include <cstring>
#include <stdexcept>

namespace {
	constexpr size_t const HEX_MAX_LENGTH = 2048ul;

	constexpr char const BASE64_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	                                         "abcdefghijklmnopqrstuvwxyz"
	                                         "0123456789+/";

	inline size_t hexValue(char const c) {
		if('0' <= c && c <= '9') {
			return c - '0';
		}

		if('A' <= c && c <= 'F') {
			return c - 'A' + 10;
		}

		if('a' <= c && c <= 'f') {
			return c - 'a' + 10;
		}

		using namespace std::literals::string_literals;
		throw std::invalid_argument("Invalid character in hexadecimal string: "s + c);
	}

	char base64char(size_t const value) {
		if(value <= 63) {
			return BASE64_ALPHABET[value];
		}

		using namespace std::literals::string_literals;
		throw std::invalid_argument("Invalid value passed to base64char: "s +
		                            std::to_string(value));
	}

	void threeLenStrToBase64(char* result, char const c1, char const c2, char const c3) {
		size_t value = hexValue(c3) + (hexValue(c2) << 4) + (hexValue(c1) << 8);

		size_t r2 = value >> 6;
		size_t r1 = value & 0b000000'111111;

		result[0] = base64char(r2);
		result[1] = base64char(r1);
	}
}

void hexToBase64(char* result, char const* hex) {
	if(std::strlen(hex) > HEX_MAX_LENGTH) {
		throw std::length_error("String too long");
	}

	size_t len           = std::strlen(hex);
	size_t bytesToRemain = (len / 2) % 3;

	char* resultIt    = result;
	char const* hexIt = hex;
	for(size_t i = 0; i < (len / 3); ++i) {
		threeLenStrToBase64(resultIt, hexIt[0], hexIt[1], hexIt[2]);
		resultIt += 2;
		hexIt += 3;
	}

	size_t remainder = len % 3;
	if(remainder == 2) {
		threeLenStrToBase64(resultIt, hexIt[0], hexIt[1], '0');
		resultIt += 2;
	} else if(remainder == 1) {
		threeLenStrToBase64(resultIt, hexIt[0], '0', '0');
		resultIt += 2;
	}

	if(bytesToRemain == 2) {
		resultIt[0] = '=';
		++resultIt;
	} else if(bytesToRemain == 1) {
		resultIt[0] = '=';
		resultIt[1] = '=';
		resultIt += 2;
	}

	resultIt[0] = '\0';
}
