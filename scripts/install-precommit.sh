#! /usr/bin/bash

pip install pre-commit
pip install cpplint
sudo apt-get install clang
sudo apt-get install clang-tidy
sudo apt-get install cppcheck
pre-commit install


pre-commit --version
