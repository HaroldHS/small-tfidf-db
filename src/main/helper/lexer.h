#pragma once

#include <stddef.h>

typedef enum {
	eof = 0,
	alphanumeric,
	symbol,
	escape_sequence,
} Token_Type;

typedef struct {
	Token_Type type;
	char token;
} Token;

typedef struct {
	char *text;
	size_t text_len;
	size_t start_pos;
	size_t current_pos;
} Lexer;

Lexer lexer(char *text, size_t text_len);
Token get_next_token(Lexer *l);
