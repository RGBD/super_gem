# frozen_string_literal: true

require 'spec_helper'

class HelloWorldSpec < Minitest::Test
  attr_reader :instance

  def setup
    @instance = SuperGem::HelloWorld.new
  end

  def test_hello
    assert_equal 'Hello, world!', instance.hello
  end

  def test_nil
    assert_nil instance.nil
  end

  def test_true
    assert_equal true, instance.true
  end

  def test_false
    assert_equal false, instance.false
  end

  def test_forty_two
    assert_equal 42, instance.forty_two
  end

  def test_float_half
    result = instance.float_half
    assert result.is_a?(Float)
    assert_equal 0.5, result
  end

  def test_hello_format
    assert_equal 'Hello, Petya. Number: 42.', instance.hello_format('Petya', 42)
  end
end
