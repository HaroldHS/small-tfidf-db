#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "lexer-test.h"
#include "../main/helper/lexer.h"

void test_token_types() {
	char *input = "a1[\r\0";
	size_t input_length = strlen(input);
	Lexer l = lexer(input, input_length);

	assert(alphanumeric == get_next_token(&l).type);
	assert(alphanumeric == get_next_token(&l).type);
	assert(symbol == get_next_token(&l).type);
	assert(escape_sequence == get_next_token(&l).type);
	assert(eof == get_next_token(&l).type);
}
