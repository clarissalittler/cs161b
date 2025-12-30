# Top-level Makefile for CS161B Examples
# Build all examples across all weeks

WEEKS = week00-basics week01-pointers week02-structures week03-functions \
        week04-file-io week05-integration week06-dynamic-memory \
        week07-memory-practice week08-data-structures week09-debugging \
        week10-templates

.PHONY: all clean $(WEEKS) mini-projects help

# Default: build all examples
all: $(WEEKS)

# Build each week by calling its Makefile
$(WEEKS):
	@echo "=== Building $@ ==="
	@$(MAKE) -C $@ --no-print-directory
	@echo ""

# Build all mini-projects
mini-projects:
	@for week in $(WEEKS); do \
		echo "=== Building mini-project in $$week ==="; \
		$(MAKE) -C $$week mini-project --no-print-directory 2>/dev/null || true; \
		echo ""; \
	done

# Clean all weeks
clean:
	@for week in $(WEEKS); do \
		echo "Cleaning $$week..."; \
		$(MAKE) -C $$week clean --no-print-directory 2>/dev/null || true; \
	done
	@echo "All cleaned!"

# Help
help:
	@echo "CS161B Examples Makefile"
	@echo ""
	@echo "Usage:"
	@echo "  make           - Build all examples in all weeks"
	@echo "  make week00-basics  - Build just week 0"
	@echo "  make week05-integration - Build just week 5"
	@echo "  make mini-projects - Build all mini-projects"
	@echo "  make clean     - Remove all compiled programs"
	@echo "  make help      - Show this help"
	@echo ""
	@echo "Available weeks:"
	@echo "  $(WEEKS)" | fmt -w 60
