#include "ruby.h"

void rb_init_hello_world_class();
VALUE rb_hello_world_hello(VALUE self);
VALUE rb_hello_world_nil(VALUE self);
VALUE rb_hello_world_false(VALUE self);
VALUE rb_hello_world_true(VALUE self);
VALUE rb_hello_world_forty_two(VALUE self);
VALUE rb_hello_world_float_half(VALUE self);
VALUE rb_hello_world_hello_format(VALUE self, VALUE name, VALUE number);
