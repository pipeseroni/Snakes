bin_PROGRAMS = cpipes

check_PROGRAMS = test_locale test_pipe_cell_list test_canvas test_cbuf
TESTS = test_locale test_pipe_cell_list test_canvas test_cbuf

SOURCES = src/pipe.c src/pipe.h \
		  src/render.c src/render.h \
		  src/util.c src/util.h \
		  src/err.c src/err.h \
		  src/pipe_cell_list.c src/pipe_cell_list.h \
		  src/location_buffer.c src/location_buffer.h \
		  src/canvas.h src/canvas.c

cpipes_SOURCES = src/cpipes.c $(SOURCES)
cpipes_CFLAGS = $(WARN_CFLAGS)
cpipes_LDFLAGS = $(WARN_LDFLAGS)
cpipes_LDADD = $(CURSES_LIBS)
cpipes_CPPFLAGS = $(CURSES_CFLAGS)

noinst_LIBRARIES = libtap.a
libtap_a_SOURCES = tap/tap.c tap/tap.h

test_locale_SOURCES = t/locale.c $(SOURCES)
test_locale_CFLAGS = -I$(srcdir)/src -isystem tap $(WARN_CFLAGS)
test_locale_LDFLAGS = $(WARN_LDFLAGS)
test_locale_LDADD = $(CURSES_LIBS) libtap.a
test_locale_CPPFLAGS = $(CURSES_CFLAGS)

test_pipe_cell_list_SOURCES = t/pipe_cell_list.c $(SOURCES)
test_pipe_cell_list_CFLAGS = -I$(srcdir)/src -isystem tap $(WARN_CFLAGS)
test_pipe_cell_list_LDFLAGS = $(WARN_LDFLAGS)
test_pipe_cell_list_LDADD = $(CURSES_LIBS) libtap.a
test_pipe_cell_list_CPPFLAGS = $(CURSES_CFLAGS)

test_canvas_SOURCES = t/canvas.c $(SOURCES)
test_canvas_CFLAGS = -I$(srcdir)/src -isystem tap $(WARN_CFLAGS)
test_canvas_LDFLAGS = $(WARN_LDFLAGS)
test_canvas_LDADD = $(CURSES_LIBS) libtap.a
test_canvas_CPPFLAGS = $(CURSES_CFLAGS)

test_cbuf_SOURCES = t/test_cbuf.c $(SOURCES)
test_cbuf_CFLAGS = -I$(srcdir)/src -isystem tap $(WARN_CFLAGS)
test_cbuf_LDFLAGS = $(WARN_LDFLAGS)
test_cbuf_LDADD = $(CURSES_LIBS) libtap.a
test_cbuf_CPPFLAGS = $(CURSES_CFLAGS)

EXTRA_DIST = LICENSE README.md
