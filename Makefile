all: 
	$(MAKE) --directory=src

test:
	$(MAKE) --directory=test

.PHONY: clean
clean:
	$(MAKE) --directory=src clean
	$(MAKE) --directory=test clean
