all: 
	@echo "Building..."
	@$(MAKE) --directory=src

test:
	@echo "Testing..."
	$(MAKE) --directory=test

.PHONY: clean
clean:
	@echo "Cleaning up..."
	$(MAKE) --directory=src clean

.PHONY: realclean
realclean: clean
	$(MAKE) --directory=test clean

