// This is an adapted snippet from the code of the proc-wait3 gem:
// https://github.com/djberg96/proc-wait3

#include <ruby/ruby.h>
#include <sys/resource.h>

static VALUE
rusage_get(int argc, VALUE* argv, VALUE mod){
  struct rusage r;
  int ret;

  ret = getrusage(RUSAGE_SELF, &r);
  if(ret == -1)
    rb_sys_fail("getrusage");

  return LONG2NUM(r.ru_maxrss);
}

void
Init_memory_usage(){
  VALUE mAllocations = rb_define_module("MemoryTracing");
  rb_define_module_function(mAllocations, "get_usage", rusage_get, -1);
}
