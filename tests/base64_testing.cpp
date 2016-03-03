#include "1_base64.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(base64_test) {
	char const hex1[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f"
	                    "7573206d757368726f6f6d",
	           hex2[] = "af321ba21dddae";

	char result[128];

	hexToBase64(result, hex1);
	BOOST_CHECK_EQUAL(result, "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
	hexToBase64(result, hex2);
	BOOST_CHECK_EQUAL(result, "rzIboh3drg==");
}
