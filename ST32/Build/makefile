include makeconfig

# Define the source directories
SRC_DIRS = ../Src/\
           ../Startup/\
           $(MCAL)/RCC/src/ \
           $(MCAL)/NVIC/src/\
           $(MCAL)/SysTick/src/\
           $(MCAL)/GPIO/src/ \
           $(MCAL)/EXTI/src/\
           $(MCAL)/AFIO/src/\
           $(MCAL)/SPI/src/\
           $(MCAL)/UART/src/

# Define the include directories
INC_DIRS = ../Inc/\
           $(MCAL)/RCC/inc/ \
           $(MCAL)/NVIC/inc/\
           $(MCAL)/SysTick/inc/\
           $(MCAL)/GPIO/inc/ \
           $(MCAL)/EXTI/inc/\
           $(MCAL)/AFIO/inc/\
           $(MCAL)/SPI/inc/\
           $(MCAL)/UART/inc/

# Add include directories to CFLAG
INC_FLAGS = $(foreach dir, $(INC_DIRS), -I$(dir))

# Find all source files
SRC_FILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# Define the object files
OBJ_FILES = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC_FILES)))

# Define the dependency files
DEP_FILES = $(patsubst %.c, $(OBJDIR)/%.d, $(notdir $(SRC_FILES)))

# Search for source files in the specified directories
vpath %.c $(SRC_DIRS)

# ANSI color codes for green background
COLOR_GREEN_BG=\033[42m
COLOR_Blue_BG=\033[94m
COLOR_purble=\033[45m
COLOR_RESET=\033[0m

all: Bin

Bin: Linker
	@$(BIN) -O binary $(Images)/app.elf $(Images)/app.bin
	@$(BIN) -O ihex $(Images)/app.elf $(Images)/app.hex
	@$(SIZE) $(Images)/app.elf
	$(eval FLASH_SIZE = $(shell $(SIZE) -A $(Images)/app.elf | awk '$$1 == ".text" {text = $$2} $$1 == ".data" {data = $$2} END {print text + data}'))
	$(eval RAM_SIZE = $(shell $(SIZE) -A $(Images)/app.elf | awk '$$1 == ".data" {data = $$2} $$1 == ".bss" {bss = $$2} END {print data + bss}'))
	@echo -e "$(COLOR_purble)++ Flash size: $(FLASH_SIZE) bytes$(COLOR_RESET)"
	@echo -e "$(COLOR_purble)++ RAM size: $(RAM_SIZE) bytes$(COLOR_RESET)"
	@echo -e "$(COLOR_purble)++ Binary and hex generation completed$(COLOR_RESET)"

Linker: $(OBJ_FILES) $(LinkerDir)/LinkerScript.ld  # Add dependency on linker script
	@$(LD) -Map $(Images)/application.map -T $(LinkerDir)/LinkerScript.ld $(OBJ_FILES) -o $(Images)/app.elf
	@echo -e "$(COLOR_Blue_BG)++ Linking completed$(COLOR_RESET)"

# Rule to compile source files to object files
$(OBJDIR)/%.o: %.c
	@$(CC) -c $(CFLAG) $(INC_FLAGS) -MMD -MF $(OBJDIR)/$*.d $< -o $@
	@mkdir -p $(OBJDIR)
	@file_name=$(notdir $<); \
	if [ "$$file_name" = "uart.c" ]; then \
		echo -e "$(COLOR_GREEN_BG)++$(COLOR_RESET) uart"; \
	else \
		echo -e "$(COLOR_GREEN_BG)++$(COLOR_RESET) Compiling $$file_name"; \
	fi

clean:
	@rm -f $(OBJDIR)/*.o
	@rm -f $(OBJDIR)/*.d
	@rm -f $(Images)/*.elf
	@rm -f $(Images)/*.map
	@rm -f $(Images)/*.bin
	@rm -f $(Images)/*.hex
	@echo -e "$(COLOR_GREEN_BG)++ Clean done$(COLOR_RESET)"

flash: Bin
	@$(STL) -c port=swd -d $(Images)/app.bin 0x08000000 -v -rst

erase:
	@$(STL) -c port=swd -e all

# Include the dependency files
-include $(DEP_FILES)
