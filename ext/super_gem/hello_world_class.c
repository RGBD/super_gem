#include "./hello_world_class.h"

VALUE HelloWorldClass = Qnil;
extern VALUE SuperGemModule;

void rb_init_hello_world_class() {
  HelloWorldClass = rb_define_class_under(SuperGemModule, "HelloWorld", rb_cObject);
  rb_define_method(HelloWorldClass, "hello", rb_hello_world_hello, 0);
  rb_define_method(HelloWorldClass, "nil", rb_hello_world_nil, 0);
  rb_define_method(HelloWorldClass, "true", rb_hello_world_true, 0);
  rb_define_method(HelloWorldClass, "false", rb_hello_world_false, 0);
  rb_define_method(HelloWorldClass, "forty_two", rb_hello_world_forty_two, 0);
  rb_define_method(HelloWorldClass, "float_half", rb_hello_world_float_half, 0);
  rb_define_method(HelloWorldClass, "hello_format", rb_hello_world_hello_format, 2);
}

VALUE rb_hello_world_hello(VALUE self) {
  return rb_str_new2("Hello, world!");
}

VALUE rb_hello_world_nil(VALUE self) { return Qnil; }
VALUE rb_hello_world_false(VALUE self) { return Qfalse; }
VALUE rb_hello_world_true(VALUE self) { return Qtrue; }
VALUE rb_hello_world_forty_two(VALUE self) { return LONG2FIX(42); }
VALUE rb_hello_world_float_half(VALUE self) { return DBL2NUM(0.5); }

VALUE rb_hello_world_hello_format(VALUE self, VALUE name, VALUE number) {
  return rb_sprintf("Hello, %"PRIsVALUE". Number: %+"PRIsVALUE".", name, number);
}
