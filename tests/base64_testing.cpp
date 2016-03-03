#include "1_base64.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(base64_test) {
	char const hex1[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f"
	                    "7573206d757368726f6f6d",
	           hex2[] = "af321ba21dddae",
	           hex3[] = "af321ba21d",
	           hex4[] = "706f73747365636f6e64617279",
	           hex5[] = "48656c6c6f2c20576f726c64";

	char result[128];

	hexToBase64(result, hex1);
	BOOST_CHECK_EQUAL(result, "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
	hexToBase64(result, hex2);
	BOOST_CHECK_EQUAL(result, "rzIboh3drg==");
	hexToBase64(result, hex3);
	BOOST_CHECK_EQUAL(result, "rzIboh0=");
	hexToBase64(result, hex4);
	BOOST_CHECK_EQUAL(result, "cG9zdHNlY29uZGFyeQ==");
	hexToBase64(result, hex5);
	BOOST_CHECK_EQUAL(result, "SGVsbG8sIFdvcmxk");
}
