#include "./hello_world_class.h"

VALUE HelloWorldClass = Qnil;
extern VALUE SuperGemModule;

void rb_init_hello_world_class() {
  HelloWorldClass = rb_define_class_under(SuperGemModule, "HelloWorld", rb_cObject);
  rb_define_method(HelloWorldClass, "hello", rb_hello_world_hello, 0);
  rb_define_method(HelloWorldClass, "nil", rb_hello_world_nil, 0);
  rb_define_method(HelloWorldClass, "true", rb_hello_world_true, 0);
  rb_define_method(HelloWorldClass, "false", rb_hello_world_false, 0);
}

VALUE rb_hello_world_hello(VALUE self) {
  return rb_str_new2("Hello, world!");
}

VALUE rb_hello_world_nil(VALUE self) { return Qnil; }
VALUE rb_hello_world_false(VALUE self) { return Qfalse; }
VALUE rb_hello_world_true(VALUE self) { return Qtrue; }
