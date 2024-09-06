#include "lexer.h"

Lexer lexer(char *text, size_t text_len) {
	Lexer l = {0};
	l.text = text;
	l.text_len = text_len;
	l.start_pos = 0;
	l.current_pos = 0;
	return l;
}

Token get_next_token(Lexer *l) {
	Token t = {0};

	// Boundary check
	if(l->current_pos >= l->text_len) {
		t.token = '\0';
		t.type = eof;
		return t;
	}

	char ct = *(l->text + l->current_pos);
	t.token = ct;
	l->current_pos += 1;

	if ((ct >= 48 && ct <= 57) || (ct >= 65 && ct <= 90) || (ct >= 97 && ct <= 122)) {
		t.type = alphanumeric;  
	} else if (ct >= 8 && ct <= 13) {
		t.type = escape_sequence;
	} else {
		t.type = symbol;
	}

	return t;
}
