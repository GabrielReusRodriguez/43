#!/bin/sh

find -d ./ -name "*.sh" | xargs basename -s ".sh"
