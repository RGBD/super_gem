# frozen_string_literal: true

require 'super_gem/version'
require 'super_gem/super_gem'

module SuperGem
  class Error < StandardError; end

  class HelloWorld
    def count_ascii_chars_ruby(string)
      string.each_char.each_with_object(Hash.new(0)) { |x, acc| acc[x] += 1 }
    end

    def count_ascii_chars_ruby_same(string)
      counts = Array.new(0x100, 0)
      string.each_byte { |c| counts[c] += 1 }
      result = {}
      (0...0x100).each do |c|
        next if counts[c].zero?

        result[c.chr] = counts[c]
      end
      result
    end
  end
end
