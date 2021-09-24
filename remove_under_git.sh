#!/bin/bash

# print under git directory name
find . -mindepth 2 -name '.git'

# remove under git directories
find . -mindepth 2 -name '.git' -prune -exec rm -rf {} +

