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
end