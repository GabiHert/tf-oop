run: compile
	@echo - RUN STARTED
	./run.exe

compile:
	@echo - COMPILE STARTED
	g++ src/main.cpp  src/domain/model/address-model.hpp src/domain/model/company-model.hpp src/domain/model/discount-model.hpp src/domain/model/product-model.hpp src/domain/dto/address-dto.hpp src/domain/dto/company-dto.hpp src/domain/dto/discount-dto.hpp src/domain/dto/product-dto.hpp  src/domain/discount/combined-discount.hpp src/domain/discount/simple-discount.hpp src/domain/discount/take-m-pay-n-discount.hpp -o run.exe