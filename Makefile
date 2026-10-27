CC      := gcc
TARGET  := PongGameDemo
BUILD   := build
CLOUDY  := .
# Set "CLOUDY := ." to CLOUDY := Cloudy" once game is made

SRCS := $(wildcard *.c) $(wildcard $(CLOUDY)/*/*.c)
OBJS := $(SRCS:%.c=$(BUILD)/%.o)

CFLAGS  := -std=c99 -Wall -Wextra -Wpedantic -MMD -MP -I. -I$(CLOUDY) \
           -I/usr/local/include/SDL2 -D_GNU_SOURCE=1 -D_REENTRANT
LDFLAGS := -L/usr/local/lib
LDLIBS  := -lSDL2 -lfreetype -lm

# Debug (default): symbols + sanitizers. Release: optimised + static.
ifeq ($(MODE),release)
    CFLAGS  += -O2
    LDFLAGS += -static
else
    SAN     := -g -fsanitize=address,undefined
    CFLAGS  += $(SAN)
    LDFLAGS += $(SAN)
endif

.PHONY: all release clean

all: $(TARGET)

release:
	$(MAKE) clean
	$(MAKE) MODE=release

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET)

-include $(OBJS:.o=.d)
