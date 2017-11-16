C_COMPILER=gcc
C_FILES=main.c calc.c handle.c
H_FILES=calc.h handle.h
TARGET=MCalc
TARGET_RM=MCalc.exe

run: $(C_FILES) $(H_FILES)
	$(C_COMPILER) $(C_FILES) -o $(TARGET)
	$(TARGET)

clean:
	-del -f $(TARGET_RM)
