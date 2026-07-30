#!/bin/sh

ifconfig  | grep ether | grep  -o -i -E '[0-9a-f]{2}(:[0-9a-f]{2}){5}'
