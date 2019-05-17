#include "ruby.h"
#include "stdlib.h"

VALUE SuperGemModule = Qnil;

void Init_super_gem() {
  printf("Init_super_gem()\n");
  SuperGemModule = rb_define_module("SuperGem");
}
