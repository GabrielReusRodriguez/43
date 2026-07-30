#!/bin/sh

find -d . -print | wc -l | sed 's/ //g'
