# frozen_string_literal: true

require 'spec_helper'

class HelloWorldSpec < Minitest::Test
  def test_hello
    assert_equal 'Hello, world!', SuperGem::HelloWorld.new.hello
  end
end
