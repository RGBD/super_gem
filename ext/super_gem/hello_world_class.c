#include <stdio.h>
#include <string.h>

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
  rb_define_method(HelloWorldClass, "fib", rb_hello_world_fib, 1);
  rb_define_method(HelloWorldClass, "count_ascii_chars", rb_hello_world_count_ascii_chars, 1);
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

VALUE rb_hello_world_fib(VALUE _self, VALUE k) {
  unsigned long long a = 0;
  unsigned long long b = 1;
  unsigned long long kk = NUM2ULL(k);
  for (unsigned long long i = 0; i < kk; i++) {
    b = a + b;
    a = b - a;
  }
  return ULL2NUM(a);
}

VALUE rb_hello_world_count_ascii_chars(VALUE _self, VALUE ruby_string) {
  unsigned long long string_length = RSTRING_LEN(ruby_string);
  unsigned char *string = (unsigned char *) RSTRING_PTR(ruby_string);
  unsigned long long counts[0x100];
  VALUE result = rb_hash_new();
  unsigned char c = 0;

  memset(counts, 0, sizeof(counts));
  for (unsigned long long i = 0; i < string_length; i++) {
    counts[string[i]] += 1;
  }

  do {
    if (!counts[c]) {
      c++;
      continue;
    }
    rb_hash_aset(result, rb_str_new((char *)&c, 1), ULL2NUM(counts[c]));
    c++;
  } while (c != 0);

  return result;
}
