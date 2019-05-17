#include "./hello_world_class.h"

VALUE HelloWorldClass = Qnil;
extern VALUE SuperGemModule;

void rb_init_hello_world_class() {
  HelloWorldClass = rb_define_class_under(SuperGemModule, "HelloWorld", rb_cObject);
  rb_define_method(HelloWorldClass, "hello", rb_hello_world_hello, 0);
}

VALUE rb_hello_world_hello(VALUE self) {
  return rb_str_new2("Hello, world!");
}
