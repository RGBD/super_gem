# frozen_string_literal: true

require 'bundler/gem_tasks'
require 'rake/extensiontask'
require 'rake/testtask'
task default: :spec

spec = Gem::Specification.load('super_gem.gemspec')
Rake::ExtensionTask.new('super_gem', spec) do |ext|
  ext.lib_dir = 'lib/super_gem'
end

Gem::PackageTask.new(spec) do |pkg|
end

Rake::TestTask.new do |t|
  t.libs << 'spec'
  t.test_files = FileList['spec/**/*_spec.rb']
end
