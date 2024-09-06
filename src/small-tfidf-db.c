#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "main/helper/lexer.h"
#include "test/lexer-test.h"

void test();
void test() {
	test_token_types();
}

int main(int argc, char *argv[], char *envp[]) {

	if(argc >= 2 && strcmp(argv[1], "test") == 0) {
		test();
		return 0;
	}

	return 0;
}
