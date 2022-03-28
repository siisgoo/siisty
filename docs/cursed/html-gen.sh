#!/bin/bash

pandoc -f markdown --standalone $1 -o $2
