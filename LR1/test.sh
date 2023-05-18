#!/bin/sh

if [ -n "$(echo $(./LR1) | grep "I992, Skrilnikov I.A.")" ]; then
	echo "Test was passed"
	exit 0
else
	echo "Test wasn't passed"
	exit 1
fi
