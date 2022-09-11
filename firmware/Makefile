PROGRAMMER := usbtiny
ARCH := avr
MCU := atmega328p
LFUSE := 0b11111111
HFUSE := 0b11010110
EFUSE := 0b11111101

TARGET_EXEC := main.hex

BUILD_DIR := ./build
INC_DIR := ./include
SRC_DIR := ./src

SRCS := $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_FLAGS := \
	-isystem /usr/avr/include -I \
	$(INC_DIR)
C_FLAGS := \
	-Wall \
	-Wno-unknown-attributes \
	--target=$(ARCH) \
	-mmcu=$(MCU) \
	-O \
	-DF_CPU=16000000 \
	-D__AVR_ATmega328P__ \
	-D__DELAY_BACKWARD_COMPATIBLE__ \
	-MMD \
	-MP

# create the hex
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	clang $(C_FLAGS) -o $@ $^

# compile the source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	clang $(INC_FLAGS) $(C_FLAGS) -c $< -o $@

.PHONY: clean fuses

# remove all built files
clean:
	rm -r $(BUILD_DIR)

# burn all fuses
fuses:
	avrdude -c $(PROGRAMMER) -p $(MCU) -v -U lfuse:w:$(LFUSE):m
	avrdude -c $(PROGRAMMER) -p $(MCU) -v -U hfuse:w:$(HFUSE):m
	avrdude -c $(PROGRAMMER) -p $(MCU) -v -U efuse:w:$(EFUSE):m

# burn the hex
burn: $(BUILD_DIR)/$(TARGET_EXEC)
	avrdude -c $(PROGRAMMER) -p $(MCU) -Uflash:w:$<

-include $(DEPS)
