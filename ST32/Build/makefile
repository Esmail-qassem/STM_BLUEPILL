include makeconfig
all : Bin

Bin:Linker
	$(BIN) -O binary $(Images)/app.elf  $(Images)/app.bin
	$(BIN) -O ihex $(Images)/app.elf $(Images)/app.hex


Linker: Obj
	$(LD) -Map $(Images)/application.map -T $(LinkerDir)/LinkerScript.ld $(wildcard $(OBJDIR)/*.o) -o $(Images)/app.elf

Obj:
	$(CC) -c $(CFLAG) ../src/main.c -o $(OBJDIR)/main.o
	$(CC) -c $(CFLAG) ../Startup/startup_stm32f103.c -o $(OBJDIR)/startup_stm32f103.o
	$(CC) -c $(CFLAG) $(MCAL)/AFIO/src/AFIO_program.c -o $(OBJDIR)/AFIO_program.o
	$(CC) -c $(CFLAG) $(MCAL)/EXTI/src/EXTI_program.c -o $(OBJDIR)/EXTI_program.o
	$(CC) -c $(CFLAG) $(MCAL)/GPIO/src/GPIO_program.c -o $(OBJDIR)/GPIO_program.o
	$(CC) -c $(CFLAG) $(MCAL)/NVIC/src/NVIC_program.c -o $(OBJDIR)/NVIC_program.o
	$(CC) -c $(CFLAG) $(MCAL)/RCC/src/RCC_program.c -o $(OBJDIR)/RCC_program.o
	$(CC) -c $(CFLAG) $(MCAL)/SPI/src/SPI_program.c -o $(OBJDIR)/SPI_program.o
	$(CC) -c $(CFLAG) $(MCAL)/SysTick/src/SysTick_program.c -o $(OBJDIR)/SysTick_program.o
	$(CC) -c $(CFLAG) $(MCAL)/UART/src/UART_program.c  -o $(OBJDIR)/UART_program.o
	
clean:
	@rm -f $(OBJDIR)/*.o
	@rm -f $(Images)/*.elf
	@rm -f $(Images)/*.map
	@rm -f $(Images)/*.bin
	@echo "Clean done in `date`" > log.txt

flash :Bin
	$(STL) write $(Images)/app.bin 0x08000000

erase :
	$(STL) erase