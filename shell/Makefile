
.PHONY: clean test

test: inputs.txt
	./sorting.sh < inputs.txt > result.txt
	./result_parsing.sh

clean:
	rm -f result.txt sorted.txt check.txt
