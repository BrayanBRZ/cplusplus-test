CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O0 -g
BUILD_DIR := build
EXAMPLE ?= 00-raiz

EXAMPLES := \
	00-raiz \
	01-fundamentos \
	02-headers \
	03-referencias-ponteiros \
	04-raii-smart-pointers \
	05-classes \
	06-copy-move \
	07-polimorfismo \
	08-templates-stl

.PHONY: all list run clean

all: $(addprefix $(BUILD_DIR)/,$(EXAMPLES))

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/00-raiz: main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/01-fundamentos: examples/01-fundamentos/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/02-headers: examples/02-headers/src/main.cpp examples/02-headers/src/math_tools.cpp examples/02-headers/include/math_tools.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Iexamples/02-headers/include examples/02-headers/src/main.cpp examples/02-headers/src/math_tools.cpp -o $@

$(BUILD_DIR)/03-referencias-ponteiros: examples/03-referencias-ponteiros/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/04-raii-smart-pointers: examples/04-raii-smart-pointers/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/05-classes: examples/05-classes/src/main.cpp examples/05-classes/src/BankAccount.cpp examples/05-classes/include/BankAccount.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Iexamples/05-classes/include examples/05-classes/src/main.cpp examples/05-classes/src/BankAccount.cpp -o $@

$(BUILD_DIR)/06-copy-move: examples/06-copy-move/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/07-polimorfismo: examples/07-polimorfismo/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/08-templates-stl: examples/08-templates-stl/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

list:
	@printf "Exemplos disponiveis:\n"
	@printf "  %s\n" $(EXAMPLES)

run: $(BUILD_DIR)/$(EXAMPLE)
	./$(BUILD_DIR)/$(EXAMPLE)

clean:
	rm -rf $(BUILD_DIR)
