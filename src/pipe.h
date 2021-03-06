#ifndef PIPE_H_
#define PIPE_H_

#include <stddef.h>
#include <stdbool.h>
#include "err.h"

struct canvas;

//States and transition characters
extern char states[][2];

// Maximum number of bytes per character
#define MAX_CHAR_BYTES 10

/** 2 continuation chars, 4 transition chars, 6 delimiting nuls.  Entries in
 * the transition matrix and list of continuation chars point to chars in this
 * buffer, which will contain multiple \0s.
 */
#define CHAR_BUF_SZ (6 * MAX_CHAR_BYTES + 6)

//Represents a pipe
struct pipe {
    unsigned char state;
    unsigned int color;
    unsigned short length;
    int x, y;
    struct location_buffer *locations;
};

enum DIRECTIONS {
    CPIPES_RIGHT = 0,
    CPIPES_DOWN = 1,
    CPIPES_LEFT = 2,
    CPIPES_UP = 3
};
struct palette;

cpipes_errno init_pipe(struct pipe *pipe, struct canvas *canvas,
        int initial_state, unsigned int max_len);
void free_pipe(struct pipe *pipe);
void move_pipe(struct pipe *pipe, struct canvas *canvas);
bool wrap_pipe(struct pipe *pipe, struct canvas *canvas);
void erase_pipe_tail(struct pipe *pipe, struct canvas *canvas);
char flip_pipe_state(struct pipe *pipe);
void random_pipe_color(struct pipe *pipe, struct palette *palette);
bool should_flip_state(struct pipe *p, int min_len, float prob);
char pipe_char(struct pipe *p, char old_state);

const char * transition_char(char **list, int row, int col);

cpipes_errno locale_to_utf8(char *locale_bytes, char *utf8_bytes,
        const char *from_charset, size_t buflen);
cpipes_errno utf8_to_locale(
        char *utf8_chars,
        char *out_chars, size_t buflen,
        const char *to_charset, size_t *num_chars);
void assign_matrices(char *pipe_chars,
        char **transition, char **continuation);
cpipes_errno multicolumn_adjust(char **continuation);

#endif //PIPE_H_
