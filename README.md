# Memory Tracing

This gem makes available some helpers for memory tracing.

To build this you need to have ruby and bundler installed.
Then you can run:

```
# Install ruby dependencies
$ bundle

# Compile C-extensions
$ rake compile

# Try running the code
$ bundle exec irb
irb> require "memory_tracing"
irb> MemoryTracing.count_allocations
=> 732745
irb> MemoryTracing.get_usage
=> 198936
```
