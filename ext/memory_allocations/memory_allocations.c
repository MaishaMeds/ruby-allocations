// This is a lightly adapted version of:
// https://github.com/scoutapp/scout_apm_ruby/blob/master/ext/allocations/allocations.c

#include <ruby/ruby.h>
#include <ruby/debug.h>

static __thread uint64_t endpoint_allocations;

static VALUE
get_allocation_count() {
  return ULL2NUM(endpoint_allocations);
}

static void
tracepoint_handler(VALUE tpval, void *data)
{
    rb_trace_arg_t *tparg = rb_tracearg_from_tracepoint(tpval);
    if (rb_tracearg_event_flag(tparg) == RUBY_INTERNAL_EVENT_NEWOBJ) {
        endpoint_allocations++;
    }
}

static VALUE
set_gc_hook(rb_event_flag_t event)
{
    VALUE tpval;
    tpval = rb_tracepoint_new(0, event, tracepoint_handler, 0);
    rb_tracepoint_enable(tpval);

    return tpval;
}

void
Init_memory_allocations()
{
    VALUE cAllocations = rb_define_class("MemoryTracing", rb_cObject);
    rb_define_singleton_method(cAllocations, "count_allocations", get_allocation_count, 0);
    set_gc_hook(RUBY_INTERNAL_EVENT_NEWOBJ);
}
