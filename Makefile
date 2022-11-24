
CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=  src/main.cpp src/sell-amount.cpp src/address-model.cpp  src/buy-request-model.cpp  src/company-model.cpp  src/discount-model.cpp  src/product-model.cpp  src/address-dto.cpp  src/buy-request-dto.cpp  src/company-dto.cpp  src/discount-dto.cpp  src/product-dto.cpp  src/combined-discount.cpp  src/simple-discount.cpp  src/take-m-pay-n-discount.cpp  src/discount-factory.cpp  src/buy-register.cpp  src/invoice.cpp  src/apply-discount-use-case.cpp  src/register-buy-use-case.cpp  src/invoice-emitter-controller.cpp  src/invoice-emitter-csv-handler.cpp src/utils.cpp


EXECUTABLE	:= main

dev: build 
	./run.exe

build:
	g++ $(LIBRARIES) -o run.exe


all: $(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(EXECUTABLE): $( )/**/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(EXECUTABLE)


localTest: buildLocalTest
	./localTest.exe

buildLocalTest:
	g++ localTest.cpp -o localTest.exe
