#include "ruby.h"
#include "./hello_world_class.h"

VALUE SuperGemModule = Qnil;

void Init_super_gem() {
  SuperGemModule = rb_define_module("SuperGem");
  rb_init_hello_world_class();
}
