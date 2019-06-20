# frozen_string_literal: true

require 'benchmark/ips'
require 'super_gem'

instance = SuperGem::HelloWorld.new

ss = 'a'

long_string = Array.new(1_000_000) { |i| (i % 256).chr }.join.force_encoding('BINARY')

configs = [
  { ss: long_string.slice(0, 1e0.to_i) },
  { ss: long_string.slice(0, 1e1.to_i) },
  { ss: long_string.slice(0, 1e2.to_i) },
  { ss: long_string.slice(0, 1e3.to_i) },
  { ss: long_string.slice(0, 1e4.to_i) },
  { ss: long_string.slice(0, 1e5.to_i) },
]

configs.each do |config|
  ss = config[:ss]

  puts " #{ss.size} ".center(80, '*')

  Benchmark.ips do |bm|
    bm.report('c99') { instance.count_ascii_chars(ss) }
    bm.report('ruby') { instance.count_ascii_chars_ruby(ss) }
    bm.report('ruby_same') { instance.count_ascii_chars_ruby_same(ss) }

    bm.compare!
  end
end
