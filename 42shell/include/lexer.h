/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser
*/

#ifndef LEXER_H_
    #define LEXER_H_

    #define IS_SEPARATOR(type) (type == TT_SMCL || type == TT_NEWLINE)

    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>


// ? Token types for our parser
typedef enum token_type_s {
    TT_SMCL,            // ? 0: ';'
    TT_NEWLINE,         // ? 1: '\n'
    TT_PIPE,            // ? 2: '|'
    TT_AND,             // ? 3: '&&'
    TT_OR,              // ? 4: '||'
    TT_JOB,             // ? 5: '&'
    TT_REDIRECT_OUT,    // ? 6: '>'
    TT_APPEND,          // ? 7: '>>'
    TT_REDIRECT_IN,     // ? 8: '<'
    TT_HEREDOC,         // ? 9: '<<'
    TT_BACKTICK,        // ? 10: '`'
    TT_RAW_STRING,      // ? 11: "'" [char]* "'"
    TT_LPAREN,          // ? 12: '('
    TT_RPAREN,          // ? 13: ')'
    TT_WORD,            // ? 14: Generic word (e.g., command names)
    TT_ERROR,           // ? 15: Error token
    TT_EOF,             // ? 16: '\0' End of input
    NB_TOKENS           // ? 17: Count of tokens (not an actual token)
} token_type_t;

typedef struct lexer_s {
    const char *start;
    size_t pos;
} lexer_t;

extern const char *tokens_list[NB_TOKENS];

typedef struct token_s {
    token_type_t type;
    const char *value;
    size_t len;
} token_t;

token_t get_next_token(lexer_t *lexer);
token_t make_generic(lexer_t *lexer, token_type_t type, size_t length);
void skip_whitespace(lexer_t *lexer);
bool is_whitespace(char c);
bool is_reserved_char(char c);
char *get_token_value(const token_t *token);

static inline void print_token(const token_t *restrict token)
{
    printf(
        "Token: \"%.*s\"; type: %hhu\n",
        (int)token->len, token->value, token->type
    );
}

#endif
