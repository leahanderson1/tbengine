# tool macros
CC ?= gcc
AR ?= ar
CFLAGS := -Wall -Wextra -Werror -I./include
DBGFLAGS := -g
COBJFLAGS := $(CFLAGS) -c
TESTFLAGS := -L./lib -ltbengine
# path macros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
DBG_PATH := debug
TST_PATH := demo
LIB_PATH := lib

# compile macros
TARGET_NAME := tbengine
TEST_NAME := tbtest
LIB_STATIC = lib$(TARGET_NAME).a
ifeq ($(OS),Windows_NT)
	TEST_NAME := $(addsuffix .exe,$(TEST_NAME))
endif
TARGET := $(LIB_PATH)/$(LIB_STATIC)
TARGET_DEBUG := $(DBG_PATH)/$(LIB_STATIC)
TARGET_TEST := $(BIN_PATH)/$(TEST_NAME)
# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DBG_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
SRC_TEST := $(foreach x, $(TST_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ_TEST := $(addprefix $(BIN_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC_TEST)))))
# clean files list
DISTCLEAN_LIST := $(OBJ) \
                  $(OBJ_DEBUG) \
		  $(OBJ_TEST)
CLEAN_LIST := $(TARGET) \
			  $(TARGET_DEBUG) \
			  $(TARGET_TEST) \
			  $(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(AR) rcs $@ $^
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(COBJFLAGS) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(COBJFLAGS) $(DBGFLAGS) -o $@ $<
$(BIN_PATH)/%.o: $(TST_PATH)/%.c*
	$(CC) $(COBJFLAGS) -o $@ $<
$(TARGET_DEBUG): $(OBJ_DEBUG)
	$(AR) rcs $@ $^
$(TARGET_TEST): $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) $(TESTFLAGS) -o $@
# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH) $(DBG_PATH) $(TST_PATH) $(LIB_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)
test: $(TARGET) $(TARGET_TEST)
.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
