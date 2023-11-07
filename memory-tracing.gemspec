# -*- encoding: utf-8 -*-
Gem::Specification.new do |s|
  s.name        = "memory-tracing"
  s.version     = "1.0.0"
  s.authors     = ["Maisha Engineers"]
  s.license     = "MIT"
  s.summary     = "Counter for Ruby memory allocations"

  s.files         = ["lib/memory_tracing.rb"]
  s.require_paths = ["lib"]
  s.extensions    = ["ext/memory_allocations/extconf.rb"]

  s.required_ruby_version = '>= 3.0'

  s.add_development_dependency "rake-compiler"
end
