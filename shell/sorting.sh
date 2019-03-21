#!/bin/sh

patch_size=10
upper_range=100

while [ "$choice" = "" ] || [ "$choice" != "Q" ]; do
	echo "Input Your Choice:
		Q) Quit
		1) Generate random numbers 
		2) Show patch size 
		3) Show range
		4) Display random numbers
		A) Set patch size
		B) Set range
		C) Do sorting
	"
	read choice

	case "$choice" in
		Q) echo "Quit";;
		1) echo "Generating random numbers..."
		   shuf -i 1-$upper_range -n $patch_size > numbers.txt
		   echo "done";;
		2) echo "Patch size: $patch_size";;
		3) echo "Range 1-$upper_range";;
		4) echo "Numbers:"
		   cat numbers.txt;;
		A) echo "Input new patch size:"; read patch_size;;
		B) echo "Input new upper range:"; read upper_range;;
		C) echo "Sorting..."; sort -n numbers.txt > sorted.txt; echo "done";;
		*) echo "unknow choice:$choice";;
	esac

	echo ""
done

exit 0
