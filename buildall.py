#!/usr/bin/env python3
import subprocess
import argparse
import os

tests = ['./bin/CppUTestTests',
         './bin/CppUTestExtTests',
         './bin/tfmtests',
         ]

def get_arguments():
    parser = argparse.ArgumentParser(description='Build FlyingSquirrel')
    parser.add_argument('--output', '-o', dest='format', default='normal',
                        choices=['normal','junit'], help='Output format from tests')
    parser.add_argument('-j', dest='N', type=int, default=1,
                        help='Number of threads sent to make')
    parser.add_argument('--c-compiler', dest='c_compiler', default='clang',
                        help='Default C compiler')
    parser.add_argument('--cxx-compiler', dest='cxx_compiler', default='clang++',
                        help='Default CXX compiler')
    parser.add_argument('--build-dir', '-d', dest='build_dir', default='_build_',
                        help='Build output directory')
    return parser.parse_args()

def programInPath(program):
    def is_executable(path):
        return os.path.isfile(path) and os.access(path, os.X_OK)

    path, name = os.path.split(program)
    if path:
        if is_executable(program):
            return True
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            test_file = os.path.join(path,program)
            if is_executable(test_file):
                return True
    return False

def set_environment_variables(args):
    if programInPath(args.c_compiler) and programInPath(args.cxx_compiler):
        os.putenv('CC', args.c_compiler)
        os.putenv('CXX', args.cxx_compiler)

def build_all(args):
    if subprocess.call(['cmake', '..']) == 0:
        return subprocess.call(['make', '-j', str(args.N)]) == 0
    return False

def run_all_tests(args):
    for test in tests:
        print("Running %s" %test)
        subprocess.call([test, '-o', args.format]);

if __name__ == '__main__':
    args = get_arguments()

    if not os.path.isdir(args.build_dir):
        os.makedirs(args.build_dir)
    os.chdir(args.build_dir)

    set_environment_variables(args)
    if build_all(args):
        run_all_tests(args)
